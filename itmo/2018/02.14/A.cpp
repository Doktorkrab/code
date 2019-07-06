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
int n;
int c = 0;
int o = 0;
int w = 0;
inline void init(){
	c = o = w = 0;
}

inline void solve(){

	for (int i = 0; i < n; i++){
		char x;
		cin >> x;
		// cerr << c << ' ' << o << ' ' << w << '\n';
		if (x == 'C')
			c++;
		if (x == 'O')
			o += c;
		if (x == 'W')
			w += o;
	}
	cout << w << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}