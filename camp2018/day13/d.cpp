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
struct Segment{
    pii beg, end;
    int ind;
    bool operator<(const Segment& o) const{
        return tie(beg, end, ind) < tie(o.beg, o.end, o.ind);
    }
    operator int() const { return ind; }
};
bool cmp(const int& x, const int& y){
    return x < y;
}
struct Solver{
    vector<Segment> segs_x, segs_y;
    vector<pii> ans;
    set<pair<pii, pii>> s;
    int n;
    Solver(){
        cin >> n;
        forn(i, n){
            int x, y, x1, y1;
            cin >> x >> y >> x1 >> y1;
            if (s.count({{x, y}, {x1, y1}})){
                cout << "0\n";
                return;
            }
            s.insert({{x, y}, {x1, y1}});
            if (x == x1){
                segs_x.pb({{x, min(y, y1)}, {x1, max(y1, y)}, i});
            }
            else segs_y.pb({{min(x, x1), y}, {max(x1, x), y1}, i});
        }
        for(Segment seg : segs_x){
            int ind = upper_bound(all(segs_y), seg.ind, cmp) - segs_y.begin();
            for (int x = seg.beg.ft; x <= seg.end.ft;i++){
                bool f = 0;
                for (int y = seg.beg.st; y <= seg.end.st;i++){
                    bool f1 = 0;
                    for (int i = ind;i < segs_y.size();i++){
                        if (y == segs_y[ind].beg.st && )
                    }
                }
            }
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