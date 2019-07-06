#include <bits/stdc++.h>
using namespace std;

int x, a, y, b, l;
vector<vector<pair<int, int>>> dp;
int check(int m){
    pair<int, int> tmp;
    dp.assign(x + 1, vector<pair<int, int>>(y + 1, {0 ,0}));
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= y; ++j) {
            if (i){
                tmp = dp[i - 1][j];
                tmp.second += a;
                if (tmp.first != l && tmp.second >= m){
                    tmp.first++;
                    tmp.second = 0;
                }
                dp[i][j] = max(dp[i][j], tmp);
//                cout << i << ' ' << j << ' ' << tmp.first << ' ' << tmp.second << '\n';
//                if (dp[i][j].first >= l) return 1;

            }
            if (j){
                tmp = dp[i][j - 1];
                tmp.second += b;
                if (tmp.first != l && tmp.second >= m){
                    tmp.first++;
                    tmp.second = 0;
                }
                dp[i][j] = max(dp[i][j], tmp);
//                cout << i << ' ' << j << ' ' << tmp.first << ' ' << tmp.second << '\n';
                if (dp[i][j].first >= l) return 1;
            }
        }
    }
    return 0;
}
int bin_search(){
    int l = 0, r = 1e9;
    while (r - l > 1){
        int m = (l + r) / 2;
        int ans = check(m);
//        cout << m << ' ' << ans << '\n';
        if (ans) l = m;
        else r = m;
//        return 0;
    }
    return l;
}
int main(){
    freopen("bridge.in", "r", stdin);
    freopen("bridge.out", "w", stdout);
    while (cin >> x >> a >> y >> b >> l) cout << bin_search() << '\n';
}