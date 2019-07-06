#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <cstring>
#include <algorithm>
#include <libnet.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#define PORT 1337

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == -1) {
        std::cerr << "Server socket error\n";
        exit(EXIT_FAILURE);
    }
    sockaddr_in addr;
    int addrLen = sizeof(addr);
    memset(&addr, 0, sizeof(addr));
    addr.sin_port = htons(PORT);
    addr.sin_family = AF_INET;


    if (bind(serverSocket, (const sockaddr *) &addr, (socklen_t) addrLen)) {
        std::cerr << "Bind error\n";
        exit(EXIT_FAILURE);
    }
    std::unordered_set<int> clientSockets;
    fd_set readfds;
    fd_set writefds;
    char buffer[1025];
    int bufSize = 1024;
    listen(serverSocket, 3);
    std::unordered_map<int, std::string> sendBuffer;
    while (true) {
        FD_ZERO(&readfds);
        FD_SET(serverSocket, &readfds);
        int maxSocket = serverSocket;
        for (int j : clientSockets){
            if (j > 0) {
                FD_SET(j, &readfds);
                maxSocket = std::max(maxSocket, j);
            }
        }

        int activity = select(maxSocket + 1, &readfds, &writefds, nullptr, nullptr);
        if (FD_ISSET(serverSocket, &readfds)) {
            int newSocket = accept(serverSocket, (sockaddr *) &addr, (socklen_t *) &addrLen);
            printf("New connection from %s:%d\n", inet_ntoa(addr.sin_addr), htons(addr.sin_port));
            clientSockets.insert(newSocket);
        }
        std::unordered_set<int> nextIteration;
        for (int client : clientSockets){
            if (FD_ISSET(client, &readfds)) {
                int readed = (int) read(client, buffer, bufSize);
                printf("Readed %d bytes\n", readed);
                if (readed > 0) {
                    buffer[readed] = '\0';
                    printf("Readed: %s\n", buffer);
                    for (int client1 : clientSockets) {
                        if (client1 == 0 || client == client1)
                            continue;
                        sendBuffer[client1] += buffer;
                    }
                    nextIteration.insert(client);
                }
                if (readed <= 0)
                    close(client);
            } else
                nextIteration.insert(client);
        }
        std::swap(nextIteration, clientSockets);

        for (int client : clientSockets){
            if (FD_ISSET(client, &writefds)){
                auto sended = (size_t) send(client, sendBuffer[client].c_str(), sendBuffer[client].size(), 0);
                std::string newStr;
                for (size_t i = sended; i < sendBuffer[client].size(); i++)
                    newStr += sendBuffer[client];
                sendBuffer[client] = newStr;
            }
        }
    }
}