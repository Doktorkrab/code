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

int n, k;
vector<vector<int>> shift = {
	/*      0  1  2  3  4  5  6  7  8  9 */
	/* 0 */{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/* 1 */{0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
	/* 2 */{0, 0, 0, 2, 3, 0, 0, 0, 0, 0},
	/* 3 */{0, 0, 2, 0, 2, 0, 0, 0, 0, 0},
	/* 4 */{0, 0, 3, 2, 0, 0, 0, 0, 0, 0},
	/* 5 */{0, 0, 0, 0, 0, 0, 2, 0, 0, 2},
	/* 6 */{0, 0, 0, 0, 0, 2, 0, 0, 0, 4},
	/* 7 */{0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
	/* 8 */{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/* 9 */{0, 0, 0, 0, 0, 2, 4, 0, 0, 0}};
inline void init(){

}

inline void solve(){
	int x;
	cin >> n >> k >> x;
	cerr << n << ' ' << k << ' ' << x << '\n';
	int ans = 1;
	for (int i = 1; i < 10; i++){
		if (shift[x][i] != 0 && shift[x][i] <= k)
			ans++;
	}
	cout << ans;
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // while (cin >> n >> k)
        solve();

}