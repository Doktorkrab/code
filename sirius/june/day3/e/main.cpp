#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;

    while(getline(cin, line)){
        size_t sz = 0;
        unsigned long long cur = 0, sum = 0;
        int cnt = 0;
        bool f = 0;
        for (char c : line){
            if (c >= '0' && c <= '9') f = 1;
            else cnt += f, f = 0;
        }
        cnt += f;
//        cout << cnt << '\n';
        if (cnt == 1){
            string ans;
            for (char c : line){
//                cout << c << ' ' << (c >= '0' && c <= '9') << '\n';
                if (c >= '0' && c <= '9') ans += c;
            }
            cout << ans << '\n';
            continue;
        }
//        cerr << "kek";
        while (!line.empty()){
            sum += stoull(line, &sz);
            line = line.substr(sz);
        }
        sum += cur;
        cout << sum << '\n';
    }
    return 0;
}