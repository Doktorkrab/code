#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, u, f, c;
    bool used;
};
vector<int> tmp;
vector<bool> used;
vector<Edge> edges;
vector<vector<pair<int, int>>> g; // edges v->u, u<-v

bool dfs(int v, int t){
    used[v] = 1;
    // cout << v << ' ' << t << '\n';
    if (v == t){
        tmp.push_back(t);
        return 1;
    }
    for (auto u : g[v]){
        Edge b = edges[u.first];
        // cout << b.v << ' ' << b.u << ' ' << b.f << ' ' << used[b.u] << '\n'; 
        if (used[b.u] || b.f == 1) continue;
        if (dfs(b.u, t)){
            edges[u.first].f = 1;
            tmp.push_back(v);
            return 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    string FN = "snails";
    freopen((FN + ".in").c_str(), "r", stdin);
    freopen((FN + ".out").c_str(), "w", stdout);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    used.assign(n, 0);
    g.resize(n);
    --s, --t;
    for(int i = 0;i < m;i++){
        int v, u, ind = edges.size();
        cin >> v >> u;
        --v, --u;
        g[v].push_back({ind, ind + 1});
        // g[u].push_back({ind + 1, ind});
        edges.push_back({v, u, 0, 1, 0});
        // edges.push_back({u, v, 0, 1, 1});
        // mx = max(mx, w);
    }
    used.assign(n, 0);
    vector<int> ans;
    if(!dfs(s, t)){
        cout << "NO\n";
        return 0;
    }
    used.assign(n, 0);
    ans = tmp;
    reverse(ans.begin(), ans.end());
    tmp.clear();
    if (!dfs(s, t)){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i : ans){
        cout << i + 1 << ' ';
    }
    cout << '\n';
    reverse(tmp.begin(), tmp.end());
    for (int i : tmp){
        cout << i + 1 << ' ';
    }
    cout << '\n';

}