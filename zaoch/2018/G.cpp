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

const int MAXN = 1e4;

int n, m;
bitset<MAXN + 1> used[MAXN];
int p[MAXN], sz[MAXN];
int arr[MAXN];
int dp[MAXN];
int prefix[MAXN];
int prefix1[MAXN];
int get_parent(int v){
	if (p[v] == v){
		return v;
	}
	return p[v] = get_parent(p[v]);
}

void un(int a, int b){
	a = get_parent(a);
	b = get_parent(b);
	if (sz[a] > sz[b])
		swap(a, b);
	sz[b] += sz[a];
	p[a] = b;
	used[b] |= used[a];  
}
inline void init(){
	for (int i = 0; i < n; i++){
		p[i] = i;
		sz[i] = 1;
		used[i] = bitset<MAXN + 1>();
		dp[i] = 0;
		prefix[i] = 0;
	}
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		used[i].set(arr[i]);
	}
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		--a, --b;
		un(a, b);
	}
	for (int i = 0; i < n; i++){
		int st = get_parent(i);
		// cerr << st << '\n';
		for (int j = 1; j <= n; j++){
			// cerr << used[st][j];
			if (used[st][j]){
				// cerr << i << ' ' << j << ' ' << prefix[j - 1] + 1 << ' ' << prefix1[j] << '\n';
				prefix1[j] = max(prefix1[j], prefix[j - 1] + 1);
				dp[i] = max(dp[i], prefix[j - 1] + 1);
			}
		}
		// cerr << '\n';
		for (int j = 1; j <= n; j++){
			prefix[j] = max(prefix1[j], max(prefix[j - 1], prefix[j]));
			prefix1[j] = 0;
			// cerr << prefix[j] << ' ';
		}
		// cerr << '\n';
		// cout << dp[i] << '\n';
	}
	int mx = 0;
	for (int i = 0; i < n; i++)
		mx = max(mx, dp[i]);
	cout << mx << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("G.in", "r", stdin);
		freopen("G.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}