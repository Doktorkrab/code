#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>

#define PORT 1337
#define ADDRESS "127.0.0.1"

int main(){
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    fd_set readfds;
    fd_set writefds;
    sockaddr_in addr;
    int addrLen = sizeof(addr);
    memset(&addr, 0, sizeof(addr));
    addr.sin_port = htons(PORT);
    addr.sin_family = AF_INET;
    inet_pton(ADDRESS, &addr.sin_addr);

}