#include <bits/stdc++.h>

using namespace std;


int main(){
    mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
    int n = rnd() % 10 + 1, k = rnd() % 5 + 1;
    string s(n, 'N');
    string kek = "ACGTN";
    int cnt = 0;
    for (int i = 0; i < n; i++){
        s[i] = kek[rnd() % 5];
        cnt += s[i] == 'N';
    }
    int gg = 1;
    if (cnt)
        gg = rnd() % (cnt * cnt + 1);
    cout << n << ' ' << k << ' ' << gg << '\n';
    cout << s << '\n';
}