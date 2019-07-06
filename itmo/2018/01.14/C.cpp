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

const int MAXN = 100;
const int MAXANS = 1e1 + 5;
int n, m;
int arr[MAXN];
int dp[MAXANS + 1];
int pos, good;
inline void init(){
	pos = -1;
	good = 1;
	memset(dp, 0, sizeof(int) * (MAXANS + 1));
	dp[0] = 2;
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		if (arr[i] == m)
			pos = i;
		else if (m % arr[i] == 0)
			good = 0;
	}
	if (!good){
		cout << "-1\n";
		return;
	}
	cerr << dp[0] << '\n';
	int ans = -1;
	for (int i = 1; i <= MAXANS; i++){
		for (int j = 0; j < n; j++){
			if (i >= arr[j] && dp[i - arr[j]] == 2 && arr[j] != m)
				dp[i] = 2;
		}
		for (int j = 0; j < n; j++){
			if (i >= arr[j] && dp[i - arr[j]] == 3 && arr[j] != m)
				dp[i] = 3;
		}

		if (i >= m){
			if (dp[i - m] == 1 || dp[i - m == 3])
				dp[i] = 3;
			if (dp[i - m] == 2 && dp[i] != 3)
				dp[i] = 1;
		}
		cerr << i << ' ' << dp[i] << '\n';
		if (dp[i] == 1){
			ans = i;
		}
	}
	cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}