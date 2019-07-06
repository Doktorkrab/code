#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
mt19937 rnd((uint64_t) new char);
int64_t rand(int64_t x, int64_t y){ return rnd() % (y - x + 1) + x; }
template<typename t>
t min(t a){
    return a;
}
template<typename t, typename... ts>
t min(const t& a, const ts&... as){
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}
template<typename t>
t max(t a){
    return a;
}
template<typename t, typename... ts>
t max(const t& a, const ts&... as){
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}
void prn(ostream& os){
    os << '\n';
}
void prn(){
    cout << '\n';
}
template<typename t, typename... ts>
void prn(ostream& os, const t& a, const ts&... b){
    os << a << ' ';
    prn(os, b...);
}
template<typename t, typename... ts>
void prn(const t& a, const ts&... b){
    cout << a << ' ';
    prn(cout, b...);
}
#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = uint64_t;
//------------------------------------------------------------------------------



int32_t main(){
    #ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif
    ll n, m, k;
    cin >> n >> m >> k;
    if ((2 * n * m) % k != 0){
        cout << "NO\n";
        return 0;
    }
    ll need_sqr = 2LL * n * m / k;
    if (n % k){
        ll a = need_sqr / n;
        if (a > m){
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n0 0\n0 " << a << "\n";
        cout << n << " 0\n";
    }
    else{
        ll a = need_sqr / m;
        if (a > n){
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n0 0\n0 " << m << '\n';
        cout << a << " 0\n";
    }
}
