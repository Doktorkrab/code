#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)


using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui = unsigned int;
using namespace std;
using pii = pair<int, int>;


void print(ostream& st){
    st << '\n';
}


template <typename Arg, typename... Arg1>
void print(ostream& st, const Arg& a, const Arg1&... a1){
    st << a << ' ';
    print(st, a1...);
}


void input(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #endif
    #ifdef DEBUG
    freopen("kek.in", "r", stdin);
    freopen("kek.out", "w", stdout);
    #endif
}
//------------------------------------END_TEMPLATE---------------------------------------------------
vector<vector<int>> g;
map<pii, int> paint;
map<pii, int> first;
void dfs(int v, int p, int c){ // 0 - p->v, 1 - v -> p
    if (c == 0){
        paint[{min(v, p), max(v, p)}] = p == first[{min(v, p), max(v, p)}];
    }
    else{
        paint[{min(v, p), max(v, p)}] = v == first[{min(v, p), max(v, p)}];
    }
    for (int u : g[v]){
        if (u == p) continue;
        dfs(u, v, !c);
    }
}
int main(){
    int n;
    cin >> n;
    g.resize(n);
    vector<pii> edges;
    for (int i = 0;i < n - 1;i++){
        int v, u;
        cin >> v >> u;
        --v;--u;
        g[v].push_back(u);
        g[u].push_back(v);
        edges.push_back({min(v, u), max(v, u)});
        first[edges.back()] = v;
    }
    dfs(0, -1, 0);
    for (pii u : edges){
        cout << paint[u] << '\n';
    }
}