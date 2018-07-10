#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

struct DSU {
    int n;
    int cnt;
    vector<int> sz;
    vector<int> parent;
    DSU(int n) : n(n), cnt(n), sz(n, 1), parent(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    DSU() {}

    int get(int a) { return parent[a] = (parent[a] == a ? a : get(parent[a])); }

    bool check(int a, int b) { return get(a) == get(b); }

    void un(int a, int b) {
        b = get(b);
        a = get(a);
        if (check(a, b))
            return;
        if (sz[a] > sz[b])
            swap(a, b);
        parent[a] = b;
        sz[b] += a;
        --cnt;
    }
};
const int FOR_X = 0;
const int FOR_Y = 1;
struct Edge {
    int type, v, u, cost;
    bool operator<(const Edge &o) {
        return tie(cost, v, u, type) < tie(o.cost, o.v, o.u, o.type);
    }
};

// -*-*-* All variables *-*-*-

DSU for_x, for_y;
vector<Edge> edges;
int nx, mx, ny, my;
int64_t ans;

// -*-*-* All functions *-*-*-

void init() {
    edges.clear();
    ans = 0;
}

void solve() {
    init();
    cin >> nx >> mx;
    for_x = DSU(nx);
    edges.resize(mx);
    for (int i = 0; i < mx; i++) {
        int v, u, cost;
        cin >> v >> u >> cost;
        edges[i] = {FOR_X, v - 1, u - 1, cost};
    }

    cin >> ny >> my;
    for_y = DSU(ny);
    for (int i = 0; i < my; i++) {
        int v, u, cost;
        cin >> v >> u >> cost;
        edges.push_back({FOR_Y, v - 1, u - 1, cost});
    }

    sort(edges.begin(), edges.end());
    for (int i = 0; i < mx + my; i++) {
        ;
        // cerr << edges[i].type << ' ' << edges[i].cost << ' ' << edges[i].v <<
        // ' ' << edges[i].u << '\n';
        if (edges[i].type == FOR_X) {
            // cerr << for_x.check(edges[i].v, edges[i].u) << "check\n";
            if (for_x.check(edges[i].v, edges[i].u))
                continue;
            for_x.un(edges[i].v, edges[i].u);
            // cerr << for_y.cnt << '\n';
            ans += 1LL * edges[i].cost * for_y.cnt;
        } else {
            // for (int i : for_y.parent) cerr << i << ' ';
            // cerr << '\n';
            if (for_y.check(edges[i].v, edges[i].u))
                continue;
            for_y.un(edges[i].v, edges[i].u);
            // cerr << for_x.cnt << '\n';
            ans += 1LL * edges[i].cost * for_x.cnt;
        }
    }
    cout << ans << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "C";
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