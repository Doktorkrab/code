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
   
// DEFINES VARS
int n, m, t, s, humans;
vi d, guki, used, on_sec;
vector<vi> g;

void bfs(int s){
    deque<int> q = {s};
    d[s] = 0;
    while(q.size()){
        int v = q.front();
        q.pop_front();
        if (used[v]) continue;
        used[v] = 1;
        on_sec[d[v]] += guki[v];
        for (int u : g[v]){
            if (d[u] > d[v] + 1){
                d[u] = d[v] + 1;
                q.push_back(u);
            }
        }
    }
}
void prep(){}

void solve(){
    cin >> n >> m >> t;
    d.assign(n + 20, MAX);
    g.assign(n, {});
    used.assign(n, 0);
    on_sec.assign(n + 20, 0);
    guki.resize(n);
    forn(i, n) cin >> guki[i];
    forn(i, m){
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].pb(u);
        g[u].pb(v);
    }
    cin >> s >> humans;
    bfs(--s);
    int cur = -1;
    for (int i : on_sec){
        if (cur == -1){
            cur = i;
            continue;
        }
        int minus = min(t, min(cur, humans));
        cur -= minus, humans -= minus;
        if (cur == 0 && humans > 0){
            cout << "YES\n";
            return;
        }
        cur += i;
    }
    int minus = min(t, min(cur, humans));
    cur -= minus, humans -= minus;
    if (cur == 0 && humans > 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

}
   
// CODE END
   
signed main(){
    int t = 1;
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
        solve();
#ifdef LOCAL
        cout << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }
   
}