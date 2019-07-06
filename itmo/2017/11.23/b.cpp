#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> dist;
vector<int> used;
int maxv = 0, maxi = 0;
pair<int, int> dfs(int v){
    used[v] = 1;
    int ans = v, cnt = 1;
    for (int u : g[v]){
        if (u == v) continue;
        if (used[u] == 0){
            dist[u] = dist[v] + 1; 
            auto tmp = dfs(u);
            if (tmp.first > cnt){
                cnt = tmp.first;
                ans = tmp.second;
            }
        }
        if (used[u] == 1){
            int l = abs(dist[v] - dist[u]) + 1;
            if (l > cnt){
                cerr << "swapping in dfs " << l << ' ' << v << ' ' << dist[v] << ' ' << u << ' ' << dist[u] << '\n'; 
                cnt = l;
                if (dist[v] > dist[u]) ans = v;
                else ans = u;
            }
        }
        
    }
    used[v] = 2;
    return {cnt, ans};
}
int main(){
    freopen("doggy.in", "r", stdin);
    freopen("doggy.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dist.resize(n);
    used.resize(n);
    for (int i = 0;i < n;i++) dist[i] = 0;
    for (int i = 0;i < m;i++){
        int v,u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    pair<int, int> ans = {0, 0};
    vector<int> ans_v;
    for (int i = 0;i < n;i++){
            for (int j = 0;j < n;j++) dist[j] = used[j] = 0;
        if (used[i] != 0) continue;
        auto tmp = dfs(i);
        if (tmp <= ans) continue;
        ans = tmp;
        vector<int> tmp_v;
        int l = ans.first, v = ans.second;
        for (int gg : dist) cerr << gg << ' ';
        cerr << '\n';
        while(l){
            tmp_v.push_back(v);
            cerr << "now in: " << v + 1 << " with dist:" << dist[v] << " start in: " << ans.second + 1 << '\n';
            for (int u : g[v]){
                cerr << "checking: " << u + 1 << " with dist: " << dist[u] << '\n';
                if (dist[u] + 1 == dist[v]){
                    v = u;
                    break;
                }
            }
            --l;
        }
        swap(tmp_v, ans_v);
    }
    cout << ans.first << '\n';
    for (int i : ans_v) cout << i << ' ';
}