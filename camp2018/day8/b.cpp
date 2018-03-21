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
struct Solver{
    vector<vector<int>> g;
    vi sz, sz1;
    int n;
    void dfs(int v, int p = -1){
        for (int u : g[v]){
            if (u == p) continue;
            dfs(u, v);
            sz1[v] += sz1[u];
            sz[v] += sz[u];
        }
        sz1[v] += sz[v] - 1;
        // cout << v + 1 << ' ' << sz[v] << ' ' << sz1[v] << '\n';
    }
    map<pair<int, int>, int> ans;
    pii get(int v, int u){
        return {min(v, u), max(v, u)};
    }
    void dfs(int v, int p, int up){
        int now = up + sz1[v];
        // cout << v + 1 << ' ' << up << '\n';
        for (int u : g[v]){
            if (u == p) continue;
            int gg = (n - sz[u]) * sz[u] + 
                     (now - sz1[u] - sz[u]) * sz[u] + 
                     sz1[u] * (n - sz[u]);
            ans[get(v, u)] =  gg;
            // cout << v + 1 << ' ' << u +1 << ' ' <<
            // (n - sz[u]) * sz[u] << ' ' <<
            // (now - sz1[u] - sz[u]) * sz[u] << ' ' <<
            // sz1[u] * (n - sz[u]) << '\n';
            // cout << v + 1 << ' ' << u + 1 << '\n';
            dfs(u, v, now - sz1[u] - sz[u] + n - sz[u]);
        }
    }
    Solver(){
        cin >> n;
        g.resize(n);
        sz.assign(n, 1);
        sz1.resize(n);
        vector<pii> edges;
        forn(i, n - 1){
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].pb(u);
            g[u].pb(v);
            edges.pb(get(v, u));
        }
        dfs(0);
        // dfs1(0);
        dfs(0, -1, 0);
        for (auto i : edges){
            cout << ans[i] << '\n';
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
    string FN = "treedp";
    freopen((FN + ".in").c_str(), "r", stdin);
    freopen((FN + ".out").c_str(), "w", stdout);
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