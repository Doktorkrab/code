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
    vector<pii> edges;
    vi sz;
    int n, p;
    vector<unordered_map<int, int>> dp;
    void dfs(int v, int p = -1){
        for (int u : g[v]){
            if (u == p) continue;
            dfs(u, v);
            sz[v] += sz[u];
            unordered_map<int, int> tmp = dp[u];
            unordered_map<int, int> tmp1 = dp[v];
            if (tmp.size() > tmp1.size()) swap(tmp, tmp1);
            for (auto t : tmp){
                if (tmp1.count(t.first)) tmp1[t.ft] = min(t.st, tmp1[t.ft]);
                else tmp1[t.ft] = t.st;
                if (tmp1.count(sz[u] - t.first)) tmp1[sz[u] - t.ft] = min(t.st + 1, tmp1[t.ft]);
                else tmp1[sz[u] - t.ft] = t.st + 1;
            }
            dp[v] = tmp1;
            dp[v][sz[u]] = 1;
            dp[v][n - sz[u]] = 1;
            
        }
    }
    Solver(){
        // cerr << "here";
        cin >> n >> p;
        // cerr << "here";
        g.resize(n);
        dp.resize(n);
        sz.assign(n, 1);
        // cerr << "here";
        forn(i, n - 1){
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].pb(u);
            g[u].pb(v);
        }
        // cerr << "here";
        dp[0][n] = 0;
        dfs(0);
        for (auto i : dp[0]){
            cout << i.ft << ' ' << i.st << '\n';
        }
        // cout << dp[0][p] << ' ' << dp[0][n - p] << '\n';
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
    string FN = "cut";
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