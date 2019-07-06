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
#include <climits>
using namespace std;
const int MAXN = 1e5;
int n = 100000, k = 66381;
pair<int, int> arr[MAXN];
int ans[MAXN];
inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
	memset(ans, -1, sizeof(int) * MAXN);
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++)
		arr[i].first = 3, arr[i].second = i;
	sort(arr, arr + n);
	reverse(arr, arr + n);
	int gr = 0;
	int cnt = 1;
	int i = 0;
	while (gr + n - i != k){
		ans[arr[i].second] = ans[arr[i + 1].second] = cnt++;
		i += 2;
		gr++;
	}
	for (; i < n; i++)
		ans[arr[i].second] = cnt++;
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];
	
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // while (cin >> n >> k)
    // cin >> n >> k;
        solve();

}