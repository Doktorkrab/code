#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define ALLOC

#define MX INT_MAX
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
    int n, m, timer = 0;
    vector<vi> g;
    vi tin, fup, ans;
    map<pii, int> id;
    vector<pii> edges;
    vector<bool> used;
    pii get(int v, int u){
        return {min(v, u), max(v, u)};
    }
    int dfs(int v, int p){
        used[v] = 1;
        tin[v] = fup[v] = timer++;
        // cerr << v << ' ';
        int child = 0, flag = 0;
        for (int u : g[v]){
            if (!used[u]){
                fup[v] = min(fup[v], dfs(u, v));
                child++;
                if (fup[u] >= tin[v] && child && !flag && p != -1){
                    ans.pb(v + 1);
                    flag = 1;
                }
            }
            else{
                if (u == p) continue;
                fup[v] = min(fup[v], tin[u]);
            }
        }
        if (p == -1 && child > 1) ans.pb(v + 1);
        return fup[v];
    }
    Solver(){
        cin >> n >> m;
        g.resize(n);
        tin.resize(n);
        fup.assign(n, MX);
        edges.resize(n);
        used.resize(n);
        for (int i = 0;i < m;i++){
            int v, u;
            cin >> v >> u;
            g[--v].push_back(--u);
            g[u].pb(v);
            id[get(v, u)] = i;
        }
        for (int i = 0;i < n;i++) if (!used[i]) {
            dfs(i, -1);
            // cout << '\n';
        }
        cout << ans.size() << '\n';
        sort(all(ans));
        for (int a : ans) cout << a << ' ';
        cout << '\n';
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
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
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
