#include <bits/stdc++.h>
#include <ostream>

using namespace std;
#define int int64_t

struct Edge {
    int v, u, f, c, used;

    operator int() const {
        return c - f;
    }

    friend ostream &operator<<(ostream &os, const Edge &edge) { // For debug
        os << "v: " << edge.v << " u: " << edge.u << " f: " << edge.f << " c: " << edge.c;
        return os;
    }
};

int n, m;
int s, t;
vector<vector<pair<int, int>>> g; // (v->u, u->v);
vector<Edge> edges;
vector<int> d;
vector<int> used;

void bfs(int64_t MAX) {
    d.assign(n, -1);
    d[s] = 0;
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
    if (v == t)
        return mn;
    used[v] = 1;
    for (auto pr : g[v]) {
        Edge u = edges[pr.first];
        if (used[u.u] || u == 0)
            continue;
        int res = dfs(u.u, min(mn, (int) u));
        if (res > 0) {
            used[v] = 0;
            edges[pr.first].f += res;
            edges[pr.second].f -= res;
            return res;
        }
    }
    return 0;
}
vector<vector<int>> ans1(2);
void dfs1(int v, int c){
	cerr << v << ' ' << c << '\n';
	if (v == t){
		ans1[c].push_back(t);
		return;
	}
	for (auto u : g[v]){
		Edge &to = edges[u.first];
		if (to.f == 1 && to.c == 1){
			to.f--;
			edges[u.second].f++;
			dfs1(to.u, c);
			ans1[c].push_back(v);
			return;
		}
	}
	return;
}
int32_t main() {
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif

    cin >> n >> m >> s >> t;
    --s, --t;
    g.resize(n);
    used.resize(n);
    edges.resize(2 * m);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        edges[2 * i] = {v, u, 0, 1, 0};
        edges[2 * i + 1] = {u, v, 0, 0, 0};
        g[v].push_back({2 * i, 2 * i + 1});
        g[u].push_back({2 * i + 1, 2 * i});
    }
    used.assign(n, 0);
    int ans = dfs(s);
    used.assign(n, 0);
    ans += dfs(s);
	if (ans < 2){
		cout << "NO\n";
		return 0;
	}
	// cerr << s << '\n';
	// dfs1(s, 1);
	cout << "YES\n";
	dfs1(s, 0);
	dfs1(s, 1);
	for (int i = 0; i < 2; i++){
		reverse(ans1[i].begin(), ans1[i].end());
		// cout << s + 1 << ' ';
		for (int j : ans1[i])
			cout << j + 1 << ' ';
		cout << '\n';
		// cout << t + 1 << '\n';
	}
}