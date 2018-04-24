#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE
 
#define int long long
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
const int INF = 4e18;
#define ALLOC
   
#define MAX INT_MAX
#define MIN INT_MIN
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0;i < n;i++)
#define ft first
#define st second
#define pb push_back
   
   
#ifdef ALLOC
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { }
#endif
   
// TEMPLATE END
   
// CODE HERE
struct Edge{
    int v, u, w;
};
struct Solver{
    // vector<vi> g;
    vector<Edge> edges;
    vector<vi> g;
    vi dist, used;
    int n, m, s;
    unordered_set<int> changes;
    void dfs(int v){
        used[v] = 1;
        changes.insert(v);
        for (int u : g[v]) if (!used[u]) dfs(u);
    }
    Solver(){
        cin >> n >> m >> s;
        --s;
        dist.assign(n, INF);
        edges.resize(m);
        used.resize(n);
        g.resize(n);
        forn(i, m){
            int v, u, w;
            cin >> v >> u >> w;
            edges[i] = {v - 1, u - 1, w};
            g[v - 1].pb(u - 1);
            // g[u].pb(v);
        }
        dist[s] = 0;
        for (int i = 1;i <= n;i++){
            for (auto e : edges){
                if (dist[e.v] < INF){
                    dist[e.u] = max(-INF, min(min(dist[e.v] + e.w, INF), dist[e.u]));
                }
            }
        }
        for (int i = 1;i <= n;i++)
        for (auto e : edges){
            if (dist[e.v] < INF && dist[e.u] > dist[e.v] + e.w){
                if (!used[e.u]) dfs(e.v);
                dist[e.u] = max(-INF, min(min(dist[e.v] + e.w, INF), dist[e.u]));
            }
        }
        forn(v, n){
            if (dist[v] >= INF) cout << "*\n";
            else if (changes.count(v)) cout << "-\n";
            else cout << dist[v] << '\n';
        }
    }   
};
   
// CODE END
   
signed main(){
    int t  = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    // string FN = "cut";
    // freopen((FN + ".in").c_str(), "r", stdin);
    // freopen((FN + ".out").c_str(), "w", stdout);
#endif
    while(t--){
#ifdef LOCAL
        clock_t t_elapsed = clock();
#endif
        Solver a;
#ifdef LOCAL
        cout << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }
   
}