#include <bits/stdc++.h>

using namespace std;

int main(){
    mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
    int n = 5;
    cout << n << '\n';
    for (int i = 0; i < n; i++)
        cout << rnd() % (1 << 10) << " \n"[i == n - 1];
    int q = rnd() % 5;
    cout << q << '\n';
    for (int i = 0; i < q; i++)
        cout << rnd() % n + 1 << ' ' << rnd() % (1 << 10) << '\n';
}
