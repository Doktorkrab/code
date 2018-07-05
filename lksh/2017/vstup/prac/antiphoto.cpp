#include <bits/stdc++.h>
#define int long long
using namespace std;
 
using ll = long long;
 
 
void prep(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}
vector<vector<int>> g;
vector<vector<int>> d;
int n, k;
void dfs(int v, int p, int depth){ // distance between upper chosen vertex
    d[depth].push_back(v);
    for (int u : g[v]) if (u != p) dfs(u, v, depth + 1);
}
vector<int> lst;
void dfs1(int v, int p, int dist, int mx){
    if (lst[v] < dist) return;
    lst[v] = min(dist, lst[v]);
    if(dist == mx) return;
    for (int u : g[v]) if (u != p) dfs1(u, v, dist + 1, mx);
}
bool check(int m){
    int ans = 0;
    lst.assign(n, INT_MAX);
    for (int i = n - 1;i>=0;i--){
        for (int j : d[i]){
            if (lst[j] == INT_MAX || lst[j] == m){
                // lst[j] = 0;
                ans++;
                dfs1(j, -1, 0, m);

            }
        }
    }
    return ans >= k;
}
void run(){
    cin >> n >> k;
    g.assign(n, {});
    d.assign(n, {});
    for (int i = 1; i < n; i++){
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, -1, 0);
    for (int i = n;i > 0;i--){
        if (check(i)){
            cout << i << '\n';
            return;
        }
    }
 
}
 
signed main() {
    string FN = "photo-marathon";
   assert(freopen((FN + ".in").c_str(), "r", stdin));
   #ifndef LOCAL
   freopen((FN + ".out").c_str(), "w", stdout);
   #endif
 
 
    int t = 1;
    prep();
 
#ifdef LOCAL
    cin >> t;
#endif
    while (t--) run();
#ifdef LOCAL
    cerr << "Elapsed: " << (clock() * 1.) / CLOCKS_PER_SEC << '\n';
#endif
 
    return 0;
}