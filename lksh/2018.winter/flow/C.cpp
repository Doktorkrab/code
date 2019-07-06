#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <climits>

using namespace std;

int n;
struct Edge {
    int v, u, f, c;

    operator int() const {
        return c - f;
    }

    friend ostream &operator<<(ostream &os, const Edge &edge) { // For debug
        os << "v: " << edge.v << " u: " << edge.u << " f: " << edge.f << " c: " << edge.c;
        return os;
    }

    Edge(int v_, int u_, int f_, int c_) : v(v_), u(u_), f(f_), c(c_) {}
};

vector<Edge> edges;
vector<vector<pair<int, int>>> g;
vector<int> d;
vector<int> used;


void bfs(int64_t MAX) {
    d.assign(n + 2, -1);
    d[n] = 0;
    deque<int> q = {n};
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
    if (v == n + 1)
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



inline void init(){
	g.resize(n + 2, {});
	d.resize(n + 2, -1);
	used.resize(n + 2, 0);
}

inline void solve(){
	init();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		int id = edges.size();
		int u = 0;
		if (w < 0){
			edges.emplace_back(i, n + 1, 0, -w);
			edges.emplace_back(n + 1, i, 0, 0);
			u = n + 1;
		}
		else {
			edges.emplace_back(i, n, 0, 0);
			edges.emplace_back(n, i, 0, w);
			sum += w;
			u = n;
		}
		g[i].push_back({id, id + 1});
		g[u].push_back({id + 1, id});
	}
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		while(k--){
			int x;
			cin >> x;
			x--;
			int id = edges.size();
			edges.emplace_back(i, x, 0, INT_MAX);
			edges.emplace_back(x, i, 0, 0);
			g[i].push_back({id, id + 1});
			g[x].push_back({id + 1, id});
		}
	}
	// cerr << "ok\n";
	// for (int i = 0; i < n + 2; i++){
	// 	cout << i << ": ";
	// 	for (auto j : g[i]){
	// 		cout << "(" << edges[j.first] << ", " << edges[j.second] << ") ";
	// 	}
	// 	cout << '\n';
	// }
	int ans = 0;
    for (int power = 30; power >= 0; power--) {
        int fl = 0;
        while (1) {
            bfs((1LL << power));
            // bfs(0);
            // for (int i = 0; i < n + 2; i++){
            // 	cout << d[i] << " \n"[i == n + 1];
            // }
            if (d[n + 1] == -1)
                break;
            used.assign(n + 2, 0);
            while (fl = dfs(n)) {
                ans += fl;
            }
        }
    }
    // cout << ans << '\n';
    cout << sum - ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}