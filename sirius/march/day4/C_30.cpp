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
const int64_t INF = 1e18;
const int MAXN = 1e3 + 10;
int n;
int64_t dp[MAXN];
int64_t h[MAXN];
int w[MAXN];
inline void init(){
    memset(h, 0, sizeof(int64_t) * MAXN);
    memset(dp, 0, sizeof(int64_t) * MAXN);
    memset(w, 0, sizeof(int) * MAXN);
}
 
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    dp[0] = 0;
    // cerr << dp[0][0] << ' ' << dp[1][0] << '\n';
    cerr << dp[0] << '\n';
    for  (int i = 1; i < n; i++){
        dp[i] = INF;
        int64_t kek = 0;
        for (int j = i - 1; j >= 0; j--){
        	cerr << i << ' ' << j << ' '  << dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + kek << ' ' << kek << ' ' << (h[i] - h[j]) * (h[i] - h[j]) << '\n';
            dp[i] = min(dp[i], dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + kek);
            kek += w[j];
        }
        cerr << dp[i] << '\n';
        // cerr << dp[0][i] << ' ' << dp[1][i] << '\n';
    }
    cerr << '\n';
    cout << dp[n - 1];
}
 
 
int main(){
    #ifdef LOCAL
        freopen("C.in", "r", stdin);
        freopen("C.out", "w", stdout);
    #endif
     
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();
 
}