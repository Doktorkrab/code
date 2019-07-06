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
#define int64_t uint64_t
int64_t n, b;

inline void init(){
}

inline void solve(){
	unordered_map<int64_t, int64_t> fact;
	int64_t old_n = n;
	for (int64_t f = 2; 1LL * f * f <= old_n; f++){
		while (n % f == 0){
			fact[f]++;
			n /= f;
		}
	}
	if (n > 1)
		fact[n]++;
	int64_t ans = LONG_LONG_MAX;
	for (auto i : fact){
		int64_t sum = 0;
		int power = 0;
		int64_t now = 1;
		while (now < b){
			now *= i.first;
			// cerr << now << '\n';
		}
		int64_t b1 = b;
		while (b1 > 0){
			sum += b1 / i.first;
			b1 /= i.first;
		}
		// cerr << i.first << ' ' << sum << '\n';
		ans = min(ans, sum / i.second);
	}
	cout << ans << '\n';
	// cerr << '\n';

}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> b >> n)
        solve();

}