// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
// const int MAX_MEM = 2e8;
// int mpos = 0;
// unsigned char mem[MAX_MEM];
// inline void * operator new ( size_t n ) {
//     assert((mpos += n) <= MAX_MEM);
//     return (void *)(mem + mpos - n);
// }
// inline void operator delete ( void * ) noexcept { }
 
const int SZ = 1e6 + 1;
vector<int> suf(SZ), par(SZ), pv(SZ), parent(SZ, -1), link(SZ), suplink(SZ), ind(SZ);
vector<vector<int>> edges(SZ, vector<int>(26, -1));
vector<bool> is_term(SZ);
vector<pair<int, int>> how_many(SZ, {INT_MAX, INT_MIN});
int first_free = 1;
void add(string& s, int i){
    int now = 0;
    for (char c : s){
        if (edges[now][c - 'a'] == -1){
            edges[now][c - 'a'] = first_free;
            pv[first_free] = c - 'a';
            parent[first_free] = now;
            first_free++;
        }
        now = edges[now][c - 'a'];
    }
    ind[i] = (now);
    is_term[now] = 1;
}
 
void make_link(int now){
    int v = parent[now];
    if (now == 0){
        link[now] = 0;
        return; 
    }
    if (v == 0){
        link[v] = 0;
        return;
    }
    v = link[v];
    int c = pv[now];
    while(1){
        // cout << v << edges[v][c] << '\n';
        if (edges[v][c] != -1){
            link[now] = edges[v][c];
            return;
        }
        if (v == 0){
            link[now] = 0;
            return;
        }
        v = link[v];
    }
}
 
void bfs(){
    deque<int> q = {0};
    while(!q.empty()){
        int now = q.front();
        q.pop_front();
        make_link(now);
        for (int i = 0;i < 26;i++){
            if (edges[now][i] != -1){
                q.push_back(edges[now][i]);
            }
        }
    }
}
void get_all(int v, int i){
    // if (!is_term[v]) return;
    how_many[v] = {min(how_many[v].first, i), max(how_many[v].second, i)};
}
vector<int> sz_s(SZ);
void process(string& s){
    int v = 0;
    for (int i = 0;i < s.size();i++){
        char c = s[i];
        while(v != 0 && edges[v][c - 'a'] == -1) {
            v = link[v];
        }
        if (edges[v][c - 'a'] != -1) v = edges[v][c - 'a'];
        get_all(v, i + 1);
    }
}
vector<pair<int, int>> dp(SZ, {0, 0});
vector<vector<int>> child(SZ);
pair<int, int> dfs(int v, int p = -1){
    if (dp[v] != make_pair(0, 0)) return {INT_MAX, INT_MIN};
    dp[v] = how_many[v];
    for (int u : child[v]){
        if (u == p) continue;
        auto tmp = dfs(u, v);
        dp[v] = {min(tmp.first, dp[v].first), max(tmp.second, dp[v].second)};
    }
    return dp[v];
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    freopen("search6.in", "r", stdin);
    freopen("search6.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        string t;
        cin >> t;
        add(t, i);
        sz_s[i] = t.size();
    }
    bfs();
    string s;
    cin >> s;
    process(s);
    // cout << link[4] << ' ' << link[6] << '\n';
    for (int i = 0;i < SZ;i++){
        if (link[i] != i && link[i] != -1) child[link[i]].push_back(i);
        // cout << link[i] << ' ' << i << '\n';
    }
    dfs(0);
    for (int j = 0;j < n;j++){
        int i = ind[j];
        if (dp[i] == make_pair(INT_MAX, INT_MIN)){
            cout << "-1 -1\n";
            continue;
        }
        cout << dp[i].first - sz_s[j] << ' ' << dp[i].second - sz_s[j] << '\n';
    }
}