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
#define int uint64_t
using namespace std;

int n;
int ans;
inline void init(){
	ans = 1;
}
uint64_t pow(int a, int b){
	int ret  = 1;
	for (int i = 0; i < b; i++) ret *= a;
	return ret;
}
inline void solve(){
	init();
	unordered_map<int, int> div;
	int newn = n;
	for (int f = 2; f * f <= newn; f++){
		while (n % f == 0){
			// cerr << f << '\n';
			div[f]++;
			n /= f;
		}
	}
	// cerr << "\t" << n << '\n';
	if (n > 1)
		div[n]++;
	for (auto i : div){
		// cerr << i.first << ' ' << i.second % 3 << '\n';
		if (i.second % 3 != 0)
			ans *= pow(i.first, 3 - (i.second % 3));
	}
	// if (ans == 1)
	// 	ans = 0;
	cout << ans << '\n';
	// cerr << '\n';
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
    while (cin >> n)
        solve();

}