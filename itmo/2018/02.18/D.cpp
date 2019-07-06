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
const int MAXN = 2e5;
vector<int> g[MAXN];
long double have[MAXN];
int sz[MAXN];
inline void init(){
	for (int i = 0; i < n; i++)
		g[i].clear();
	memset(have, 0, sizeof(long double) * MAXN);
	fill(sz, sz + MAXN, 1);
}

void dfs(int v){
	
	for (int u : g[v]){

	}
}
inline void solve(){
	init();
	for (int i = 1; i < n; i++){
		int x;
		cin >> x;
		--x;
		g[x].push_back(i);
	}
	for (int i = 0; i < n; i++){
		cin >> have[i];
	}


}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}