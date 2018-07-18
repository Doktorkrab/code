#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXLOG = 5;
const int MAXLOG_N = 10;
#else
const int INF = 1e9;
const int MAXLOG = 25;
const int MAXLOG_N = 2e5;
#endif

const pair<int, int> MAX = {INF, INF};

// -*-*-* All variables *-*-*-
int n, m, timer = 0, root;
int color = 0;
vector<vector<int>> g, g1;
vector<vector<pair<int, int>>> sparse;
vector<pair<int, int>> euler;
vector<int> tin, dp, colors, logs, used, id, depth;

// -*-*-* All functions *-*-*-
void init() {
    g.assign(n, {});
    g1.assign(n, {});
    sparse.clear();
    logs.assign(MAXLOG_N, 0);
    for (int i = 2; i < MAXLOG_N; i++) {
        logs[i] = logs[i / 2] + 1;
    }
    tin.assign(n, 0);
    dp.assign(n, INF);
    euler.clear();
    colors.assign(n, -1);
    used.assign(n, 0);
    id.assign(n, -1);
    depth.assign(n, 0);
    timer = 0;
    color = 0;
}
int dfs(int v, int p) {
    tin[v] = dp[v] = timer++;
    used[v] = 1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        if (!used[u]) {
            dp[v] = min(dp[v], dfs(u, v));
        } else {
            dp[v] = min(dp[v], tin[u]);
        }
    }
    return dp[v];
}
void paint(int v) {
    colors[v] = color;
    for (int u : g[v]) {
        if (colors[u] != -1)
            continue;
        if (tin[v] < dp[u]) {
            color++;
        }
        paint(u);
    }
}

void color_all() {
    used.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1)
            paint(i);
    }
}

void dfs_euler(int v, int d, int p = -1) {
    id[v] = euler.size();
    euler.push_back({d, v});
    depth[v] = d;
    for (int u : g1[v]) {
        if (u == p)
            continue;
        dfs_euler(u, d + 1, v);
        euler.push_back({d, v});
    }
}

void build() {
    // cerr << "build\n";
    sparse.assign(MAXLOG, vector<pair<int, int>>(euler.size(), MAX));
    sparse[0] = euler;
    for (int log = 1; log < MAXLOG; log++) {
        for (int i = 0; i + (1 << (log - 1)) < (int)(euler.size()); i++) {
            sparse[log][i] =
                min(sparse[log - 1][i], sparse[log - 1][i + (1 << (log - 1))]);
        }
    }
}

int get_min(int l, int r) {
    if (l > r)
        swap(l, r);
    int len = r - l + 1;
    int power = logs[len];
    return min(sparse[power][l], sparse[power][r - (1 << power) + 1]).second;
}

int lca(int a, int b) { return get_min(id[a], id[b]); }

void solve() {
    init();
    cin >> root;
    root--;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i, -1);
    color_all();
    for (int i = 0; i < n; i++) {
        for (int u : g[i]) {
            if (colors[i] == colors[u])
                continue;
            g1[colors[i]].push_back(colors[u]);
            g1[colors[u]].push_back(colors[i]);
        }
    }
    dfs_euler(colors[root], 0);
    build();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        a = colors[a];
        b = colors[b];
        // cerr << a << ' ' << b << '\n';
        // cerr << depth.size() << '\n';
        // cerr << lca(a, b) << '\n';
        cout << depth[lca(a, b)] << '\n';
    }
}
int main() {
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
    while (cin >> n >> m) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}