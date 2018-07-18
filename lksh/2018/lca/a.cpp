#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

// -*-*-* All variables *-*-*-
vector<vector<int>> g;
vector<int> tin, tout;
int n, m, timer = 0, root = 0;

// -*-*-* All functions *-*-*-
void init() {
    g.clear();
    tin.clear();
    tout.clear();
    timer = 0;
}

void dfs(int v, int p = -1) {
    tin[v] = timer++;
    for (int u : g[v])
        if (u != p)
            dfs(u, v);
    tout[v] = timer++;
}

bool is_parent(int a, int b) { // a - parent b
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void solve() {
    g.resize(n);
    tin.resize(n);
    tout.resize(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        --v;
        if (v == -1)
            root = i;
        else
            g[v].push_back(i);
    }
    dfs(root);
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << is_parent(a - 1, b - 1) << '\n';
    }
}
int main() {
#ifdef LOCAL
    string taskName = "A";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
#else
    string taskName = "";
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