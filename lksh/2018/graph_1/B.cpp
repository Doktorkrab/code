#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif

struct Vertex{
    int v;
    bool is_positive;
};
// -*-*-* All variables *-*-*-
vector<int> ans;
vector<vector<int>> g_2sat; // < n - negative, >=n - positive
vector<vector<int>> g;
vector<int> topsort;
vector<int> color_in;
vector<int> color_2sat;
map<char, int> color_to_int;
vector<vector<int>> can_color;
vector<int> used;
int n, m;
// -*-*-* All functions *-*-*-
void init(){
    ans.clear();
    g_2sat.clear();
    g.clear();
    topsort.clear();
    color_in.clear();
    color_2sat.clear();
    can_color.clear();
    used.clear();
    color_to_int['R'] = 0;
    color_to_int['G'] = 1;
    color_to_int['B'] = 2;
}
void get_topsort(int v){
    used[v] = 1;
    for (int u : g_2sat[v]){
        if (!used[u]) get_topsort(u);
    }
    topsort.push_back(v);
}
int get(int v){
    return (v >= n ? v - n : v);
}

int get_second(int v){
    return (v >= n ? v - n : v + n);
}
void paint(int v, int color){
    color_2sat[v] = color;
    if (color_2sat[get_second(v)] == color){
        cout << "Impossible\n";
        exit(0);
    } 
    if (ans[get(v)] == -1){
        ans[get(v)] = (v >= n);
    }
    for (int u : g_2sat[v]){
        if (color_2sat[u] == -1) paint(u, color);
    }
}
void solve(){
    init();
    cin >> n >> m;
    g.resize(n);
    g_2sat.resize(2 * n);
    color_2sat.assign(2 * n, -1);
    color_in.resize(n);
    can_color.resize(n);
    used.resize(2 * n);
    ans.assign(n, -1);
    for (int i = 0;i < n; i++){
        char c;
        cin >> c;
        color_in[i] = color_to_int[c];
        for (int j = 1; j < 4; j++){
            if (j != color_in[i]){
                can_color[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0;i < n; i++){
        for (int j : g[i]){
            for (int cl = 0; cl < 2; cl++){
                for (int cl1 = 0; cl1 < 2; cl1++){
                    if (can_color[i][cl] == can_color[j][cl1]){
                        g_2sat[i + cl * n].push_back(j + cl1 * n);
                    }
                }
            }
        }
    }
    for (int i = 0; i < 2 * n; i++) if (!used[i]) get_topsort(i);
    reverse(topsort.begin(), topsort.end());
    int cl = 0;
    for (int i : topsort){
        if (color_2sat[i] == -1) paint(i, cl++);
    }
    for (int i = 0; i < n; i++){
        cout << can_color[i][ans[i]];
    }
    cout << '\n';

}
int main(){
    #ifdef LOCAL
    string taskName = "B";
    assert(freopen((taskName + ".in").c_str(), "r", stdin));
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
    #else
    string taskName = "";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
    #endif
    while(t--){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}