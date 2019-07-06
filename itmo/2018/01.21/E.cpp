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

const int MAXN = 5e3 + 10;
int n, m, k;
int p[MAXN], used[MAXN];
int run = 0;
vector<int> g[MAXN];
int dfs(int v){
	used[v] = run;
	for (int i : g[v]){
		if (p[i] == -1){
			p[i] = v;
			return 1;
		}
	}
	for (int i : g[v]){
		if (used[p[i]] != run && dfs(p[i])){
			p[i] = v;
			return 1;
		}
	}
	return 0;
}
inline void init(){
	memset(p, -1, sizeof(int) * MAXN);
	memset(used, -1, sizeof(int) * MAXN);
	for (int i = 0; i < MAXN; i++)
		g[i].clear();
	run = 0;
}
bool cmp(const vector<int>& a, const vector<int>& b){
	return a.size() > b.size();
}
inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		int cnt;
		cin >> cnt;
		g[i].resize(cnt);
		for (int j = 0; j < cnt; j++){
			cin >> g[i][j];
			g[i][j]--;
		}
	}
	sort(g, g + n, cmp);
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans += dfs(i);
		run++;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < g[i].size(); j++){
			if (p[g[i][j]] != -1){
				swap(g[i][j], g[i].back());
				g[i].pop_back();
				j--;
			}
		}
	}

	for (int i = 0; i < m; i++)
		cerr << p[i] + 1 << " \n"[i == m - 1];
	int ans1 = 0;
	memset(p, -1, sizeof(int) * MAXN);
	for (int i = 0; i < n && ans1 < k; i++){
		ans1 += dfs(i);
		run++;
	}
	for (int i = 0; i < m; i++)
		cerr << p[i] + 1 << " \n"[i == m - 1];
	cout << ans + ans1 << '\n';
	cerr << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> k)
        solve();

}