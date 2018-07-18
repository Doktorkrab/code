#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXN = 5;
#else
const int INF = 1e9;
const int MAXN = 20; 
#endif
#define int int64_t
// -*-*-* All variables *-*-*-
int dp_path[MAXN][(1 << MAXN)];
int dp_path1[1 << MAXN];
int dp[(1 << MAXN)];
int g[MAXN][MAXN];
int n, m;

// -*-*-* All functions *-*-*-
void init(){
    for (int i = 0;i < n; i++) {
        fill(dp_path[i], dp_path[i] + (1 << n), 0);
        fill(g[i], g[i] + n, 0);
    }
    fill(dp, dp + (1 << n), 0);
    fill(dp_path1, dp_path1 + (1 << n), 0);
}
int test(int mask, int bit){
    return mask & (1 << bit);
}
void solve(){
    init();
    while (m--){
        int v, u;
        cin >> v >> u;
        g[--v][--u] = 1;
        dp_path[u][(1 << v) | (1 << u)] = 1; 
        // g[u][v] = g[v][u];
        // cerr << m << '\n';
    }

    for (int mask = 1; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (!g[i][j]) continue;
                if (!test(mask, i) || test(mask, j)) continue;
                dp_path[j][mask | (1 << j)] += dp_path[i][mask];
            }
            dp_path1[mask] += dp_path[i][mask];
        }
    }
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); mask++){
        int high = 0;
        for (int i = 0; i < n; i++) if (test(mask, i)) high = i;
        for (int submask = mask; test(submask, high); submask = mask & (submask - 1)){
            // cerr << dp_path1[submask] << ' ' << dp[mask ^ submask] << ' ' << mask << ' ' << submask << '\n'; 
            dp[mask] += dp_path1[submask] * dp[mask ^ submask];
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}
int32_t main(){
    #ifdef LOCAL
    string taskName = "F";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n >> m){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}