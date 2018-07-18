#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXLOG = 5;
// const int MAXLOG_N = 10;
const int MAXN = 10;
#else
const int INF = 1e9; 
const int MAXLOG = 20;
// const int MAXLOG_N = 2e5;
const int MAXN = 2e5 + 1;
#endif

const pair<int, int> MAX = {INF, INF};


// -*-*-* All variables *-*-*-
int n, m, timer = 0, root;
int max_color = 1;
vector<int> g[MAXN], g1[MAXN];
pair<int, int> sparse[MAXLOG][MAXN];
pair<int, int> euler[2 * MAXN];
int tin[MAXN], dp[MAXN], colors[MAXN], used[MAXN], id[MAXN], depth[MAXN];
int point = 0;
// -*-*-* All functions *-*-*-
void init(){
    // for (int i = 2; i < MAXLOG_N; i++){
    //     logs[i] = logs[i / 2] + 1;
    // }
    memset(colors, 0, sizeof(int) * MAXN);
    memset(used, 0, sizeof(int) * MAXN);
    timer = 0;
    max_color = 1;
}
int dfs(int v, int p){
    tin[v] = dp[v] = timer++;
    used[v] = 1;
    for (int u : g[v]){
        if (u == p) continue;
        if (!used[u]){
            dp[v] = min(dp[v], dfs(u, v));
        }
        else{
            dp[v] = min(dp[v], tin[u]);
        }
    }
    return dp[v];
}
void paint(int v, int color){
    colors[v] = color;
    for (int u : g[v]){
        if (colors[u] != 0) continue;
        if (tin[v] < dp[u]){
            max_color++;
            paint(u, max_color);
        }
        else paint(u, color);
    }
}

void color_all(){
    memset(used, 0, sizeof(int) * MAXN);
    max_color = 1;
    for (int i = 0;i < n; i++){
        if (colors[i] == 0) {
            paint(i, max_color);
            max_color++;
        }
    }
}

void dfs_euler(int v, int d, int p = -1){
    id[v] = point;
    used[v] = 1;
    // cerr << v << '\n';
    euler[point++] = {d, v};
    // cerr << point << "point" << '\n';
    depth[v] = d;
    for (int u : g1[v]){
        if (u == p || used[u]) continue;
        dfs_euler(u, d + 1, v);
        euler[point++] = {d, v};
        // cerr << point << "point" << '\n';
    }
}

void build(){
    // cerr << "build\n";
    for (int i = 0;i < point; i++) sparse[0][i] = euler[i]; 
    for (int log = 1; log < MAXLOG; log++){
        for (int i = 0; i + (1 << (log - 1)) < (int)MAXN; i++){
            sparse[log][i] = min(sparse[log - 1][i], sparse[log - 1][i + (1 << (log - 1))]);
            // cerr << setw(5) << sparse[log][i].first << ", " << sparse[log][i].second << ' ';
        }
        // cerr << '\n';
    }
}

int get_min(int l, int r){
    if (l > r) swap(l, r);
    int len = r - l + 1;
    int power = (int)log2(len + 0.5);
    return min(sparse[power][l], sparse[power][r - (1 << power) + 1]).second;
}

int lca(int a, int b){
    return get_min(id[a], id[b]);
}

void solve(){
    init();
    cin >> root;
    root--;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) if (!used[i]) dfs(i, -1);
    color_all();
    for (int i = 0;i < n; i++){
        for (int u : g[i]){
            if (colors[i] == colors[u]) continue;
            // cerr << "from " << colors[i] << " to " << colors[u] << '\n';
            g1[colors[i]].push_back(colors[u]);
            g1[colors[u]].push_back(colors[i]);
        }
    }
    memset(used, 0, sizeof(int) * MAXN);
    dfs_euler(colors[root], 0);
    build();
    int t;
    cin >> t;
    // for (int i = 0;i < n; i++) cerr << colors[i] << ' ';
    // cerr << '\n';
    while (t--){
        
        int a, b;
        cin >> a >> b;
        a--, b--;
        a = colors[a];
        b = colors[b];
        // cerr << a << ' ' << b << '\n';
        // cerr << depth.size() << '\n';
        // cerr << lca(a, b) << '\n';
        cout << depth[lca(a, b)] << '\n';
    }
}
int main(){
    #ifdef LOCAL
    string taskName = "F";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n >> m){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}