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

int n, k;
const int MAXN = 1e4 + 7;
int arr[MAXN];
int g[MAXN];
int sz[MAXN];
int p[MAXN];
int used[MAXN];
int pnt[MAXN];
inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
	memset(used, 0, sizeof(int) * MAXN);
	memset(g, 0, sizeof(int) * MAXN);
	for (int i = 0; i < MAXN; i++){
		sz[i] = 1;
		p[i] = i;
	}
}
int find_set(int a){
	if (p[a] == a)
		return a;
	return p[a] = find_set(p[a]);
}
inline void un(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if (a == b)
		return;
	if (sz[a] > sz[b])
		swap(a, b);
	p[a] = b;
	sz[b] += sz[a];
}
inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		arr[i]--;
	}
	for (int i = 0; i < n; i++){
		un(i, arr[i]);
		g[arr[i]] = i;
	}
	if (k == 0){
		for (int i = 0; i < n; i++)
			cout << i + 1 << " \n"[i == n - 1];
		return;
	}
	// --k;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cerr << find_set(p[i]) << " \n"[i == n - 1];
	for (int i = 0; i < n; i++){
		if (used[find_set(i)]){
			cerr << i << ' ' << find_set(i) << ' ' << pnt[find_set(i)] + 1 << ' ' << arr[pnt[find_set(i)]] << '\n';
			cout << pnt[find_set(i)] + 1 << ' ';
			cnt++;
			pnt[find_set(i)] = g[pnt[find_set(i)]];
			continue;
		}
		int shift = k % sz[find_set(i)];
		cerr << sz[find_set(i)] << ' ' << shift << '\n';
		int now = arr[i];
		cerr << now << ' ' << i << '\n';
		for (; shift > 1; shift--){
			now = arr[now];
		}
		cerr << now << '\n';
		pnt[find_set(i)] = now;
		cout << pnt[find_set(i)] + 1 << ' ';
		cnt++;
		pnt[find_set(i)] = g[pnt[find_set(i)]];	
		used[find_set(i)] = 1;
	}
	if (cnt != n)
		assert(0);
	cout << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k)
        solve();

} 