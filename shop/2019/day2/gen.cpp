#include <bits/stdc++.h>

using namespace std;

int main(){
    mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
    int n = rnd() % 5 + 1;
    cout << n << ' ' << n << '\n';
    for (int i = 0; i < n; i++)
        cout << rnd() % 100 << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << rnd() % 100 << ' ';
    cout << '\n';
    

}