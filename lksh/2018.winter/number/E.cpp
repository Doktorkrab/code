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
const int MAXN = 5e6 + 5;
using ll = int64_t;
// #define int ll
int primes[MAXN], cnt = 0;
int d[MAXN];
int deg[MAXN];
int rest[MAXN];
ll prefix[MAXN + 1];
int l, r;

ll ans[MAXN];
inline void init(){
	memset(primes, 0, MAXN * sizeof(int));
	fill(ans, ans + MAXN, 0);
	memset(prefix, 0, MAXN * sizeof(ll));
	fill(d, d + MAXN, -1);
	cnt = 0;
}

inline void init1(){
	init();
	for (int i = 2; i < MAXN; i++){
		// cerr << d[i] << ' ';
		if (d[i] == -1){
			d[i] = cnt;
			primes[cnt++] = i;
		}
		// cerr << i << '\n';
		for (int j = 0; j <= d[i] && i * primes[j] < MAXN; j++){
			// cerr << i * primes[j] << ' ' << MAXN << '\n';
			d[i * primes[j]] = j;
		
		}
	}
	// cerr << '\n';
	prefix[2] = 1;
	ans[1] = 1;
	ans[0] = 0;
	// cerr << cnt << '\n';
	for (int i = 2; i < MAXN; i++){
		// cerr << i << ' ';
		// cerr << d[i] << '\n';
		int p = primes[d[i]];
		int y = i / p;
		deg[i] = (d[y] == d[i] ? deg[y] + 1: 1);
		rest[i] = (d[y] == d[i] ? rest[y] : y);
		int term = i / rest[i];
		ans[i] = ans[rest[i]] * 1LL * (1LL * term * p - 1) / (p - 1);
		prefix[i + 1] = prefix[i] + ans[i];
	}
}
void solve(){
	// cin >> l >> r;
	// cerr << l << ' ' << r << '\n';
	// cerr << prefix[r] << ' ' << prefix[l - 1] << '\n'; 
	// cerr << prefix[r] - prefix[l - 1] << '\n';
	cout << prefix[r + 1] - prefix[l] << '\n';
}

int32_t main(){
	#ifdef LOCAL
		// freopen("E.in", "r", stdin);
		// freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init1();
    while (cin >> l >> r)
        solve();

}