#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MAXN = 2 * 1e5;
const int MAXLOG = 25;
using ll = long long;
int tin[MAXN], tout[MAXN], up[MAXLOG][MAXN], timer = 0;
ll sums[MAXN];
vector<vector<pair<int, int>>> tree(MAXN);
void add(int v, int p){
    up[0][v] = p;
    for (int i = 1;i < MAXLOG;i++){
        up[i][v] = up[i-1][up[i - 1][v]];
    }
}
void dfs(int v, int p, ll sum){
    sums[v] = sum;
    tin[v] = timer++;
    for (auto u : tree[v]){
        if (u.f == p) continue;
        add(u.f, v);
        dfs(u.f, v, sum + u.s);
    }
    tout[v] = timer++;
}
bool is_anc(int a, int b){
    return (tin[a] <= tin[b]) && (tout[b] <= tout[a]);
}
int lca(int a, int b){
    if (is_anc(a, b)) return a;
    if (is_anc(b, a)) return b;
    for (int i = MAXLOG - 1;i >= 0;i--){
        int v = up[i][a];
        if (!is_anc(v, b)) a = v;
    }
    return up[0][a];
}
int main() {
    int n, m;
    cin >> n >> m;
    int r = 0;
    vector<vector<int>> id(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int i = 0; i < m; i++){
            2
        }
    }
    
    return 0;
}