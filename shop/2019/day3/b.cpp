#include <bits/stdc++.h>


using namespace std;
vector<pair<int, int>> pairs;
vector<pair<int, int>> gg;
int ans = 0, n, n_old;
void rec(int pos){
    bool fl = 0;
    // for (auto i : pairs)
    //     cerr << "(" << i.first << ", " << i.second << ") ";
    if (pos == n){
        for (int x = 2; x <= n_old; x++){
            bool flag = 1;
            for (auto [a, b] : pairs)
                flag &= (a < x && b < x) || (a >= x && b >= x);
            fl |= flag;
                // cout << flag << ' ' << x << '\n';
        }
        if (!fl){
            // cerr << "!";
            ans++;
        }
        // cerr << '\n';
        return;
    }
    // cerr << '\n';
    pairs.push_back(gg[pos]);
    rec(pos + 1);
    pairs.pop_back();
    rec(pos + 1);
}
int main(){
    #ifdef LOCAL
        freopen("B.in", "r", stdin);
        freopen("B.out", "w", stdout);
    #endif
    cin >> n;
    n_old = n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (__gcd(i, j) == 1)
                gg.emplace_back(i, j);
    n = gg.size();
    rec(0);
    cout << ans << '\n';
}