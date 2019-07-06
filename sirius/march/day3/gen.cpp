#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(15);
vector<int> used;
set<pair<int, int>> gg;
int cnt = 0;
void dfs(int v){
	used[v] = 1;
	cnt++;
	for (int u : g[v]){
		if (!used[u])
			dfs(u);
	}
}
int main(){
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	while (1){
		gg.clear();
		cnt = 0;
		int n = 300;
		int m = (int)(rnd() % ((int) 3e4)) + 1;
		used.assign(n, 0);
		g.assign(n, {});
		int hh = 0;
		for (int i = 0; i < m; i++){
			int v = (rnd() % n);
			int u = (rnd() % n);
			int cnt = 0;
			while ((gg.count({min(v, u), max(v, u)}) || u == v) && cnt < (int)1e3){
				v = (rnd() % n);
				u = (rnd() % n);
				while (u == v) u = (rnd() % n);
				cnt++;
				// cerr << cnt << ' ' << hh << '\n';
			}
			if (cnt == (int)1e3)
				break;
			hh++;
			// cerr << min(v, u) << ' ' << max(v, u) << '\n'; 
			gg.insert({min(v, u), max(v, u)});
			g[v].push_back(u);
			g[u].push_back(v);
		}
		dfs(0);
		if (cnt != n)
			continue;
		cout << n << ' ' << hh << '\n';
		cout << (rnd() % n) + 1 << ' ' << (rnd() % n) + 1 << '\n';
		cout << (rnd() % n) + 1 << ' ' << (rnd() % n) + 1 << '\n';
		for (int i = 0; i < n; i++)
			for (int j : g[i])
				if (i < j)
					cout << i + 1 << ' ' << j + 1 << ' ' << rand() % 10 + 1 << '\n';
		break;
	}
}