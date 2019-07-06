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
const int MAXN = 1e5 + 7;
int a[MAXN];
int b[MAXN];
inline void init(){
	memset(a, 0, sizeof(int) * MAXN);
	memset(b, 0, sizeof(int) * MAXN);
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	int s = 0;
	for (int i = n - 1; i >= 0; i--){
		int tmp = (a[i] + s) % b[i];
		if (tmp != 0)
		s += b[i] - tmp;
	}
	cout << s << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}