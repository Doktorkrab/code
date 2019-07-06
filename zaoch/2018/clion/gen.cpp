#include <bits/stdc++.h>

using namespace std;


int main(){
    srand(time(0));
    int n = (int)5e5, q = (int)2.5e5;
    cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; i++){
        cout << rand() % (n + 1) << ' ';
    }
    cout << '\n';
    int change = 0;
    const int MAX_CHANGE = (int) 5e4;
    for (int i = 0; i < q; i++){
        int l = rand() % n;
        int r = rand() % n;
        int type = rand() % 2;
        if (type == 1 && change >= MAX_CHANGE) type = 0;
        if (type == 1) r = rand() % (n + 1) - 1, change++;
        if (type == 0 && l > r) swap(l, r);
        cout << "?!"[type] << " " << l + 1 << ' ' << r + 1 << '\n';
    }
}