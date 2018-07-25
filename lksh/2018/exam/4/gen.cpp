#include <bits/stdc++.h>

using namespace std;


int main(){
    srand(time(0));
    int n = rand() % 15 + 1;
    cout << n << '\n';
    vector<int> kek(n);
    for (int i = 0; i < n; i++) kek[i] = i + 1;
    int iter = rand() % 1000000;
    while (iter--) next_permutation(kek.begin(), kek.end());
    for (int i :kek) cout << i << ' ';
    cout << '\n';
    int m = rand() % 15 + 1;
    cout << m << '\n';
    for (int i = 0; i < m; i++){
        int l = rand() % n + 1;
        int r = rand() % n + 1;
        if (r < l) swap(l, r);
        cout << l << ' ' << r << '\n';
    }
}