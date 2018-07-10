#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

// -*-*-* All variables *-*-*-
vector<vector<int>> g, matrix, g1;
vector<int> matching;
vector<int> used;
const int NO_MATCHING = -INF;
int n, m, k, iteration = 0;
// -*-*-* All functions *-*-*-
void init() {
    g.clear();
    matching.clear();
    used.clear();
    matrix.clear();
    g1.clear();
    iteration = 0;
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
void dfs1(int v) {
    used[v] = 1;
    for (int u : g1[v])
        if (!used[u])
            dfs1(u);
}
void solve() {
    init();
    cin >> n >> m;
    g.resize(n);
    matching.assign(m, NO_MATCHING);
    used.assign(n, -1);
    matrix.assign(n, vector<int>(m, 1));
    g1.resize(n + m);
    // cerr << n << m << k << '\n';
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        while (cnt != 0) {
            // cerr << i << ' ' << cnt << '\n';
            matrix[i][cnt - 1] = 0;
            cin >> cnt;
        }
    }
    // cerr << "hre";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j])
                g[i].push_back(j);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dfs(i)) {
            ans++;
            iteration++;
        }
    }
    vector<int> can_launch(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            if (matching[j] == i) {
                g1[n + j].push_back(i);
                can_launch[i] = 0;
            } else {
                g1[i].push_back(n + j);
            }
        }
    }
    // cerr << "here";
    used.assign(n + m, 0);
    for (int i = 0; i < n; i++) {
        if (can_launch[i] && !used[i])
            dfs1(i);
    }
    vector<int> independent(n + m, 0);
    int ans_n = 0, ans_m = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            independent[i] = 1;
            ans_n++;
        }
    }
    for (int j = 0; j < m; j++) {
        if (!used[n + j]) {
            independent[n + j] = 1;
            ans_m++;
        }
    }
    cout << (n + m) - ans << '\n';
    cout << ans_n << ' ' << ans_m << '\n';
    for (int i = 0; i < n; i++)
        if (independent[i])
            cout << i + 1 << ' ';
    cout << '\n';
    for (int j = 0; j < m; j++)
        if (independent[n + j])
            cout << j + 1 << ' ';
    cout << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "B";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t;
    cin >> t;
#endif
    while (t--) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}