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
#define int int64_t
const int64_t INF = 1e18;
const int MAXN = 1e6 + 10;
int n;
int64_t dp[MAXN];
int64_t h[MAXN];
int w_prefix[MAXN];
struct Line{
	int64_t k, b;
	Line() : k(0), b((int)1e12) {}
	Line(int64_t k, int64_t b) : k(k), b(b) {}
	int64_t value(int64_t x){
		return k * x + b;
	}
};
Line st[4 * MAXN];
void add(Line nw, int v = 1, int l = 0, int r = MAXN){
	int m = (l + r) / 2;
	bool mid = nw.value(m) < st[v].value(m);
	bool lft = nw.value(l) < st[v].value(l);
	// cerr << nw.k << ' ' << nw.b << ' ' << st[v].k << ' ' << st[v].b << '\n';
	if (mid)
		swap(st[v], nw);
	if (r - l == 1)
		return;
	if (lft != mid)
		add(nw, v * 2, l, m);
	else
		add(nw, v * 2 + 1, m, r);
}

int64_t get_val(int x, int v = 1, int l = 0, int r = MAXN){
	int m = (l + r) / 2;
	if (r - l == 1)
		return st[v].value(x);
	if (x < m)
		return min(st[v].value(x), get_val(x, v * 2, l, m));
	else
		return min(st[v].value(x), get_val(x, v * 2 + 1, m, r));
}

inline void init(){
	memset(h, 0, sizeof(int64_t) * MAXN);
	memset(dp, 0, sizeof(int64_t) * MAXN);
	memset(w_prefix, 0, sizeof(int) * MAXN);
	fill(st, st + (4 * MAXN), Line());
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (i == 0 || i == n - 1)
			x = 0;
		w_prefix[i + 1] = w_prefix[i] + x;
	}
	dp[0] = 0;
	add({-2 * h[0], h[0] * h[0] + w_prefix[1]});
	for  (int i = 1; i < n; i++){
		dp[i] = get_val(h[i]) + h[i] * h[i] + w_prefix[i];
		add({-2 * h[i], dp[i] + h[i] * h[i] - w_prefix[i + 1]});
	}
	cout << dp[n - 1];
}


int32_t main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}