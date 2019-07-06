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
const int MAXN = 2e5;
int n;
int arr[MAXN];
const int mod = 4066273;
int bp(int a, int b, int m){
	int res = 1;
	while (b > 0){
		if (b & 1)
			res *= a;
		a *= a;
		res %= m;
		a %= m;
		b /= 2;
	}
	return res;
}

inline void init(){
	for (int i = 0;  i < n; i++)
		cin >> arr[i];
}

inline void solve(){
	init();
	int ans = arr[0] * n;
	int g = 5;
	int r = g;
	for (int i = 1; i < n; i++){
		int add = bp(r, n, mod) - 1;
		add = add * bp(r - 1, mod - 2, mod) % mod;
		ans = (ans + add * arr[i] % mod)  % mod;
		r = (r * g) % mod;
	}
	cout << ans << '\n';
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