#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int SZ = 42;
const int ABC = 26;
#else
const int SZ = 1e6 + 1;
const int INF = 1e9;
const int ABC = 26;
#endif

// -*-*-* All variables *-*-*-

int suf[SZ];
int par[SZ];
int pv[SZ];
int parent[SZ];
int link[SZ];
int suplink[SZ];
int ind[SZ];
int edges[SZ][26];
bool is_term[SZ];
bool used[SZ], was_here[SZ], ans[SZ];
int first_free = 1, n;
vector<int> child[SZ];

// -*-*-* All functions *-*-*-

void add(const string& s, int pos){
    int now = 0;
    for (char c : s){
        if (edges[now][c - 'a'] == -1){
            edges[now][c - 'a'] = first_free;
            pv[first_free] = c - 'a';
            parent[first_free++] = now;
        }
        now = edges[now][c - 'a'];
    }
    ind[pos] = now;
    is_term[now] = 1;
}

int make_link(int now){
    int v = parent[now];
    if (!now) return link[now] = 0;
    if (!v) return link[v] = 0;
    v = link[v];
    int c = pv[now];
    while (1){
        if (edges[v][c] != -1) return link[now] = edges[v][c];
        if (!v) return link[now] = 0;
        v = link[v];
    }
}

void bfs(){
    deque<int> q = {0};
    while (!q.empty()){
        // cerr << q.size() << '\n';
        int now = q.front();
        q.pop_front();
        make_link(now);
        for (int i = 0; i < 26; i++){
            if (edges[now][i] != -1) 
            q.push_back(edges[now][i]);
        }
    }
}

void get_all(int v){
    // if (!is_term[v]) return;
    was_here[v] = 1;
}

void process(const string& s){
    int v = 0;
    for (int i = 0;i < (int)s.size(); i++){
        char c = s[i];
        while(v != 0 && edges[v][c - 'a'] == -1){
            v = link[v];
        }
        if (edges[v][c - 'a'] != -1) v = edges[v][c - 'a']; 
        get_all(v);
    }
}

int dfs(int v, int p = -1){
    if (used[v]) return 0;
    ans[v] = was_here[v];
    used[v] = 1;
    for (int u : child[v]){
        if (u == p) continue;
        ans[v] |= dfs(u, v);
    }
    return ans[v];
}

void init(){
    fill(parent, parent + SZ, -1);
    for (int i = 0; i < SZ; i++){
        fill(edges[i], edges[i] + ABC, -1);
    }
    
}

void solve(){
    init();
    for (int i = 0;i < n; i++){
        string t;
        cin >> t;
        add(t, i);
    }
    bfs();
    // cerr << "kek\n";
    string s;
    cin >> s;
    process(s);
    for (int i = 0; i < SZ; i++){
        if (link[i] != i && link[i] != -1) child[link[i]].push_back(i);
    }
    dfs(0);
    for (int j = 0; j < n; j++){
        int i = ind[j];
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}

int main(){
    #ifdef LOCAL
    string taskName = "B";
    assert(freopen((taskName + ".in").c_str(), "r", stdin));
    assert(freopen((taskName + ".out").c_str(), "w", stdout));
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n){
        solve();
    }
}