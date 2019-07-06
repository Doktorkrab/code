#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("computers.in", "r", stdin);
    freopen("computers.out", "w", stdout);
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int b1, b2, b3;
    cin >> b1 >> b2 >> b3;
    int ans = 0;
    ans += min(b1, a1);
    int tmp = min(a1, b1);
    a1 -= tmp;
    b1 -= tmp;
    tmp = min(b3, a1);
    ans += tmp;
    b3 -= tmp;
    a1 -= tmp;
    tmp = min(b2, a2);
    ans += tmp;
    b2 -= tmp;
    a2 -= tmp;
    tmp = min(b3, a2);
    ans += tmp;
    b3 -= tmp;
    a2 -= tmp;
    tmp = min(b1, a3);
    ans += tmp;
    b1 -= tmp;
    a3 -= tmp;
    tmp = min(b2, a3);
    ans += tmp;
    b2 -= tmp;
    a3 -= tmp;
    tmp = min(b3, a3);
    ans += tmp;
    b3 -= tmp;
    a3 -= tmp;
    cout << ans << '\n';
}