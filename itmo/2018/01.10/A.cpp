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

const int MAXN = 1e5 + 7;
int n, m;
pair<int, int> arr[MAXN];
int ans[MAXN];
pair<int, int> shelters[MAXN];

inline void init(){
	fill(shelters, shelters + MAXN, pair<int, int>());
	fill(ans, ans + MAXN, -1);
	fill(arr, arr + MAXN, pair<int, int>());
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> shelters[i].first;
		shelters[i].second = i;
	}

	sort(shelters, shelters + m);
	int r = 0;
	for (int i = 0; i < n; i++){
		while (r < m && shelters[r].first < arr[i].first)
			r++;
		// cerr << arr[i] << ' ' << r << '\n';
		if (r != 0 && (r == m || abs(shelters[r - 1].first - arr[i].first) < abs(shelters[r].first - arr[i].first)))
			ans[arr[i].second] = shelters[r - 1].second + 1;
		else
			ans[arr[i].second] = shelters[r].second + 1;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
		freopen("shelter.in", "r", stdin);
		freopen("shelter.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}