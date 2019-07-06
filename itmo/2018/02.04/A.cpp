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

using ld = long double;

int64_t a, b, x;
inline void init(){

}

inline void solve(){
	int64_t dt = (a + b) - ((x / 1000 + a) % (a + b));
	int64_t t = x / 1000;
	cout << fixed << setprecision(20) << x / (t + dt) << '\n';

}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
		freopen("lights.in", "r", stdin);
		freopen("lights.out", "w", stdout);
	#endif	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> b >> x)
        solve();

}