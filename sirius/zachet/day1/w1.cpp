#include <bits/stdc++.h>


using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0;i < m;i++){
            int v, u;
            cin >> v >> u;
            matrix[--v][--u] = 1;
            matrix[u][v] = 1;
        }
        vector<int> independt((1 << n));
        for (int mask = 1; mask < (1 << n); mask++){
            bool f = 1;
            for (int i = 0;i < n;i++){
                if (((1 << i) & mask) == 0) continue;
                for (int j = 0; j < n; j++){
                    if (((1 << j) & mask) == 0) continue;
                    if (matrix[i][j]){
                        f = 0;
                        break;
                    }
                }

                if (!f) break;     
            }
            if (f) independt[mask] = 1;
        }
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        vector<int> p(1 << n, -1);
        for (int mask = 1; mask < (1 << n); mask++){
            //cout << "mask " << mask << '\n';
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask){
                if (independt[sub]){
                    //cout << "submask " << sub << ' ' << (mask ^ sub) <<'\n';
                    //cout << dp[mask] << ' ' << dp[mask ^ sub] + 1LL << '\n';
                    if (dp[mask ^ sub] + 1LL < dp[mask] * 1LL){
                        dp[mask] = dp[mask ^ sub] + 1LL;
                        p[mask] = sub;
                    }
                }
            }
            // cout << dp[mask] << '\n';
        }
        int mask = (1 << n) - 1;
        cout << dp[mask] << '\n';
        vector<int> ans(n);
        int color = 1;
        while (mask > 0){
            for (int i = 0;i < n;i++){
                if ((1 << i) & p[mask]){
                    ans[i] = color;
                }
            }
            mask ^= p[mask];
            color++;
        }
        for (int i : ans) cout << i << ' ';
        cout << '\n';

    }
}