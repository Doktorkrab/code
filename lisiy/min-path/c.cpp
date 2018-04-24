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
    vector<vi> matr;
    int n;
    Solver(){
        cin >> n;
        matr.assign(n, vi(n));
        forn(i, n){
            forn(j, n){
                cin >> matr[i][j];
                if (matr[i][j] == -1) matr[i][j] = MAX;
            }
        }
        forn(k, n){
            forn(i, n){
                forn(j, n){
                    if (matr[i][k] < MAX && matr[k][j] < MAX){
                        matr[i][j] = min(matr[i][j], matr[i][k] + matr[k][j]);
                    }
                }
            }
        }
        int ans = 0, ans1 = MAX;
        forn(i, n){
            int ans2 = 0;
            bool f = 0;
            forn(j, n){
                if (matr[i][j] != MAX){
                    ans = max(matr[i][j], ans);
                    ans2 = max(matr[i][j], ans2);
                    f = 1;
                }
            }
            if (f) ans1 = min(ans2, ans1);
        }
        cout << ans << '\n' << ans1 << '\n';
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