#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
vector<vector<int>> g;
vector<int> matching;
vector<int> used;
vector<pair<int, int>> weight;
const int NO_MATCHING = -INF;
int n, iteration = 0;
// -*-*-* All functions *-*-*-
void init(){
    g.clear();
    matching.clear();
    used.clear();
}
int dfs(int v){
    if (used[v] == iteration) return 0;
    used[v] = iteration;
    for (int u : g[v]){
        if (matching[u] == NO_MATCHING){
            matching[u] = v;
            return 1;
        }
    }
    for (int u : g[v]){
        if (dfs(matching[u])){
            matching[u] = v;
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin >> n;
    g.resize(n);
    matching.assign(n, NO_MATCHING);
    used.assign(n, -1);
    weight.resize(n);
    for (int i = 0; i < n; i++){
        int w;
        cin >> w;
        weight[i] = {w, i};
    }
    for (int i = 0; i < n; i++){
        int cnt;
        cin >> cnt;
        while(cnt--){
            int tmp;
            cin >> tmp;
            g[i].push_back(tmp - 1);
        }
    }
    sort(weight.rbegin(), weight.rend());
    int ans = 0;
    for (int i = 0; i < n; i++){
        // cerr << weight[i].second << '\n';
        if (dfs(weight[i].second)){
            // for (int h : matching) cerr << h << ' ';
            // cerr << '\n';
            ans++;
            iteration++;
        }
    }
    vector<int> ans1(n, 0);
    for (int i = 0; i < n; i++){
        // cerr << matching[i] << '\n';
        if (matching[i] != NO_MATCHING) ans1[matching[i]] = i + 1;
    }
    for (int i : ans1) cout << i << ' ';
    cout << '\n';
}
int main(){
    #ifdef LOCAL
    string taskName = "B";
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