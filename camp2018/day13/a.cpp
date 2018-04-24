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
struct Event{
    int l, r, val;
    bool operator<(const Event& o) const{
        int nr = -r, nr1 = -o.r;
        return tie(val, nr, l) < tie(o.val, nr1, o.l);
    }
};
bool cmp(pii a, pii b){
    return tie(a.st, a.ft) < tie(b.st, b.ft);
}
struct Solver{
    int n;
    vector<int> colors, prv, last;
    vector<int> dp;
    vector<vector<pii>> st_ft;
    vector<Event> events;
    set<Event> now;
    vector<int> par;
    bool add(int x){
        if (prv[x] == n) return 0;
        if (x != n - 1) st_ft[x + 1].pb({events.size(), 0});
        if (prv[x] != n - 1) st_ft[prv[x] + 1].pb({events.size(), 1});
        events.pb({x, prv[x] + 1, dp[x] + 1});
        return 1;
    }
    Solver(){
        cin >> n;
        colors.resize(n);
        prv.assign(n, n);
        dp.assign(n, MAX);
        last.assign(300000, n);
        st_ft.resize(n);
        par.assign(n, -1);
        forn(i, n){
            cin >>colors[i];
            colors[i]--;
            // cout << colors[i] << ' ' << last[colors[i]] << '\n';
            if (last[colors[i]] != n) {
                prv[last[colors[i]]] = i;
                // cout << prv[last[colors[i]]] << '\n';
            }
            last[colors[i]] = i;
        }
        dp[0] = 0;
        if (!add(0)){
            cout << 0 << '\n';
            return;
        }
        // cerr << "here";
        for (int i = 1;i < n;i++){
            sort(all(st_ft[i]), cmp);
            for (auto j : st_ft[i]){
                Event now_e = events[j.ft];
                if (j.st == 0) now.insert(now_e);
                else now.erase(now_e);
            }
            if (now.empty()){
                cout << "0\n";
                return;
            }
            dp[i] = (now.begin())->val;
            par[i] = (now.begin())->l;
            add(i);
        }
        cout << dp[n - 1] << '\n';
        int x = par[n - 1];
        vector<int> ans;
        while (par[x] != -1){
           ans.pb(x + 1);
            x = par[x];
        }
        ans.pb(x + 1);
        reverse(all(ans));
        for (int i : ans) cout << i << ' ';
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
    string FN = "expedition";
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