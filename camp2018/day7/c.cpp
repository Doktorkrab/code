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
struct Edge{
    int v, u, f, c;
    bool used;
};
struct Solver{
    vector<Edge> edges;
    vector<vector<pii>> g; // edges v->u, u<-v
    vector<bool> used;
    int n, m, s, t;
    int get(Edge a){
        return a.c - a.f;
    }
    vector<int> ans;
    int dfs(int v, int max_, int cm, int t){
        // cerr << v << ' ' << power << '\n';
        used[v] = 1;
        if (v == t){
            // cout << "n - 1 " << cm << '\n';        
            return cm;
        }
        for (pii a : g[v]){
            Edge b = edges[a.ft];
            // cerr << b.v << ' ' << b.u << ' ' << get(b) << ' ' << used[b.u] << '\n';
            if (used[b.u] || get(b) < max_) continue;
            auto ret = dfs(b.u, max_, min(cm, get(b)), t);
            if (!ret) continue;
            edges[a.ft].f += ret;
            edges[a.st].f -= ret;
            return ret;
        }
        return 0;
    }
    bool dfs(int v, int t){
        used[v] = 1;
        if (v == t){
            ans.pb(t);
            // cout << "t!\n";
            return 1;
        }
        for (pii a : g[v]){
            Edge b = edges[a.ft];
            if (used[b.u] || get(b) != 0 || b.f < 0 || b.used) continue;
            if (dfs(b.u, t)){
                // cout << v << ' ' << b.u << ' ' << get(b) << '\n';
                // edges[a.ft].f -= 1;
                // edges[a.st].f += 1;
                edges[a.ft].used = 1;
                edges[a.st].used = 1;
                ans.pb(v);
                return 1;
            }
        }
        return 0;
    }
    Solver(){
        cin >> n;
        g.resize(n);
        cin >> m >> s >> t;
        --s, --t;
        assert(s != t);
        int mx = 0;
        forn(i, m){
            int v, u, w, ind = edges.size();
            cin >> v >> u;
            --v, --u;
            g[v].pb({ind, ind + 1});
            g[u].pb({ind + 1, ind});
            edges.pb({v, u, 0, 1, 0});
            edges.pb({u, v, 0, 1, 1});
            mx = max(mx, w);
        }
        int power = 64;
        for (;power >= 0;power--){
            used.assign(n, 0);                
            while(dfs(s, (1LL << power), INT_MAX, t)){
                used.assign(n, 0);                
            }
        }
        int ans1 = 0;
        for (int i = 0;i < edges.size();i++){
            Edge a = edges[i];
            if (a.u == t && i % 2 == 0) ans1 += a.f;
        }
        // cout << ans1 << '\n';
        if (ans1 < 2){
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        used.assign(n, 0);
        assert(dfs(s, t));
        reverse(all(ans));
        for (int i : ans){
            cout << i + 1 << ' ';
        }
        ans.clear();
        cout << '\n';
        used.assign(n, 0);
        assert(dfs(s, t));
        reverse(all(ans));
        for (int i : ans){
            cout << i + 1 << ' ';
        }
        cout << '\n';
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
    string FN = "snails";
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