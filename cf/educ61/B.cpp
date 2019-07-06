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

const int MAXN = 3e5 + 7;
int n;
int64_t arr[MAXN];
inline void init(){
	memset(arr, 0, sizeof(int64_t) * MAXN);
}

inline void solve(){
	init();
	int64_t sum = 0;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	int m;
	cin >> m;

	for (int i = 0; i < m; i++){
		int x;
		cin  >> x;
		cout << sum - arr[n - x] << '\n';
	}

}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}