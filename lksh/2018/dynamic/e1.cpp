#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

// -*-*-* All variables *-*-*-
vector<vector<int>> dp;
int n, k;
// -*-*-* All functions *-*-*-
void init() {}
void solve() {
    init();
    cin >> n >> k;
    dp.assign(n + 1, vector<int>(k + 1, INF));
    for (int i = 0; i <= k; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= k; i++) {
        int best = 1;
        for (int j = 1; j <= n; j++) {
            while (best < j &&
                   max(dp[j - best][i - 1], dp[best - 1][i - 1] + 1) >=
                       max(dp[j - best + 1][i - 1], dp[best][i - 1] + 1)) {
                best++;
            }
            dp[j][i] = min(dp[j][i],
                           max(dp[j - best][i - 1], dp[best - 1][i - 1] + 1));
        }
    }
    cout << (dp[n][k] == INF ? -1 : dp[n][k]) << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "E";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
#endif
    while (t--) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}