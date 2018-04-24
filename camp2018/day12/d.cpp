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
    int n, k;
    vector<int> nvp;
    vector<int> perm;
    vector<int> oxr;
    Solver(){
        cin >> n >> k;
        nvp.resize(n);
        perm.resize(n);
        oxr.resize(k);
        forn(i, n) perm[i] = i;
        forn(i, k) cin >> oxr[i];
        int ans = 0;
        do{
            // cerr << "here";
            nvp.assign(n, 1);
            int mx = 1;
            forn(i, n){
                for (int j = i - 1;j >= 0;j--){
                    if (perm[j] < perm[i]){
                        nvp[i] = max(nvp[j] + 1, nvp[i]);
                        mx = max(mx, nvp[i]);
                    }
                }
            }
            // cout << mx << '\n';
            int f = 1;
            for (int i = 1;i < k;i++){
                if (find(all(perm), oxr[i] - 1) - perm.begin() < find(all(perm), oxr[i - 1] - 1) - perm.begin()){
                    f = 0;
                    break;
                }
            }
            // cout << f << '\n';
            ans += f * (mx <= k);
        } while (next_permutation(perm.begin(), perm.end()));
        cout << ans << '\n';
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
    string FN = "army";
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