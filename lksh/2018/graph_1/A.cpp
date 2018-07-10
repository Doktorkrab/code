#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXN = 10;
#else
const int INF = 1e9; 
const int MAXN = 1e5;
#endif
struct Edge{
    int v, u, e;
};
// -*-*-* All variables *-*-*-
vector<vector<int>> g;
vector<Edge> ans;
vector<Edge> edges;
vector<bool> banned;
vector<int> id;
int n, s;
// -*-*-* All functions *-*-*-
void init(){
    g.clear();
    banned.clear();
    edges.clear();
}

void dfs(int v){
    while (g[v].size() != 0){
        auto tmp = g[v].back();
        g[v].pop_back();
        if (banned[tmp]) continue;
        banned[tmp] = 1;
        int nxt = edges[tmp].v ^ edges[tmp].u ^ v;
        dfs(nxt);
        // if (tmp < 2 * n || v < 2 * n)
        ans.push_back(edges[tmp]);
    }
}

void solve(){
    init();
    cin >> n >> s;
    g.resize(2 * n + 2);
    for (int i = 0;i < s;i++){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(edges.size());
        g[n + y].push_back(edges.size());
        edges.push_back({x, n + y, i});
        banned.push_back(0);
    }
    for (int i = 0; i < n; i++){
        if (g[i].size() & 1) {
            g[i].push_back(edges.size());
            g[2 * n].push_back(edges.size()); 
            edges.push_back({i, 2 * n, -1});
            banned.push_back(0);       
        }
    }
    for (int i = 0; i < n; i++){
        if (g[i + n].size() & 1) {
            g[i + n].push_back(edges.size());
            g[2 * n + 1].push_back(edges.size());
            edges.push_back({n + i, 2 * n + 1, -1});
            banned.push_back(0);  
        }
    }
    if (g[2 * n].size() & 1 && g[2 * n + 1].size() & 1) {
        g[2 * n].push_back(edges.size());
        g[2 * n + 1].push_back(edges.size());
        edges.push_back({2 * n, 2 * n + 1, -1});
        banned.push_back(0);  
    }
    for (int i = 0; i < 2 * n + 2; i++){
        dfs(i);
    }
    int color = 0;
    reverse(ans.begin(), ans.end());
    vector<int> ans1(s);
    for (auto i : ans){
        color ^= 1;
        if (i.e == -1) continue;
        // cerr << i.v << ' ' << i.u << ' ' << i.e<< ' '<< color << '\n';
        if (i.v >= n) i.v -= n;
        if (i.v >= n) i.u -= n;
        ans1[i.e] = color;
    }
    string ans = "MW";
    for (int i = 0; i < s; i++){
        // cerr << i.first << ' ' << i.second << '\n';
        cout << ans[ans1[i]];
    }
    cout << '\n';

}
int main(){
    #ifdef LOCAL
    string taskName = "A";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
    #endif
    while(t--){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}