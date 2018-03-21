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
    vector<vi> g;
    vector<vector<int>> dp;
    vector<set<int>> types;
    int n;
    void dfs(int v, int p = -1){
        dp[0][v] = types[v].count(0) ? 1 : -1;
        dp[1][v] = (int)types[v].count(1) ? 0 : -1;
        dp[2][v] = (int)types[v].count(2) ? 0 : -1;
        for (int u : g[v]){
            if (u == p) continue;
            dfs(u, v);
            for (int i : {0, 1, 2}){
                if (types[v].count(i) && dp[i][v] != -1){
                    int max_ = -1;
                    for (int j : {0, 1, 2}){
                        if (i == j) continue;
                        max_ = max(dp[j][u], max_);
                    }
                    // if (dp[i][v][0] == -1 || max_[0] == -1) continue;
                    if (max_ == -1) dp[i][v] = -1;
                    else dp[i][v] += max_;
                    // dp[i][v] = merge(max_, dp[i][v]);
                }
            }
        }
    }
    Solver(){
        cin >> n;
        g.resize(n);
        dp.assign(3, vi(n, -1));
        types.resize(n);
        forn(i, n - 1){
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].pb(u);
            g[u].pb(v);
        }
        forn(i, n){
            string s;
            cin >> s;
            for (char c : s){
                if (c == 'I'){
                    types[i].insert(0);
                }
                if (c == 'B'){
                    types[i].insert(1);
                }
                if (c == 'V'){
                    types[i].insert(2);
                }
            }
        }
        dfs(0);
        auto ans = max(dp[0][0], max(dp[1][0], dp[2][0]));
        cout << ans << '\n';
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
    string FN = "indigo";
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