#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <string>
#include <cassert>

using namespace std;

mt19937 rnd((uint64_t) new char);

int64_t rand(int64_t x, int64_t y) { return rnd() % (y - x + 1) + x; }

template<typename t>
t min(t a) {
    return a;
}

template<typename t, typename... ts>
t min(const t &a, const ts &... as) {
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}

template<typename t>
t max(t a) {
    return a;
}

template<typename t, typename... ts>
t max(const t &a, const ts &... as) {
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}

void prn(ostream &os) {
    os << '\n';
}

void prn() {
    cout << '\n';
}

template<typename t, typename... ts>
void prn(ostream &os, const t &a, const ts &... b) {
    os << a << ' ';
    prn(os, b...);
}

template<typename t, typename... ts>
void prn(const t &a, const ts &... b) {
    cout << a << ' ';
    prn(cout, b...);
}

#ifdef LOCAL

template<typename... ts>
void deb(const ts &... b) {
    prn(cerr, "DEBUG", b...);
}

#else
template<typename... ts>
void deb(const ts&... b){

}
#endif

#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------
#define int ll


int32_t main(){
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int t;
    cin >> t;
    while (t--){
        int d0, d1, k;
        cin >> k >> d1 >> d0;
        ll x = d0 + d1 * k;
        if (x % (k + 1) == 0 && x / (k + 1) <= 2 * (k - 1)){
            prn("YES");
            ll a0 = (x / (k + 1) / 2);
            ll b0 = ((x / (k + 1) + 1) / 2);
            if (a0 == 0) prn(1, a0);
            else prn(2, a0, a0);
            prn(2, b0, b0);
            continue;
        }
        if (x <= 2 * (k - 1)){
            prn("YES");
            ll a0 = (x / 2);
            ll b0 = ((x + 1) / 2);
            prn(1, a0);
            prn(1, b0);
            continue;
        }
        if (d1 + 1 <= k - 1){
            ll a0 = x - k * (d1 + 1) - d1 - 1;
            if (a0 >= 0 && a0 <= k - 1){
                prn("YES");
                prn(1, a0);
                prn(2, d1 + 1, d1 + 1);
                continue;
            }
        }
        ll a0 = x - d1 * k - d1;
        if (a0 >= 0 && a0 <= k - 1){
            prn("YES");
            prn(1, a0);
            prn(2, d1, d1);
            continue;
        }
        if (d1 - 1 >= 0){
            ll a0 = x - k * (d1 - 1) - d1 + 1;
            if (a0 >= 0 && a0 <= k - 1){
                prn("YES");
                prn(1, a0);
                prn(2, d1 - 1, d1 - 1);
                continue;
            }
        }
        prn("NO");
    }
}
