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

int64_t n, e, c;

inline void init(){

}

int64_t gcd(int64_t a, int64_t b, int64_t& x1, int64_t& y1){
	if (a == 0){
		x1 = 0;
		y1 = 1;
		return b;
	}
	int64_t x, y;
	int64_t g = gcd(b % a, a, x, y);
	x1 = y - (b / a) * x;
	y1 = x;
	return g;
}

inline int64_t inv(int64_t a, int64_t m){
	int64_t x, y;
	int64_t kikos = gcd(a, m, x, y);
	if (kikos != 1)
		return -1;
	else
		return (x % m + m) % m;
}
int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}


int64_t binpow (int64_t a, int64_t n, int64_t m) {
	int64_t res = 1;
	while (n) {
		if (n & 1){
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res;
}
inline void solve(){
	int64_t n1 = n;
	int64_t ph = phi(n);
	cerr << ph << ' ' << e << '\n';
	int64_t d = inv(e, ph);
	cerr << d << '\n';
	assert(d != -1);
	cout << binpow(c, d, n1) << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> e >> c)
        solve();

}