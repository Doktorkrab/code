#include <bits/stdc++.h>
using namespace std;

vector<int> ans, ans1;
vector<int> cat;
vector<vector<int>> g;
int n, m;
void dfs(int v, int p, int up){
    ans[v] = max(up + cat[v], p != -1 ? ans[p] : 0);
    bool f = 0;
    for (int u : g[v]){
        if (u != p) {
            dfs(u, v, (cat[v] ? up + 1 : 0));
            f = 1;
        }
    }
    if (!f && ans[v] <= m) ans1[v] = 1;
}
int main(){
    cin >> n >> m;
    ans.resize(n);
    cat.resize(n);
    g.resize(n);
    ans1.resize(n);
    for (int& i : cat) cin >> i;
    vector<int> leafs;
    for (int i = 0;i < n - 1; i++){
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 1;i < n;i++){
        if (g[i].size() == 1) leafs.push_back(i);
    }
    dfs(0, -1, 0);
    int an = 0;
    for (int i : ans1) an += i;
    cout << an << '\n';
}