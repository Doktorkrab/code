#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE
 
#define int long long
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
// #define ALLOC
   
#define MAX 8e16L 
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

vector<vi> dp;
struct Event{
    int u, is_b, w;
    bool operator<(const Event& o) const{
        // int gg = 1 - is_b, hh = 1 - o.is_b;
        return tie(w, u, is_b) < tie(o.w, o.u, o.is_b);
    }
};
struct Solver{
    int n, m, s, t, a, b;
    vector<vector<Edge>> g;
    vector<Edge> edges;
    vector<vi> used;
    set<Event> heap;
    Solver(){
        cin >> n >> m >> s >> t;
        --s, --t;
        used.resize(n);
        dp.assign(n,vi(2, MAX));
        used.assign(n, vi(2, 0));
        g.resize(n);
        edges.resize(2 * m);
        forn(i, m){
            int v, u, w;
            cin >> v >> u >> w;
            --v, --u;
            g[v].pb({v, u, w});
            g[u].pb({u, v, w});
            edges[2 * i] = {v, u, w};
            edges[2 * i + 1] = {u, v, w}; 
        }
        cin >> a >> b;
        dp[s] = {0, 0};
        heap.insert({s, 0, 0});
        int ans = MAX;
        while (heap.size()){
            auto e = *heap.begin();
            // cout << e.u << ' ' << e.is_b << ' ' << dp[e.u] << ' ' << heap.count(e) << '\n';
            heap.erase(e);
            if (used[e.u][e.is_b]) continue;
            used[e.u][e.is_b] = 1;
            for (auto u : g[e.u]){
                if (u.w <= a && !e.is_b){
                    if (dp[u.u][0] > u.w + e.w){
                        dp[u.u][0] = e.w + u.w;
                        heap.insert({u.u, 0, dp[u.u][0]});
                    }
                }
                else if (u.w >= b){
                    if (dp[u.u][1] > u.w + min(dp[e.u][0], dp[e.u][1])){
                        dp[u.u][1] = u.w + min(dp[e.u][0], dp[e.u][1]);
                        heap.insert({u.u, 1, dp[u.u][1]});
                    }
                }
            }
        }
        ans = min(dp[t][0], dp[t][1]);
        cout << (ans >= MAX ? -1 : ans) << '\n';
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