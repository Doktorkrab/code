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

int n, m;
const int MAXN = 5e5 + 10;
vector<int> g[MAXN];
vector<int> g_trans[MAXN];
int used[MAXN], cnt;
int parent[MAXN];
bool root[MAXN];
vector<int> stack;
inline void init(){
	stack.clear();
	cnt = 0;
	memset(used, 0, MAXN * sizeof(int));
	memset(root, 0, MAXN * sizeof(bool));
	memset(parent, -1, MAXN * sizeof(int));
	for (int i = 0; i < MAXN; i++)
		g[i].clear();
}

bool find_cycle(int v){
	used[v] = 1;
	for (int u : g[v]){
		if (used[u] == 1)
			return 1;
		if (used[u] == 2)
			continue;
		if (find_cycle(u))
			return 1;
	}
	used[v] = 2;
	return 0;
}

void check_connectivy(int v){
	used[v] = 1;
	for (int u : g[v]){
		if (used[u])
			continue;
		check_connectivy(u);
	}
}
void topsort(int v){
	used[v] = 1;
	for (int u : g[v]){
		if (used[u])
			continue;
		topsort(u);
	}
	stack.push_back(v);
}

inline void solve(){
	init();
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		--v, --u;
		root[u] = 1;
		// cerr << v << ' ' << u << '\n';
		g[v].push_back(u);
		g_trans[u].push_back(v);
	}
	for (int i = 0; i < n; i++){
		if (used[i] == 0 && find_cycle(i)){
			cout << "No\n";
			return;
		}
	}
	memset(used, 0, sizeof(int) * MAXN);
	int rt = -1;
	for (int i = 0; i < n; i++){
		// cerr !<< 
		if (!root[i]){
			rt = i;
			break;
		}
	}
	assert(rt != -1);
	check_connectivy(rt);
	int tmp = 0;
	for (int i = 0; i < n; i++)
		if (used[i])
			tmp++;
	if (tmp != n){
		cout << "No\n";
		return;
	}
	memset(used, 0, sizeof(int) * MAXN);
	topsort(rt);
	// reverse(stack.begin(), stack.end());
	memset(used, 0, sizeof(int) * MAXN);
	for (int i = 0; i < n; i++){
		int v = stack[i];
		used[v] = 1;
		for (int u : g[v]){
			if (used[v] && parent[u] == -1){
				parent[u] = v + 1;
			}
			else if (!used[v]){
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
	for (int i = 0; i < n; i++)
		cout << parent[i] << " \n"[i == n - 1];


}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}