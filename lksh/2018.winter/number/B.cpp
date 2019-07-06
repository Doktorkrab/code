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
using ll = int64_t;
ll a, b, n, m;

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

inline void solve(){
	int64_t kikos = 1;
	int64_t x, y;
	int64_t g = gcd(abs(n), abs(m), x, y);
	// cout << g << '\n';
	// cout << a << ' ' << b << ' ' << n << ' ' << m << '\n';
	if (kikos % g){
		cout << "NO\n";
		return;
	}
	cout << (x * n * a + y * m * b + n * m) % (n % m) << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> b >> n >> m)
        solve();

}