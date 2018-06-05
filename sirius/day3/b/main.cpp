#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int now = 0;
    for (int i = 0;i < n;i++){
        vector<int> tmp(m);
        iota(tmp.begin(), tmp.end(), now);
        if ( i & 1) reverse(tmp.begin(), tmp.end());
        for (int i : tmp) {
            cout << setw(3) << i;
        }
        cout << '\n';
        now += m;
    }
    return 0;
}