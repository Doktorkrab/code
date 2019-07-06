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

using namespace std;


const int MAXN = 1e2 + 5;

int n;
string s;
char ans[MAXN];
set<int> g[MAXN];
pair<int, int> edges[(MAXN - 1) * MAXN / 2];
int used[MAXN];
vector<int> topsort;


inline void init(){
	fill(edges, edges + (MAXN - 1) * MAXN / 2, make_pair(-1, -1));
	fill(g, g + MAXN, (set<int>){});
	topsort.clear();
	memset(used, 0, sizeof(int) * MAXN);
	n = (int) s.size();
}
void dfs(int v){
	used[v] = 1;
	for (int u : g[v]){
		if (used[u])
			continue;
		dfs(u);
	}
	topsort.push_back(v);
}
inline void solve(){
	init();
	// cout << n * (n - 1) / 2 << endl;

	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (s[i] == s[j])
				continue;
			// cout << i + 1 << ' ' << j + 1 << endl;
			g[i].insert(j);
			g[j].insert(i);
			edges[cnt++] = {i, j};
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++){
		cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << endl;
	}
	for (int i = 0; i < cnt; i++){
		char c;
		cin >> c;
		if (c == '0')
			g[edges[i].second].erase(edges[i].first);
		else 
			g[edges[i].first].erase(edges[i].second);
	}
	for (int i = 0; i < n; i++){
		if (!used[i])
			dfs(i);
	}
	// reverse(topsort.begin(), topsort.end());
	for (int i = 0; i < n; i++){
		ans[i] = s[topsort[i]];
		// cout << topsort[i] << ' ' << s[i] << '\n';
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	cout << endl;
}


int main(){
	#ifdef LOCAL
		// freopen("I.in", "r", stdin);
		// freopen("I.out", "w", stdout);
	#endif
	
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();
}