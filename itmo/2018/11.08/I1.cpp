#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

vector<vector<int>> g;
vector<vector<int>> bin_up;
vector<int> tin, tout, level;
int timer = 0;
const int MAXLOG = 25;
// -*-*-* All functions *-*-*-
void add(int a, int par){
    bin_up[a][0] = par;
    for (int i = 1; i < MAXLOG; i++){
        bin_up[a][i] = bin_up[bin_up[a][i - 1]][i - 1];
    }
}
void calc(int v, int d, int p = -1){
    tin[v] = timer++;
    level[v] = d;
    for (auto u : g[v]){
        if (u == p) continue;
        add(u, v);
        calc(u, d + 1, v);
    }
    tout[v] = timer++;
}

bool is_anc(int a, int b){
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b){
    if (is_anc(a, b)) return a;
    for (int i = MAXLOG - 1; i >= 0; i--){
        int v = bin_up[a][i];
        if (!is_anc(v, b)) a = v;
    }
    return a;
}
int main(){
    int n, m;
    cin >> n;
    g.resize(n);
    tin.resize(n);
    tout.resize(n);
    level.resize(n);
    bin_up.assign(n, vector<int>(MAXLOG + 1));
    vector<pair<int, int>> edges(n - 1);
    for (int i = 1; i < n; i++){
        int v, u;
        cin >> v >> u;
        edges[i - 1] = {--v, --u};
        g[v].push_back(u);
        g[u].push_back(v);

    }
    calc(0, 0, 0);
    cin >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
//        cout << bin_up[a][0] + 1 << '\n';
        if (!is_anc(a, b)) cout << bin_up[a][0] + 1 << '\n';
        else cout << lca(b, a) + 1 << '\n';
    }
}