#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
// using double = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
// const double EPS = 1e-18;
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
struct Vector{
    double x, y;
    double vector_product(Vector a){
        return x * a.y - y * a.x;
    }
    double scalar_product(Vector a){
        return x * a.x + y * a.y;
    }
    double angle(Vector b) {
    return atan2(vector_product(b), scalar_product(b));
  }
};
istream& operator>> (istream& stream, Vector& v) {
    stream >> v.x >> v.y;
    return stream;
}
struct Solver{
    Solver(){
        Vector a, b, c;
        cin >> a >> b >> c;
        Vector ab = {b.x - a.x, b.y - a.y};
        Vector bc = {c.x - b.x, c.y - b.y};
        Vector ac = {c.x - a.x, c.y - a.y};
        Vector ba = {a.x - b.x, a.y - b.y};
        double an1 = ab.angle(ac), an2 = bc.angle(ba);
        Vector a1, b1, c1;
        cin >> a1 >> b1 >> c1;
        ab = {b1.x - a1.x, b1.y - a1.y};
        bc = {c1.x - b1.x, c1.y - b1.y};
        ac = {c1.x - a1.x, c1.y - a1.y};
        ba = {a1.x - b1.x, a1.y - b1.y};
        double an11 = ab.angle(ac), an12 = bc.angle(ba);
        if (abs(an11) == abs(an1) && abs(an12) == abs(an2)){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }   
};


// CODE END

int main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    freopen("twotri.in", "r", stdin);
    freopen("twotri.out", "w", stdout);
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
