#include <bits/stdc++.h>
#include <ostream>

using namespace std;
#define int int64_t

struct Edge {
    int v, u, f, c;

    operator int() const {
        return c - f;
    }

    friend ostream &operator<<(ostream &os, const Edge &edge) { // For debug
        os << "v: " << edge.v << " u: " << edge.u << " f: " << edge.f << " c: " << edge.c;
        return os;
    }
};

int n, m;
vector<vector<pair<int, int>>> g; // (v->u, u->v);
vector<Edge> edges;
vector<int> d;
vector<int> used;

void bfs(int64_t MAX) {
    d.assign(n, -1);
    d[0] = 0;
    deque<int> q = {0};
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto pr : g[v]) {
            Edge u = edges[pr.first];
            if (d[u.u] == -1 && u >= MAX) {
                d[u.u] = d[v] + 1;
                q.push_back(u.u);
            }
        }
    }
}

int dfs(int v, int mn = 1e9) {
    if (v == n - 1)
        return mn;
    used[v] = 1;
    for (auto pr : g[v]) {
        Edge u = edges[pr.first];
        if (used[u.u] || u == 0 || d[u.u] != d[v] + 1)
            continue;
        int res = dfs(u.u, min(mn, (int) u));
        if (res != 0) {
            used[v] = 0;
            edges[pr.first].f += res;
            edges[pr.second].f -= res;
            return res;
        }
    }
    return 0;
}

void dfs1(int v) {
    used[v] = 1;
    for (auto pr : g[v]) {
        Edge u = edges[pr.first];
        // cout << u << '\n';         
        if (u != 0 && !used[u.u]) {
            dfs1(u.u);
        }
    }
}

int32_t main() {
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    edges.resize(2 * m);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        --v, --u;
        edges[2 * i] = {v, u, 0, w};
        edges[2 * i + 1] = {u, v, 0, w};
        g[v].push_back({2 * i, 2 * i + 1});
        g[u].push_back({2 * i + 1, 2 * i});
    }
    int ans = 0;
    for (int power = 30; power >= 0; power--) {
        int fl = 0;
        while (1) {
            bfs((1LL << power));
            // bfs(0);
            if (d[n - 1] == -1)
                break;
            used.assign(n, 0);
            while (fl = dfs(0)) {
                ans += fl;
            }
        }
    }
//    for (int i = 0; i < m; i++) {
//        int j = 2 * i;
//        if (edges[j].f > 0) {
//            cout << edges[j] << '\n';
//        }
//    }
    used.assign(n, 0);
    dfs1(0);
    vector<int> ans1;
    // for (int i = 0; i < n; i++)
        // cout << used[i] << " \n"[i == n - 1];
    for (int i = 0; i < 2 * m; i += 2) {
        if (used[edges[i].v] ^ used[edges[i].u])
            ans1.push_back(i / 2 + 1);
    }
    cout << ans1.size() << ' ' << ans << '\n';
    for (auto i : ans1)
        cout << i << ' ';
    cout << '\n';
}