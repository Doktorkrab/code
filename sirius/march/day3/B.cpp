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
const int MAXN = 5e5 + 5;
pair<int, int> arr[MAXN];
int prefix[MAXN];
inline void init(){
	memset(arr, 0, sizeof(pair<int, int>) * MAXN);
	memset(prefix, 0, sizeof(int) * MAXN);
}
inline int get_sum(int l, int r){
	return prefix[r] - prefix[l];
}
inline void solve(){
	for (int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++){
		prefix[i + 1] = prefix[i] + arr[i].second;
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		int best = -1;
		int best_sum = 0;
		for (int j = i; j < n; j++){
			int tmp = get_sum(i, j + 1) - arr[j].first + arr[i].first;
			if (tmp > best_sum){
				best_sum = tmp;
				best = j;
			}
		}
		// cerr << i << ' ' << best << '\n';
		ans = max(ans, best_sum);
		while (i < best){
			ans = max(ans, get_sum(i, best + 1) - arr[best].first + arr[i].first);
			i++;
		}
	}
	cout << ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}