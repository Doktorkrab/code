#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXN = 5;
const int MOD = 1e9 + 7;
#else
const int INF = 1e9;
const int MAXN = 50; 
const int MOD = 1e9 + 7;
#endif

// -*-*-* All variables *-*-*-
vector<int> arr(MAXN);
map<vector<int>, int64_t> dp;
int n;



// -*-*-* All functions *-*-*-
void init(){
    dp[vector<int>(n, 0)] = 1;
    arr.assign(n, 0);
}

int64_t lazy(vector<int>& key){
    // for (int i : key) cerr << i << ' ';
    // cerr << '\n'; 
    if (dp.count(key)) return dp[key];
    int64_t ans = 0;
    for (int i = 0; i < n; i++){
        if (key[i] <= 0) continue;
        // cerr << i << ' ' << key[i] << '\n';
        if (i != n - 1 && key[i] - 1 < key[i + 1]) continue;
        key[i]--;
        ans += lazy(key);
        ans %= MOD;
        key[i]++;
    }
    return dp[key] = ans;
}
void solve(){
    cin >> n;
    init();
    for (int& i : arr) cin >> i;
    cout << lazy(arr) << '\n';
}
int main(){
    #ifdef LOCAL
    string taskName = "D";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
    #endif
    while(t--){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}