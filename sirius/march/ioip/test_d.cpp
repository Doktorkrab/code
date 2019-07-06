#include <bits/stdc++.h>
using namespace std;


int main(){
    mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
    int n = rnd() % 10 + 1;
    int p = rnd() % 10 + 1;
    cout << "n is " << n << '\n';
    cout << "p is " << p << '\n';
    for (int i = 0; i < n; i++)
        cout << rnd() % p << " \n"[i == n - 1];
}
