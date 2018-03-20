#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define ch(arr) arr.begin(),arr.end()
using ll = long long;
using ld = long double;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #ifndef LOCAL
        freopen("secure.in", "r", stdin);
        freopen("secure.out", "w", stdout);
    #endif
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        rep(tests, 3){
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> kek(n);
    vector<ll> d(n, INT_MAX);
    vector<int> gg(n, -1); 
    set<pair<int, int>> dji;
    rep(i, n) {
        cin >> kek[i];
        if (kek[i] == 1) {d[i] = 0, gg[i] = i;dji.insert({0, i});};
    }
    vector<vector<pair<int, int>>> g(n);


    rep(i, m){
        int v, u, c;
        cin >> v >> u >> c;
        g[--v].push_back({c, --u});
        g[u].push_back({c, v});
    }
    while (dji.size()){
        auto top = *dji.begin();
        //cout << top.first << ' ' << top.second << ' ' << d[top.second] << " debug!\n";
        dji.erase(dji.begin());
        for (auto u : g[top.second]){
            //cout << u.second << ' ' << d[u.second] << ' ' << d[top.second] + u.first << '\n';
            if (d[top.second] + u.first < d[u.second]){
                d[u.second] = d[top.second] + u.first;
                gg[u.second] = gg[top.second];
                dji.insert({u.first, u.second});
                //cout << u.second << '\n';
            }
        }
    }
    ll ans = INT_MAX + 239LL;
    ll ans_i = -1;
    rep(i, n){
        // cout << d[i] << ' ';
        if (kek[i] == 2 && ans > d[i] && d[i] < INT_MAX) {
            ans = d[i];
            ans_i = i;
        }
    }
    if (ans_i == -1) cout << -1 << '\n';
    else{
        cout << gg[ans_i] + 1 << ' ' << ans_i + 1 << ' ' << ans << '\n';
    }
    // cout << '\n';
}
#ifdef LOCAL
}
#endif