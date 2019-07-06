#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

uint64_t n, a, b, c;

inline void init(){

}
void prn(__int128 a){
	string s;
	do{
		s += '0' + (int)(a % 10);
		a /= 10;
	} while (a > 0);
	reverse(s.begin(), s.end());
	cout << s;
}
inline void solve(){
	__int128 cnt = n / 3;
	__int128 ans = 0;
	__int128 aa = 0, bb = 0, cc = 0;
	for (__int128 A = max((__int128)0, cnt - 3000); A <= cnt + 3000; A++)
		for (__int128 B = max((__int128)0, cnt - 3000); B <= cnt + 3000; B++){
			if (n <= A + B)
				continue;
			uint64_t C = n - A - B;
			uint64_t tmp = (A / a) * (B / b) * (C / c);
			if (tmp > ans){
				ans = tmp;
				aa = A;
				bb = B;
				cc = C;
			}
		}
	// cerr << ans << '\n';
	// cerr << aa + bb + cc << '\n';
	prn(aa);
	cout << ' ';
	prn(bb);
	cout << ' ';
	prn(cc);
	cout << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
		freopen("sweets.in", "r", stdin);
		freopen("sweets.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> a >> b >> c)
        solve();

}