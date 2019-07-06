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
#define int int64_t
int n;
struct Edge{
	int u, w;
	bool can_change;
	bool operator< (const Edge& oth) const {
		return tie(w, u, can_change) < tie(oth.w, oth.u, oth.can_change);
	}
};
const int MAXN = 1e5 + 5;
vector<Edge> g[MAXN];
int dist[MAXN];
inline void init(){
	for (int i = 0; i < n; i++){
		g[i].clear();
	}
}
int cost = 0;
int dfs(int v, int p = -1){
	Edge from = {0, 0, 0};
	set<pair<int, Edge>> sons;
	vector<pair<int, Edge>> sons_v;
	for (Edge e : g[v]){
		if (e.u == p){
			from = e;
			continue;
		}
		int tmp = dfs(e.u, v);
		sons.insert({tmp, e});
		if (e.can_change)
			sons_v.push_back({tmp,e});
	}
	if (sons.empty()){
		if (from.can_change)
			return 0;
		return from.w;
	}
	int max_ = sons.rbegin()->first;
	for (int i = 0; i < sons_v.size(); i++){
		sons.erase(sons_v[i]);
		sons.insert({sons_v[i].first - sons_v[i].second.w, sons_v[i].second});
		max_ = min(max_, sons.rbegin()->first);
		sons.erase({sons_v[i].first - sons_v[i].second.w, sons_v[i].second});
		sons.insert(sons_v[i]);
	}
	if (from.can_change)
		return min(max_ + from.w, sons.rbegin()->first);
	return max_ + from.w;
}

inline void solve(){
	init();
	for (int i = 0; i < n - 1; i++){
		int v, u, w;
		cin >> v >> u >> w;
		--v, --u;
		g[v].push_back({u, w, 1});
		g[u].push_back({v, w, 0});
	}
	cout << dfs(0) << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}