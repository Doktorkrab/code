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
#define int uint64_t
int a, b;

inline void init(){

}
inline void solve(){
	int ans = 0;
	for (int i = 1; i <= a; i++){
		int l = 0, r = 1e18;
		while (r - l > 1){
			int m = (l + r) / 2;
			int s = i * m;
			int one = s / 2;
			int two = s - one;
			// cerr << m << ' ' << s << ' ' << one << ' ' << two << ' ' << a << ' ' << b << '\n';
			if ((one <= a && two <= b) || (one <= b && two <= a))
				l = m;
			else
				r = m;
		}
		// cerr << i << ' ' << l << '\n';
		if (l < i)
			break;
		ans += l - i + 1;
	}
	cout << ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> b)
        solve();

}