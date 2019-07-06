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
using ll = int64_t;
//------------------------------------------------------------------------------
#define int ll
bool if_pal(int a){
    string s = to_string(a);
    reverse(all(s));
    return s == to_string(a);
}

bool is_pr(int a){
    if (a == 1) return 0;
    int f = 2;
    for(; f * f <= a; f++){
        if (a % f == 0) return 0;
    }
    return 1;
}
int32_t main(){
    clock_t start = clock();
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int p, q;
    cin >> p >> q;
    int g = __gcd(p, q);
    p /= g;
    q /= g;
    int n = 0;
    int prime_count = 0;
    int palindrom = 0;
    int ans = 0;
    while (fabs(clock() - start * 1.) / CLOCKS_PER_SEC <= 2.7){
        ++n;
        prime_count += is_pr(n);
        palindrom += if_pal(n);
        if (prime_count * q <= palindrom * p){
            ans = n;
        }
        // prn(n, prime_count, is_pr(n), if_pal(n), palindrom );
    }
    cout << ans << '\n';
}
