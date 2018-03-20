#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
// #define ALLOC
 
#define MX MAX_INT
#define MIX MIN_INT
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
    int n, m;
    vector<vector<int>> g, g1;
    vector<int> topsort, color;
    vector<bool> used;
    // set<pii> edges;
    void dfs(int v){
        // cout << v << ' ';
        used[v] = 1;
        for (int u : g[v]){
            if(used[u]) continue;
            dfs(u);
        }
        topsort.push_back(v);
    }
    void dfs(int v, int c){
        // cout << "! " << v + 1 << ' ' << c << '\n';
        color[v] = c;
        for (int u : g1[v]){
            if (!color[u]) dfs(u, c); 
        }
    }
    Solver(){
        cin >> n >> m;
        g.resize(n);
        g1.resize(n);
        used.resize(n);
        color.resize(n);
        for(int i = 0;i < m;i++){
            int v, u;
            cin >> v >> u;
            g[--v].push_back(--u);
            // cout << v << ' ' << u << '\n';
            g1[u].push_back(v);
            // edges.insert({v, u});
        }
        for (int i = 0;i < n;i++) if (!used[i]) {
            dfs(i);
            // cout << '\n';
        }
        reverse(all(topsort));
        int c = 1;
        for (int v : topsort)
            if (!color[v]) {
                dfs(v, c++);
            }
 
        // int ans = 0;
        vector<int> power(c);
        set<pii> edges;
        for (int i = 0;i < n;i++){
            for (int u : g[i]){
                if (color[i] != color[u] && !edges.count({i, u})){
                    edges.insert({i, u});
                    power[color[i]]++;
                }
            }
        }
        int ans = 0;
        for (int i = 1;i < c;i++){
            if (!power[i]) ans++;
        }
        cout << ans << '\n';
    }   
};
 
// CODE END
 
int main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    freopen("fire.in", "r", stdin);
    freopen("fire.out", "w", stdout);
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