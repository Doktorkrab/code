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
int n, m;
vector<int> arr;
inline void init(){
    arr.resize(n);
}

const int MAXN = 14, MAXM = 101;
int dp[(1 << 14)][MAXN][MAXM];
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int mask = 0; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if (mask & (1 << i))
                continue;
            if (mask == 0){
                dp[mask | (1 << i)][i][0] = 1;
                continue;
            }
            for (int j = 0; j <= m; j++){
                for (int k = 0; k < n; k++){
                    if (!(mask & (1 << k)))
                        continue;
                    if (j + abs(arr[k] - arr[i]) > m)
                        continue;
                    dp[mask | (1 << i)][i][j + abs(arr[k] - arr[i])] += dp[mask][k][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++){
            cerr << dp[(1 << n) - 1][i][j] << " \n"[j == m];
            ans += dp[(1 << n) - 1][i][j];
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