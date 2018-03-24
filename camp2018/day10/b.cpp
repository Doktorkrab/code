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
    vector<vector<pii>> g;
    vector<int> ans;
    int n;
    void dfs(deque<int>& q, int v, bool is_delete){
        if (is_delete){
            // q.pop_front();
            ans[v] = q.front();
            q.pop_front();
        }
        for (auto u : g[v]){
            // cout << v << ' ' << u.ft << ' ' << u.st << '\n';
            if (u.st != LONG_LONG_MIN) q.push_back(u.st);
            dfs(q, u.ft, u.st == LONG_LONG_MIN);
            if (u.st != LONG_LONG_MIN) q.pop_back();
        }
        if (is_delete){
            q.push_front(ans[v]);
        }
    }
    Solver(){
        cin >> n;
        g.resize(n + 1);
        ans.assign(n + 1, LONG_LONG_MIN);
        // vector<int> to_delete;
        forn(i, n){
            int type, num;
            cin >> type >> num;
            if (type == 1){
                int how;
                cin >> how;
                g[num].pb({i + 1, how});
            }
            else{
                g[num].pb({i + 1, LONG_LONG_MIN});
            }
        }
        deque<int> dek;
        dfs(dek, 0, 0);
        for (int u : ans){
            if (u != LONG_LONG_MIN) cout << u << '\n';
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
    // string FN = "cut";
    // freopen((FN + ".in").c_str(), "r", stdin);
    // freopen((FN + ".out").c_str(), "w", stdout);
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