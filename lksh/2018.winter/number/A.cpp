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

int64_t a, m;

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
inline void init(){

}

inline int solve(){
	int64_t x, y;
	int64_t kikos = gcd(a, m, x, y);
	if (kikos != 1)
		return -1;
	else
		return (x % m + m) % m;
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> m)
        solve();

}
