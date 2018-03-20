#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<vector<int>> g;
vector<int> used;
vector<int> dist;
int s, t;
bool dfs(int v){
    used[v] = 1;
    bool ans = 0;
    for (int u : g[v]){
        if (u == t) continue;
        if (used[u] == 1) {
            cout << v << ' ' << u << "!!!!!!!\n";
            return 1;
        }
        dist[u] = dist[v] + 1;
        ans |= dfs(u);
    }
    used[v] = 2;
    return ans;
}
int main(){
    int t;
    cin >> t;
    for (int test = 0; test < t; test++){
        int n, m;
        cin >> n >> m >> s >> t;
        --s;--t;
        g.assign(n, vector<int>());
        used.assign(n, 0);
        dist.assign(n, INF);
        dist[s] = 0;
        for (int i = 0;i < m;i++){
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        int kek = dfs(s);
        if (kek){
            cout << -1 << '\n';
            continue;
        }
        for (int u : g[t]) kek = max(kek, dist[u]);
        cout << kek + 1 << '\n';
    }
}