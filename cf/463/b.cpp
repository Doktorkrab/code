#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kek(10, vector<int>((int)1e6 + 1));
int f(int a){
    int lol = 1;
    // cerr << a << '\n';
    while (a != 0){
        lol = (a % 10 == 0 ? lol : (lol * (a % 10)));
        a /= 10;
    }
    // cerr << a << ' ' << lol << '\n';
    return lol;
}
int g(int a){
    if (a < 10) return a;
    // cerr << a << '\n';
    return g(f(a));
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 1; i <= 1e6; i++){
        for (int j = 1; j <= 9;j++){
            // cerr << i << ' ' << j << '\n';
            // cerr << g(i) << '\n';
            kek[j][i] = kek[j][i - 1] + (g(i) == j);
        }
    }
    for (int i = 0; i < q;i++){
        int l, r, k;
        cin >> l >> r >> k;
        cout << kek[k][r] - kek[k][l - 1] << '\n';
    }
}