#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define ALLOC

#define MX MAX_INT
#define MIX MIN_INT
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
struct Edge{
    int v, u, w;
    bool operator<(Edge& a){
        return tie(w, v, u) < tie(a.w, a.v, a.u);
    }
};
struct Solver{
    int n, m;
    vector<Edge> edges;
    vi p, sz;
    int get(int v){
        // cerr << v << p[v] << '\n';
        if (p[v] == v) return v;
        return p[v] = get(p[v]);
    }
    void un(int v, int u){
        v = get(v), u = get(u);
        if (v == u) return;
        if(sz[v] > sz[u]) swap(v, u);
        p[v] = u;
        sz[u] += sz[v];
    }
    Solver(){
        cin >> n >> m;
        p.resize(n);
        sz.resize(n);
        edges.resize(m);
        forn(i, n) p[i] = i, sz[i] = 1;
        forn(i, m){
            int v, u, w;
            cin >> v >> u >> w;
            edges[i] = {--v, --u, w};
        }
        sort(all(edges));
        int ans = 0;
        for (Edge a : edges){
            // cerr << a.v << ' ' << a.u << '\n';
            // cerr << "NEW:\n";
            if (get(a.v) != get(a.u)){
                ans += a.w;
                un(a.v, a.u);
            }
        }
        cout << ans << '\n';
    }   
};

// CODE END

signed main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    freopen("spantree2.in", "r", stdin);
    freopen("spantree2.out", "w", stdout);
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
