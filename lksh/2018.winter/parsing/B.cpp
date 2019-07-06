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
int n;
string abc;
unordered_map<int, int> to_replace;
vector<vector<int>> g;
vector<vector<vector<int>>> g_trans;
vector<int> dist;
vector<int> is_terminal;
vector<vector<int>> usedMinimize;
inline void init(){
	is_terminal.resize(n, 0);
	g.resize(n, vector<int>(abc.size()));
	g_trans.resize(n, vector<vector<int>>(abc.size()));
	dist.resize(n, 1e9);
	usedMinimize.assign(n, vector<int>(n));
}

void bfs(int start){
	dist[start] = 0;
	vector<int> used(n);
	deque<int> q = {start};
	while (!q.empty()){
		int top = q.front();
		q.pop_front();
		if (used[top])
			continue;
		used[top] = 1;
		for (int u : g[top]){
			if (dist[u] > dist[top] + 1){
				dist[u] = dist[top] + 1;
				q.push_back(u);
			}
		}
	}
}

void minimize(){
	deque<pair<int, int>> q;
	for (int i = 0; i < n; i++){
		if (!is_terminal[i] || dist[i] == 1e9)
			continue;
		for (int j = 0; j < n; j++){
			if (i == j || is_terminal[j] || dist[j] == 1e9)
				continue;
			q.push_back({i, j});
			// cerr << i << ' ' << j << '\n';
		}
	}
	while (!q.empty()){
		auto top = q.front();
		q.pop_front();
		if (usedMinimize[top.first][top.second] || usedMinimize[top.second][top.first])
			continue;
		usedMinimize[top.first][top.second] = usedMinimize[top.second][top.first] = 1;
		for (int i = 0; i < (int) abc.size(); i++){ 
			for (auto v : g_trans[top.first][i])
				for (auto u : g_trans[top.second][i]){
					if (usedMinimize[v][u] || usedMinimize[u][v])
						continue;
					q.push_back({v, u});
				}
		}
	}
}
inline void solve(){
	init();
	int start;
	cin >> start;
	--start;
	int t;
	cin >> t;
	// cerr << t << '\n';
	for (int i = 0; i < t; i++){
		int x;
		cin >> x;
		is_terminal[x - 1] = 1;
		// cerr << x - 1 << ' ' << ' ';
	}
	// cerr << '\n';
	for (int i = 0; i < n; i++){
		to_replace[i] = i;
		for (int j = 0; j < (int) abc.size(); j++){
			int x;
			cin >> x;
			--x;
			g[i][j] = x;
			g_trans[x][j].push_back(i);
		}
	}

	bfs(start);
	minimize();
	vector<int> used(n, -1);
	int cnt = 0;
	vector<int> terminals;
	vector<int> used1(n);
	for (int i = 0; i < n; i++){
		if (used1[i] || dist[i] == 1e9)
			continue;
		used[i] = cnt++;
		for (int j = 0; j < n; j++){
			if (i == j || usedMinimize[i][j] || dist[j] == 1e9)
				continue;
			used1[j] = 1;
			used[j] = used[i];
		}
		if (is_terminal[i])
			terminals.push_back(used[i] + 1);
	}

	cout << cnt << '\n';
	cout << used[start] + 1 << ' ' << terminals.size() << ' ';
	for (int i : terminals)
		cout << i << ' ';
	cout << '\n';

	for (int i = 0; i < n; i++){
		if (used1[i] || dist[i] == 1e9)
			continue;
		// cerr << i << '\n';
		for (int u : g[i])
			cout << used[u] + 1 << ' ';
		cout << '\n';
	}

	// for (int i : is_terminal)
	// 	cout << i << ' ' ;
	// cout << "\n\n";
	// for (int i : dist)
	// 	cout << i << ' ' ;
	// cout << "\n\n";
	// for (int i : used)
	// 	cout << i << ' ' ;
	// cout << "\n\n";
	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < n; j++)
	// 		cout << usedMinimize[i][j] << ' ';
	// 	cout << '\n';
	// }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #ifdef LOCAL
    	freopen("B.in", "r", stdin);
    	freopen("B.out", "w", stdout);
	#endif

    while (cin >> abc >> n)
        solve();

}