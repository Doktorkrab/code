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
    vector<int> tin, tout, tin1, tout1;
    vector<vector<int>> g, g1;
    int timer = 0;
    void dfs(int v, int p = -1){
        tin[v] = timer++;
        for (int u : g[v])
            if (u != p) dfs(u, v);
        tout[v] = timer++;
    }
    void dfs1(int v, int p = -1){
        tin1[v] = timer++;
        for (int u : g1[v])
            if (u != p) dfs1(u, v);
        tout1[v] = timer++;
    }
    Solver(){
        int n;
        cin >> n;
        int root = 0;
        g.resize(n);
        g1.resize(n);
        tin.resize(n);
        tout.resize(n);
        tin1.resize(n);
        tout1.resize(n);
        forn(i, n){
            int p;
            cin >> p;
            if (p == 0){
                root = i;
                continue;
            }
            --p;
            g[p].pb(i);
            g[i].pb(p);
        }
        dfs(root);
        forn(i, n){
            int p;
            cin >> p;
            if (p == 0){
                root = i;
                continue;
            }
            --p;
            g1[p].pb(i);
            g1[i].pb(p);
        }
        dfs1(root);
        set<pii> ans;
        forn(i, n){
            forn(j, n){
                if (tin[i] < tin[j] && tout[i] > tout[j] && tin1[i] < tin1[j] && tout1[i] > tout1[j]) ans.insert({min(i, j), max(i ,j)});
            }
        }
        
        cout << ans.size() << '\n';

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
    string FN = "virus";
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