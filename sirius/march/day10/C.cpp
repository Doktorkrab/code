#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
 
const int MAXN = 3e4 + 7;
int n, k;
int arr[MAXN];
int cnt[MAXN];
int version[MAXN];
inline void init(){
 
}
 
inline void solve(){
    if (k == 1){
        cout << 1LL * (n + 1) * n / 2 << '\n';
        return;
    }
    int64_t ans = 0;
    int mx = -1, i, j;
    for (i = 0; i < n; i++){
        cin >> arr[i];
        mx = -1;
        for (j = i; j >= 0; j--){
            if (version[arr[j]] != i){
                version[arr[j]] = i;
                cnt[arr[j]] = 0;
            }
            cnt[arr[j]] += 2;
            if (mx == -1 || cnt[arr[j]] > cnt[mx])
                mx = arr[j];
            if (i - j + 1 < cnt[mx])
                ans++;
            if (cnt[mx] + 2 * j < i + 1)
                break;
        }
    }
    cout << ans << '\n';
 
}
 
 
int main(){
    #ifdef LOCAL
        freopen("C.in", "r", stdin);
        freopen("C.out", "w", stdout);
    #else
        freopen("prediction.in", "r", stdin);
        freopen("prediction.out", "w", stdout);
    #endif
     
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // while (cin >> n >> k)
    cin >> n >> k;
        solve();
 
}