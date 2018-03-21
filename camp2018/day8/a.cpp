#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE
  
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
  
#define int long long
  
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
    vector<vector<int>> dp;
    int n;
    void dfs(int v, int p = -1){
        dp[1][v] = 1;
        for (int u : g[v]){
            if (u == p) continue;
            dfs(u, v);
            dp[1][v] += dp[0][u];
            dp[0][v] += max(dp[1][u], dp[0][u]);
        }
        // cout << v + 1 << ' ' << dp[0][v] << ' ' << dp[1][v] << '\n';
    }
    Solver(){
        int n;
        cin >> n;
        g.resize(n);
        dp.assign(2, vector<int>(n));
        int root;
        forn(i, n){
            int p;
            cin >> p;
            if (!p){
                root = i;
                continue;
            }
            g[p - 1].pb(i);
            g[i].pb(p - 1); 
        }
        dfs(root);
        cout << max(dp[0][root], dp[1][root]) << '\n';
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
    string FN = "select";
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