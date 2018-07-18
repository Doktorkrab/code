#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXLOG = 5;
const int MAXLOG_N = 2e5;
#else
const int INF = 1e9;
const int MAXLOG = 25;
const int MAXLOG_N = 2e5;
#endif
using ll = long long;
const pair<int, int> MAX = {INF, INF};

// -*-*-* All variables *-*-*-

vector<vector<pair<int, int>>> sparse; // [LOG][N]
vector<vector<int>> g;
vector<int> logs;
vector<int> id;
vector<pair<int, int>> euler;
int n, m;

// -*-*-* All functions *-*-*-

void init() {
    g.assign(n, {});
    logs.assign(MAXLOG_N + 1, 0);
    for (int i = 2; i <= MAXLOG_N; i++) {
        logs[i] = logs[i / 2] + 1;
    }
    id.assign(n, -1);
    euler.clear();
}

void precalc(int v, int d, int p = -1) {
    id[v] = euler.size();
    euler.push_back({d, v});
    for (int u : g[v]) {
        if (u == p)
            continue;
        precalc(u, d + 1, v);
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
    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;
        g[t].push_back(i);
    }
    precalc(0, 0);
    // cerr << "kek";
    build();
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    ll x, y, z;
    cin >> x >> y >> z;
    int prev = 0;
    while (m--) {
        prev = lca((a + prev) % n, b);
        ans += prev;
        a = (x * a + y * b + z) % n;
        b = (x * b + y * a + z) % n;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    string taskName = "C";
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