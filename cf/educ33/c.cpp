#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define ch(arr) arr.begin(),arr.end()
using ll = long long;
using ld = long double;
using namespace std;

vector<vector<int>> g;
vector<ll> w;
vector<bool> used;
ll dfs(int v){
    if (used[v]) return INT_MAX;
    used[v] = 1;
    ll min_ = w[v];
    for (int u : g[v]) min_ = min(min_, dfs(u));
    return min_;
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        rep(tests, 3){
    #endif
    int n, m;
    cin >> n >> m;
    g.clear();
    w.clear();
    used.clear();
    g.resize(n);
    w.resize(n);
    used.resize(n);
    rep(i, n) cin >> w[i];
    rep(i, m){
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    ll ans = 0;
    rep(i, n) if (!used[i]) ans += dfs(i);
    cout << ans << '\n';
}
#ifdef LOCAL
}
#endif