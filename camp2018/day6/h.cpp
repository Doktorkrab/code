#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<double, double>;
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
    int n;
    double r, a;
    vector<pii> coords;
    vector<int> stack;
    double len(pii a, pii b){
        return sqrt((a.ft - b.ft) * (a.ft - b.ft) + (a.st - b.st) * (a.st - b.st));
    }
    Solver(){
        cout.precision(20);
        cout.setf(ios::fixed);
        cin >> n;
        coords.resize(n);
        forn(i, n) cin >> coords[i].ft;
        forn(i, n) cin >> coords[i].st;
        cin >> r >> a;
        int mst_count = n - 1;
        vector<bool> in_mst(n);
        double ans = -a;
        int air = -1;
        while(mst_count > 0){
            cout << ans << '\n';
            forn(j, n){
                cerr << mst_count << ' ' << j << ' ';
                if (in_mst[j]) continue;
                ans += a;
                air++;
                int index = j;
                while (mst_count){
                    cerr << index << ' ';
                    double min_ = INT_MAX;
                    in_mst[index] = 1;
                    int mini = 0;
                    forn(i, n){
                        if (!in_mst[i]){
                            if (min_ > len(coords[index], coords[i]))
                            min_ = len(coords[index], coords[i]), mini = i;
                        }
                    }
                    mst_count--;
                    if (min_ > a + a * (air == 0)){
                        in_mst[index] = 0;
                        break;
                    }
                    ans += min_;
                    index = mini;
                }
                cerr << '\n';
            }
        }
        cout << ans * (air > 0) << '\n';
    }   
};

// CODE END

int main(){
    int t  = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
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
