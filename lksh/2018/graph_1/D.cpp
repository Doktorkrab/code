#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

// -*-*-* All variables *-*-*-

vector<vector<int>> g, g_trans;
vector<int> colors, topsort;
vector<vector<int>> comps;
vector<unordered_set<int>> g_cond;
vector<int> used;
vector<int> tin, dp;
vector<int> cut_point;
vector<int> can, can_tmp;
vector<int> ans;
int n, m, timer = 0, n_orig;
// -*-*-* All functions *-*-*-

void get_topsort(int v) {
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u])
            get_topsort(u);
    }
    topsort.push_back(v);
}

void paint(int v, int color) {
    colors[v] = color;
    comps[color].push_back(v);
    for (int u : g_trans[v]) {
        if (colors[u] == -1)
            paint(u, color);
    }
}

int dfs(int v, int p = -1, int flag1 = 0) {
    used[v] = 1;
    tin[v] = dp[v] = timer++;
    int child = 0, flag = 0;
    if (v == colors[n_orig - 1])
        flag1 = 1;
    for (int u : g_cond[v]) {
        if (used[u]) {
            if (u == p)
                continue;
            dp[v] = min(dp[v], tin[u]);
            continue;
        }
        dp[v] = min(dp[v], dfs(u, v, flag1));
        child++;
        if (dp[u] >= tin[v] && child && !flag && !flag1 && p != -1) {
            if (comps[v].size() == 1) {
                ans.push_back(comps[v][0] + 1);
                flag = 1;
            }
        }
    }
    return dp[v];
}
void check(int v, const vector<vector<int>> &g) {
    can_tmp[v]++;
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u])
            check(u, g);
    }
}
void init() {
    g.clear();
    g_trans.clear();
    g_cond.clear();
    comps.clear();
    colors.clear();
    topsort.clear();
    used.clear();
    cut_point.clear();
    can.clear();
    tin.resize(n);
    dp.resize(n);
    ans.clear();
    can_tmp.clear();
    timer = 0;
}

void solve() {
    init();
    cin >> n >> m;
    can_tmp.assign(n, 0);
    n_orig = n;
    can_tmp.resize(n);
    g.resize(n);
    g_trans.resize(n);
    g_cond.resize(n);
    colors.assign(n, -1);
    used.assign(n, 0);
    comps.resize(n);
    cut_point.resize(n);
    can.assign(n, 1);
    tin.resize(n);
    dp.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        if (v == u) {
            can[v] = 0;
            continue;
        }
        g[v].push_back(u);
        g_trans[u].push_back(v);
    }
    check(0, g);
    used.assign(n, 0);
    check(n - 1, g_trans);
    for (int i = 0; i < n; i++) {
        can[i] &= (can_tmp[i] == 2);
    }
    if (!can[0] || !can[n - 1]) {
        cout << "0\n";
        return;
    }
    used.assign(n, 0);
    get_topsort(0);
    for (int i = 1; i + 1 < n; i++) {
        if (!used[i]) {
            get_topsort(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    int color = 0;
    for (int v : topsort) {
        if (colors[v] == -1) {
            paint(v, color);
            color++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!can[i])
            continue;
        for (int j : g[i]) {
            if (!can[j])
                continue;
            if (colors[i] != colors[j]) {
                g_cond[colors[i]].insert(colors[j]);
                g_cond[colors[j]].insert(colors[i]);
            }
        }
    }

    int n = color;
    used.assign(n, 0);
    dfs(0);

    if (comps[colors[0]].size() == 1)
        ans.push_back(1);
    reverse(ans.begin(), ans.end());
    if (comps[colors[n - 1]].size() == 1)
        ans.push_back(n_orig);

    cout << ans.size() << '\n';
    if (ans.size()) {
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }
}
int main() {
#ifdef LOCAL
    string taskName = "D";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "dfs";
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