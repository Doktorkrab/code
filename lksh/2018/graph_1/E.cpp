#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif

struct Edge{
    string v, u;
    bool is_fake;
};
// -*-*-* All variables *-*-*-
map<string, vector<int>> g;
map<string, int> in_degree, out_degree;
unordered_set<string> used;
vector<char> ans[2];
unordered_set<int> banned;
unordered_set<string> was;
vector<Edge> edges;
int n;
// -*-*-* All functions *-*-*-
void init(){
    g.clear();
    in_degree.clear();
    out_degree.clear();
    used.clear();
    ans[0].clear();
    ans[1].clear();    
    banned.clear();
    edges.clear();
    was.clear();
}

int dfs(const string& v, bool flag = 1){
    int was_fake = 0;
    while(!g[v].empty()){
        cerr << v << ' ' << edges[g[v].back()].u << ' ' << edges[g[v].back()].is_fake << '\n';
        // for (int i : g[v]) cerr << i << ' ';
        // cerr << '\n';
        auto tmp = edges[g[v].back()].u;
        auto tmp1 = edges[g[v].back()].is_fake;
        g[v].pop_back();
        // cerr << v[1] << '\n';
        was_fake |= dfs(tmp, !tmp1);
        was_fake |= !tmp1;
    }
    ans[was_fake].push_back(v[1]);
    return was_fake;
    // cerr << flag << ' ' << v[1] << '\n';
}
void solve(){
    init();
    cin >> n;
    unordered_set<string> substrs;
    for (int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        // cerr << tmp.substr(0, 2) << ' ' << tmp.substr(1, 2) << '\n';
        substrs.insert(tmp.substr(0, 2));
        substrs.insert(tmp.substr(1, 2));
        g[tmp.substr(0, 2)].push_back(edges.size());
        // cerr << edges.size() << '\n';
        in_degree[tmp.substr(1, 2)]++;
        out_degree[tmp.substr(0, 2)]++;
        edges.push_back({tmp.substr(0, 2), tmp.substr(1, 2), 0});
    }
    // cerr << "here";
    string one = "--"s, minus_one = "--"s;
    for (auto& i : substrs){
        // cerr << i << ' ' << in_degree[i] << ' ' << out_degree[i] << '\n';
        if (in_degree[i] == out_degree[i]) continue;
        else if (one == "--" && (in_degree[i] - out_degree[i]) == 1){
            one = i;
        }
        else if (minus_one == "--" && (in_degree[i] - out_degree[i]) == -1){
            minus_one = i;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    cerr << one << '\n' << minus_one << '\n';
    if ((one != "--") ^ (minus_one != "--")){
        cout << "NO\n";
        return;
    }
    if (one != "--" && minus_one != "--"){
        g[one].push_back(edges.size());
        edges.push_back({one, minus_one, 1});
    }
    // cerr << minus_one << '\n';
    if (minus_one == "--") minus_one = g.begin()->first;
    for (auto i : edges){
        cout << i.v << ' ' << i.u << ' ' << i.is_fake << '\n';
    }
    dfs(minus_one);
    // ans.push_back(g.begin()->first[0]);
    // reverse(ans.begin(), ans.end());
    // ans.push_back(g.begin()->first[1]);
    // for (int i : banned) cerr << i << ' ';
    // cerr << '\n';
    for (auto i : g){
        if (i.second.size() != 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << minus_one[0];
    for (char i : ans[0]) cout << i << ' ';
    cout << '\n';
    for (char i : ans[1]) cout << i << ' ';
    cout << "\n";
    // for (auto i : ans) cout << i;
    // cout << '\n';    

}
int main(){
    #ifdef LOCAL
    string taskName = "E";
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