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
// #define int int64_t

const int OPEN = 1, CLOSE = -1;
const int MAXN = 2e5 + 7;
const int64_t MOD = 998244353;

int n;
pair<int, int> arr[MAXN];
int events[MAXN];
bool haveOpen[MAXN];
inline void init(){
	fill(arr, arr + MAXN, pair<int, int>());
	memset(events, 0, sizeof(int) * MAXN);
	memset(haveOpen, 0, sizeof(bool) * MAXN);

}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++){
		int j = i;
		while (j + 1 < n && arr[j].first == arr[j + 1].first) j++;
		if (i == j)
			continue;
		events[arr[i].second]++;
		haveOpen[arr[i].second] = 1;
		if (arr[j].second + 1 < n){
			events[arr[j].second + 1]--;
		}
		i = j;
	}
	int up = 0;
	int64_t ans = 1;
	for (int i = 0; i < n; i++){
		// cerr << events[i] << ' ';
		up += events[i];
		if (haveOpen[i] && i > 0 && up == 1){
			ans *= 2;
			ans %= MOD;
		}
		if (up == 0 && i > 0){
			ans <<= 1;
			ans %= MOD;
		}
	}
	cout << ans << '\n';
	cerr << '\n';

}


int32_t main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
    // cin >> n;
        solve();

}