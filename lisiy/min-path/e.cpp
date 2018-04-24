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
    vector<pii> shift = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<vi> fld, used;
    vector<vector<pii>> d;
    int n, m;
    pii s, t;
    void bfs(){
        deque<pii> q = {s};
        d[s.st][s.ft] = {0, 0};
        while (q.size()){
            auto v = q.front();
            q.pop_front();
            if (used[v.ft][v.st]) continue;
            used[v.ft][v.st] = 1;
            for (pii s : shift){
                pii nw = {v.ft + s.ft, v.st + s.st};
                if (nw.ft >= n || nw.st >= m || nw.ft < 0 || nw.st < 0 || fld[nw.ft][nw.st] == 0) continue;
                pii nw_d = {d[v.ft][v.st].ft + (fld[v.ft][v.st] != fld[nw.ft][nw.st]), d[v.ft][v.st].st + 1};
                if (nw_d < d[nw.ft][nw.st]){
                    d[nw.ft][nw.st] = min(nw_d, d[nw.ft][nw.st]);
                    q.push_back(nw);
                }
            }
        }
    }
    Solver(){
        cin >> n >> m;
        cin >> s.ft >> s.st;
        s.ft--;
        s.st--;
        cin >> t.ft >> t.st;
        t.ft--;
        t.st--;
        fld.assign(n, vi(m));
        used.assign(n, vi(m));
        d.assign(n, vector<pii>(m, {MAX, MAX}));
        used.resize(n);
        forn(i, n){
            forn(j, m){
                char c;
                cin >> c;
                fld[i][j] = c - '0';
            }
        }
        bfs();
        // for(auto i : d){
        //     for (auto j : i) cout << "{" << j.st << ", " << j.ft << "} ";
        //     cout << '\n';
        // }
        if (used[t.ft][t.st]){
            cout << d[t.ft][t.st].st + 1 << ' ' << d[t.ft][t.st].ft << '\n';
        }
        else{
            cout << "0 0\n";
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