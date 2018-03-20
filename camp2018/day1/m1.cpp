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
// unordered_map<int, int> ans;
struct Solver{
    int n;
    double x;
    vector<pair<int, double>> cards;
    pair<double, long long> solve(long long mask, int minus, double x, int pos){
        if (pos == n) return {x - minus, mask};
        if (x - minus <= 0) return {0, mask};
        auto ret = solve(mask, minus, x, pos + 1);
        pair<double, long long> ret1 = {INT_MAX, INT_MAX};
        if (x - minus > x * cards[pos].st - minus + cards[pos].ft)
            ret1 = solve(mask | (1 << pos), minus - cards[pos].ft, x * cards[pos].st, pos + 1);
        return min(ret, ret1);
    }
    Solver(){
        cin >> n >> x;
        cards.resize(n);
        int minus = 0;
        forn(i, n){
            int a, b;
            cin >> a >> b;
            cards[i] = {a, 1 - b / 100.};
            minus += a;
        }
        auto ans = solve(0, minus, x, 0);
        // cout << ans.ft << '\n';
        long long ansmask = ans.st;
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
