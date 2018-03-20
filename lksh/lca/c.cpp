// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (signed long long)n; i++)
#define each(i, v) for (auto i : v)

using ll = long long;
using pii = pair<int, int>;

const int MAXLOG = 25;

void print(){
    cout << '\n';
}


template<typename Arg1, typename... Args>
void print(const Arg1& a1, const Args&... args){
    cout << a1 << ' ';
    print(args...);
}


vector<vector<pii>> g;
vector<vector<int>> bin_up;
vector<vector<int>> min_up;
vector<int> tin;
vector<int> tout;
vector<int> level;
int timer = 0;


void add(pii a, int par){
    bin_up[a.first][0] = par;
    min_up[a.first][0] = a.second;
    // cerr << a.first << "!!!!!!!!!!!!!!!!!!!!!!\n";
    for (int i = 1; i <= MAXLOG; i++){
        min_up[a.first][i] = min(min_up[a.first][i - 1], min_up[bin_up[a.first][i - 1]][i - 1]);
        bin_up[a.first][i] = bin_up[bin_up[a.first][i - 1]][i - 1];
    }
    // cerr << a.first << "!!!!!!!!!!!" << '\n';
}


void dfs(int v, int d){
    // cerr << v << '\n';
    tin[v] = timer++;
    level[v] = d;
    for (pii u : g[v]){
        add(u, v);
        dfs(u.first, d + 1);
    }
    tout[v] = timer++; 
}


bool is_ans(int a, int b){
    return (tin[a] <= tin[b]) && (tout[a] >= tout[b]);
}


int lca(int a, int b){
    if (is_ans(a, b)) return a;
    for (int i = MAXLOG; i >= 0; i--){
        int v = bin_up[a][i];
        if (!is_ans(v, b)) a = v;
    }
    return bin_up[a][0];
}


int jump(int a, int k){
    int ans = INT_MAX;
    for (int i = 0; i <= MAXLOG; i++){
        if (k & (1 << i)){
            ans = min(ans, min_up[a][i]);
            a = bin_up[a][i];
        }
    }
    return ans;
}
int main(){
    freopen("minonpath.in", "r", stdin);
    freopen("minonpath.out", "w", stdout);
    int n;
    cin >> n;
    g.resize(n);
    tin.resize(n);
    tout.resize(n);
    level.resize(n);
    bin_up.assign(n, vector<int>(MAXLOG + 1));
    min_up.assign(n, vector<int>(MAXLOG + 1));
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back({i + 1, b});
        // cout << a - 1 << ' ' << i + 1 << '\n';
    }
    int m;
    cin >> m;
    dfs(0, 0);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        int l = lca(--x, --y);
        // cout << l << '\n';
        print(min(jump(x, level[x] - level[l]), jump(y, level[y] - level[l])));
    }
}
