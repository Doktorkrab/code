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
int arr[MAXN];
int dp[MAXN];
inline void init(){
    memset(arr, 0, sizeof(int) * MAXN);
    fill(dp, dp + MAXN, 0x3f3f3f3f);
}
 
inline void solve(){
    init();
    int mx = -1, mn = -1;
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        mx = mn = arr[i];
        dp[i + 1] = dp[i] + 1;
        for (int j = i - 1; j >= 0; j--){
            mx = max(arr[j], mx);
            if (mx != arr[i])
                break;
            mn = min(arr[j], mn);
            if (mn == arr[j])
                dp[i + 1] = min(dp[i + 1], dp[j] + 1);
        }
    }
    cout << dp[n] << '\n';
}
 
 
int main(){
    #ifdef LOCAL
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
    #endif
     
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();
 
}