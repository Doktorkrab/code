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
    double x;
    vector<pair<int, double>> cards;
    Solver(){
        cin >> n >> x;
        cards.resize(n);
        forn(i, n){
            int a, b;
            cin >> a >> b;
            cards[i] = {a, 1 - b / 100.};
        }
        double ans = x;
        int ansmask = 0;
        for (int mask = 0; mask < (1 << n);mask++){
            double cur = x, minus = 0;
            forn(i, n){
                if (mask & (1 << i)) cur *= cards[i].st;
                else minus += cards[i].ft;
            }
            cur -= minus;
            if (ans > cur) ans = cur, ansmask = mask;
        }
        // cout << ans << '\n';
        forn(i, n){
            if ((1 << i) & ansmask) cout << i + 1 << ' ' << "reverse" << '\n';
        }
        forn(i, n){
             if (!((1 << i) & ansmask)) cout << i + 1 << ' ' << "front" << '\n';
       
        }
    }   
};

// CODE END

int main(){
    int t = 1;
#ifdef LOCAL
    // assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    freopen("discount.in", "r", stdin);
    freopen("discount.out", "w", stdout);
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
