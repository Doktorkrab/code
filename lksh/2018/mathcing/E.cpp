#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

// -*-*-* All variables *-*-*-
vector<vector<int>> g;
vector<int> matching;
vector<int> used;`
const int NO_MATCHING = -INF;
int n, m, k, iteration = 0;
// -*-*-* All functions *-*-*-
void init() {
    g.clear();
    matching.clear();
    used.clear();
}
int dfs(int v) {
    if (used[v] == iteration)
        return 0;
    used[v] = iteration;
    for (int u : g[v]) {
        if (matching[u] == NO_MATCHING) {
            matching[u] = v;
            return 1;
        }
    }
    for (int u : g[v]) {
        if (dfs(matching[u])) {
            matching[u] = v;
            return 1;
        }
    }
    return 0;
}
void solve() {
    cin >> n >> m >> k;
    g.resize(n);
    matching.assign(m, NO_MATCHING);
    used.assign(n, -1);
    // cerr << n << m << k << '\n';
    while(k--){
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
    }
    // cerr << "kek";
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dfs(i)) {
            ans++;
            iteration++;
        }
    }
    // for (int i = 0;i < m; i++) cerr << matching[i] << '\n';
    cout << (n + m) - ans << '\n';
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