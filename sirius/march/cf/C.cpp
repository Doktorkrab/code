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
int n, k;
const int MAXN = 1e5 + 7;
const int64_t MOD = 1e9 + 7;
vector<pair<int, int>> g[MAXN];
int dp[MAXN];
int color[MAXN];
inline void init(){

}
int64_t pow1(int64_t a, int64_t b){
    int64_t res = 1;
    while (b){
        if (b & 1){
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}
int64_t ans = 0;
void dfs(int v, int p, int c){
    dp[c]++;
    color[v] = 1;
    for (auto u : g[v])
        if (u.second == 0 && u.first != p)
            dfs(u.first, v, c);
}
inline void solve(){
    for (int i = 0; i < n - 1; i++){
        int v, u, type;
        cin >> v >> u >> type;
        --v, --u;
        g[v].push_back({u, type});
        g[u].push_back({v, type});
    }
    int c = 1;
    for (int i = 0; i < n; i++){
        if (color[i] == 0)
            dfs(i, -1, c++);
    }
    ans = pow1(n, k);
    for (int i = 1; i < c; i++){
        ans = (ans + MOD - pow1(dp[i], k)) % MOD;
    }
    cout << ans << '\n';
}


int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
        solve();

}
