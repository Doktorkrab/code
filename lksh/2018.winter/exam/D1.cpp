#include<bits/stdc++.h>
using namespace std;
const int MAXM = 2e5;
const int MAXN = 1e5;
 
int n, m, s, t;
 
struct E{
    int from, to, c, f;
    E(){}
    E(int a, int b, int _c, int d){from = a, to = b, c = _c, f = d;}
};
 
E e[MAXM];
int d[MAXN];
int u[MAXN];
int flow, B;
vector<int> g[MAXN];
 
inline void init(){
    flow = 0;
    s--;
    t--;
    B = 1;
    for(int i = 0; i < n; i++){
        d[i] = 1e9;
        u[i] = 0;
        g[i].clear();
    }
    for(int i = 0; i < m; i++){
        e[i] = E(0, 0, 0, 0);
    }
}
 
void bfs(){
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto id : g[v]){
            auto edge = e[id];
            if(d[edge.to] > d[v] + 1 && edge.c >= edge.f + B){
                d[edge.to] = d[v] + 1;
                q.push(edge.to);
            }
        }
    }
}
 
vector<int> path;
inline int dfs(int v, int _min = 1e9){
    u[v] = 1;
    if(v == t){
        u[v] = 0;
        path.push_back(v);
        return _min;
    }
    for(auto id : g[v]){
        auto edge = e[id];
        if(!u[edge.to])
                if(edge.c >= edge.f + B){
                    int kek = dfs(edge.to, min(_min, edge.c - edge.f));
                    if(kek > 0){
                        u[v] = 0;
                        e[id].f += kek;
                        e[id ^ 1].f -= kek;
                        path.push_back(v);
                        return kek;
                    }
                }
    }
    return 0;
}
 
inline void dfs_get(int v){
    if(v == t){
        path.push_back(v);
        return ;
    }
    for(auto id : g[v]){
        auto edge = e[id];
            if(edge.f == 1){
                e[id].f--;
                e[id ^ 1].f++;
                dfs_get(edge.to);
                path.push_back(v);
                return;
            }
    }
    return ;
}
 
inline void solve(){
    init();
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        e[i * 2] = E(a, b, 1, 0);
        e[i * 2 + 1] = E(b, a, 0, 0);
        g[a].push_back(i * 2);
        g[b].push_back(i * 2 + 1);
    }
    /*while(B > 0){
        while(1){
            for(int i = 0; i < n; i++){
                d[i] = 1e9;
                u[i] = 0;
            }
            bfs();
            if(d[t] == 1e9)
                break;
            while(1){
                int kek = dfs(s);
                if(kek == 0)
                    break;
                flow += kek;
            }
        }
        B >>= 1;
    }*/
    int cnt = 0;
    cnt += dfs(s);
    memset(u, 0, sizeof(u));
    cnt += dfs(s);
    if(cnt < 2){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < 2; i++){
        memset(u, 0, sizeof(u));
        path.clear();
        dfs_get(s);
        reverse(path.begin(), path.end());
        for(auto it : path){
                cout << it + 1 << ' ';
        }
        cout << '\n';
    }
}
 
signed main() {
    #ifdef DEBUG
        freopen("D.in", "r", stdin);
        freopen("D.out", "w", stdout);
    #else
 
    #endif // DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m >> s >> t){ // O(m^3 * alpha * test)
        solve();
    }
    return 0;
}