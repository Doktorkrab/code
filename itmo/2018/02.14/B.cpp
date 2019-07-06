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
const int MAXN = 755;
const int64_t MOD = 1e9 + 7;
int n, m, k;
int arr[MAXN][MAXN];
int64_t dp[MAXN][MAXN];
inline void init(){

}

inline void solve(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	dp[0][0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (i == 0 && j == 0)
				continue;
			for (int a = 0; a < i; a++)
				for (int b = 0; b < j; b++)
					if (arr[i][j] != arr[a][b])
						dp[i][j] = (dp[i][j] + dp[a][b]) % MOD;
		}
	cout << dp[n - 1][m - 1] << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> k)
        solve();

}