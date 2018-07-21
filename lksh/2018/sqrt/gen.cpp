#include <bits/stdc++.h>

using namespace std;

int main(){
    srand(time(0));
    int n = 100, m = 100;
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; i++){
        cout << rand() << ' ';
    }
    cout << '\n';

    for (int i = 0; i < m; i++){
        int64_t ch = rand() % 2, l = rand() % n, r = rand() % n, x = rand();
        if (l > r) swap(l, r);
        cout << (ch ? "? " : "+ ") << l + 1 << ' ' << r + 1 << ' ' << x << '\n';
    }
}