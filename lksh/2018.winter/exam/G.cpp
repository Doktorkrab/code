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
int s, t;

void bfs(int64_t MAX) {
    d.assign(2 * n + 2, -1);
    d[s] = 0;
    deque<int> q = {s};
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


inline void init(){
	g.resize(2 * n + 2, {});
	d.resize(2 * n + 2, -1);
	used.resize(2 * n + 2, 0);
}

inline void solve(){
	init();
	int ans = 0;
	s = 2 * n;
	t = 2 * n + 1;
	int sum = 0;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		int id = edges.size();
		sum += x;
		edges.push_back({2 * n, i, 0, x});
		edges.push_back({i, 2 * n, 0, 0});
		g[2 * n].push_back({id, id + 1});
		g[i].push_back({id + 1, id});
	}
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		int id = edges.size();
		edges.push_back({n + i, 2 * n + 1, 0, x});
		edges.push_back({2 * n + 1, n + i, 0, 0});
		// sum += x;
		g[n + i].push_back({id, id + 1});
		g[2 * n + 1].push_back({id + 1, id});
	}	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int id = edges.size();
			edges.push_back({i, n + j, 0, 100});
			edges.push_back({n + j, i, 0, 0});
			g[i].push_back({id, id + 1});
			g[n + j].push_back({id + 1, id});
		}
	}
	cerr << "here\n";
    for (int power = 30; power >= 0; power--) {
        int fl = 0;
        while (1) {
            bfs((1LL << power));
            if (d[t] == -1)
                break;
            used.assign(2 * n + 2, 0);
            while (fl = dfs(s)) {
                ans += fl;
            }
        }
    }
    cerr << "found\n";
    cerr << ans << ' ' << sum << '\n';
    for (auto E : edges){
    	cerr << E << '\n';
    }
    if (ans != sum){
    	cout << "NO\n";
    	return;
    }
    cout << "YES\n";
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++){
    	for (auto pr : g[i]){
    		Edge to = edges[pr.first];
    		if (!(to.u >= n && to.u < 2 * n))
    			continue;
    		matrix[i][to.u - n] = to.f;
    	}
    }
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < n; j++)
    		cout << matrix[i][j] << " \n"[j == n - 1];
    }
}


int main(){
	#ifdef LOCAL
		freopen("G.in", "r", stdin);
		freopen("G.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}