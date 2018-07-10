#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXN = 10;
#else
const int INF = 1e9;
const int MAXN = 1e5;
#endif

// -*-*-* All variables *-*-*-
vector<vector<int>> g;
vector<vector<int>> matrix;
vector<pair<int, int>> needed_point, ans;
int n, s;
// -*-*-* All functions *-*-*-
void init() {
    g.clear();
    matrix.clear();
    needed_point.clear();
}

void dfs(int v) {
    while (g[v].size() != 0) {
        auto tmp = g[v].back();
        g[v].pop_back();
        dfs(tmp);
        if (tmp < 2 * n || v < 2 * n)
            ans.push_back({min(tmp, v), max(tmp, v) - n});
    }
}

void solve() {
    init();
    cin >> n >> s;
    g.resize(2 * n + 2);
    matrix.assign(2 * n + 2, vector<int>(2 * n + 2));
    for (int i = 0; i < s; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        needed_point.push_back({x, y});
        g[x].push_back(n + y);
        g[n + y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (g[i].size() & 1) {
            g[i].push_back(2 * n);
            g[2 * n].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (g[i + n].size() & 1) {
            g[i + n].push_back(2 * n + 1);
            g[2 * n + 1].push_back(i + n);
        }
    }
    if (g[2 * n].size() & 1 && g[2 * n + 1].size() & 1) {
        g[2 * n].push_back(2 * n + 1);
        g[2 * n + 1].push_back(2 * n);
    }
    for (int i = 0; i < 2 * n; i++) {
        dfs(i);
    }
    int color = 1;
    for (auto i : ans) {
        matrix[i.first][i.second] = color;
        color ^= 1;
    }
    string ans = "MW";
    for (auto i : needed_point) {
        cout << ans[matrix[i.first][i.second]];
    }
    cout << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "A";
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