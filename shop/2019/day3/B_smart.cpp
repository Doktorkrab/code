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

#define int int64_t
using namespace std;
int n;
const int MAXN = 1e6 + 7;
const int MOD = 1e9;
// int power2[MAXN];
int dp[MAXN];
int pairs[MAXN];

inline void init(){
    // power2[0] = 1;
    // for (int i = 1; i < MAXN; i++)
    //     power2[i] = (power2[i - 1] * 2) % MOD;
}
int power2(int b){
    int ans = 1;
    int a = 2;
    while (b > 0){
        if (b & 1){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}
inline void solve(){
    init();
    dp[1] = 1;
    // int cnt = n - 1;
    cout << "{0, 1,";
    // cout << ""
    for (int i = 2; i <= n; i++){
        int sum = 0;
        int cnt = 0;
        for (int j = i - 1; j >= 1; j--){
            if (__gcd(i, j) == 1)
                pairs[j]++;

            // cerr << i << ' ' << j << ' ' << dp[j] * power2[cnt] % MOD << '\n';
            sum += dp[j] * power2(cnt) % MOD;
            sum %= MOD;
            cnt += pairs[j];
            cnt %= MOD;
            // cerr << sum << '\n';
        }
        // cerr << '\t' << i << ' ' << power2[cnt] << ' ' << sum << '\n';
        dp[i] = (power2(cnt) + MOD - sum) % MOD;
        cout << dp[i] << ", ";
    }
    cout << "};\n";
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