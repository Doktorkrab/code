#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
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
// #define int int64_t
using ld = long double;
// #define double ld
const int MAXN = 1e3;
int n;
pair<int, int> arr[MAXN];
int p[MAXN];
int sz[MAXN];

inline void init(){
	fill(arr, arr + MAXN, pair<int, int>());
}
inline double len(pair<int, int> a, pair<int, int> b){
	return sqrt(1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second));
}
int get(int v){
	if (p[v] == v)
		return v;
	return p[v] = get(p[v]);
}

void un(int a, int b){
	a = get(a);
	b = get(b);
	if (sz[a] > sz[b])
		swap(a, b);
	p[a] = b;
	sz[b] += sz[a];
}
inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		arr[i] = {x, y};
	}
	double l = 0, r = 1e9;
	for (int cnt = 0; cnt < 75; cnt++){
		double m = (l + r) / 2;
		for (int i = 0; i < n; i++){
			p[i] = i;
			sz[i] = 1;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (len(arr[i], arr[j]) < m){
					un(i, j);
				}
			}
		}
		double minLen = INT_MAX;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (get(i) == get(j))
					continue;
				// cerr << i << ' ' << j << '\n';
				minLen = min(minLen, len(arr[i], arr[j]));
			}
		}
		// cerr << minLen << '\n';
		if (fabs(minLen - INT_MAX) < 1e-8 || minLen < m)
			r = m;
		else
			l = m;
	}
	cout << fixed << setprecision(20) << l << '\n';

}


int32_t main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}