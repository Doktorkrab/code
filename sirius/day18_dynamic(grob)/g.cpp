#include <bits/stdc++.h>


using namespace std;
using ll = long long;

struct Vertex{
    vector<ll> dp = {INT_MAX, INT_MAX, INT_MAX, INT_MAX}; // | 0, | 1, & 0, & 1 
    ll and_cost = INT_MAX;
    ll or_cost = INT_MAX;
};
vector<Vertex> g;
int n, v;
void dfs(int v){
    if (v * 2 > n) return;
    dfs(2 * v);
    dfs(2 * v + 1);
    ll zl = min(g[2 * v].dp[0], g[2 * v].dp[2]);
    ll zr = min(g[2 * v + 1].dp[0], g[2 * v + 1].dp[2]);
    ll ol = min(g[2 * v].dp[1], g[2 * v].dp[3]);
    ll _or = min(g[2 * v + 1].dp[1], g[2 * v + 1].dp[3]);
    // cout << "dfs " << v << ": " << zl << ' ' << zr << ' '<< ol << ' ' << or << '\n';
    // cout << g[v].and_cost << ' ' << g[v].or_cost << '\n';
    g[v].dp[0] = zl + zr + g[v].or_cost;
    g[v].dp[1] = min(ol + _or, min(ol + zr, zl + _or)) + g[v].or_cost;
    g[v].dp[2] = min(zl + zr, min(ol + zr, zl + _or)) + g[v].and_cost;
    g[v].dp[3] = ol + _or + g[v].and_cost;
}
void solve(){
    cin >> n >> v;
    g.resize(n + 1);
    for (int i = 1; i * 2 <= n;i++){
        int operation, can_change;
        cin >> operation >> can_change;
        if (operation) g[i].and_cost = 0;
        if (!operation) g[i].or_cost = 0;
        if (can_change){
            g[i].and_cost = min(1LL, g[i].and_cost);
            g[i].or_cost = min(1LL, g[i].or_cost);
        }
    }
    for (int i = n / 2 + 1; i <= n; i++){
        int val;
        cin >> val;
        if (val) 
            g[i].dp = {INT_MAX, 0, INT_MAX, 0};
        else 
            g[i].dp = {0, INT_MAX, 0, INT_MAX};
    }
    dfs(1);
    // cout << v << '\n';
    ll ans = min(g[1].dp[0 + v], g[1].dp[2 + v]);
    if (ans >= INT_MAX){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << ans << '\n';
    }
}

int main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
#endif
    while(t--){
#ifdef LOCAL
        clock_t t_elapsed = clock();
#endif
        solve();
#ifdef LOCAL
        cout << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }

}
