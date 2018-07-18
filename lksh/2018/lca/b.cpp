#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXLOG = 5;
#else
const int INF = 1e9;
const int MAXLOG = 25;
#endif

// -*-*-* All variables *-*-*-

vector<vector<pair<int, int>>> g;
vector<vector<int>> bin_up;
vector<vector<int>> min_up;
vector<int> tin, tout, level;
int n, m, timer = 0;

// -*-*-* All functions *-*-*-
void add(pair<int, int> a, int par) {
    bin_up[a.first][0] = par;
    min_up[a.first][0] = a.second;
    // cerr << a.first << "!!!!!!!!!!!!!!!!!!!!!!\n";
    for (int i = 1; i < MAXLOG; i++) {
        min_up[a.first][i] =
            min(min_up[a.first][i - 1], min_up[bin_up[a.first][i - 1]][i - 1]);
        bin_up[a.first][i] = bin_up[bin_up[a.first][i - 1]][i - 1];
    }
    // cerr << a.first << "!!!!!!!!!!!" << '\n';
}
void calc(int v, int d, int p = -1) {
    // cerr << v << ' ' << d << ' ' << p << '\n';
    tin[v] = timer++;
    level[v] = d;
    for (auto u : g[v]) {
        add(u, v);
        if (u.first != p)
            calc(u.first, d + 1, v);
    }
    tout[v] = timer++;
}

bool is_anc(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }

int lca(int a, int b) {
    if (is_anc(a, b))
        return a;
    // cerr << a << ' ' << b << '\n';
    for (int i = MAXLOG - 1; i >= 0; i--) {
        // cerr << a << ' ' << b << ' ' << bin_up[a][i] << ' ' << i << '\n';
        int v = bin_up[a][i];
        if (!is_anc(v, b))
            a = v;
    }
    return bin_up[a][0];
}

int get_min(int v, int a) {
    int ans = INT_MAX;
    for (int i = 0; i < MAXLOG; i++) {
        if (a & (1 << i)) {
            ans = min(ans, min_up[v][i]);
            v = bin_up[v][i];
        }
    }
    return ans;
}
void init() {
    g.clear();
    bin_up.clear();
    min_up.clear();
    tin.clear();
    tout.clear();
    level.clear();
}

void solve() {
    g.resize(n);
    bin_up.assign(n, vector<int>(MAXLOG + 1));
    min_up.assign(n, vector<int>(MAXLOG + 1));
    tin.resize(n);
    tout.resize(n);
    level.resize(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back({i, b});
    }
    calc(0, 0);
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        int lca_ = lca(--a, --b);
        cout << min(get_min(a, level[a] - level[lca_]),
                    get_min(b, level[b] - level[lca_]))
             << '\n';
    }
}
int main() {
#ifdef LOCAL
    string taskName = "B";
    assert(freopen((taskName + ".in").c_str(), "r", stdin));
    assert(freopen((taskName + ".out").c_str(), "w", stdout));
    clock_t start = clock();
#else
// string taskName = "";
// freopen((taskName + ".in").c_str(), "r", stdin);
// freopen((taskName + ".out").c_str(), "w", stdout);
#endif
    while (cin >> n) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}