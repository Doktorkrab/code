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
void deb(const ts &... b) {

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
using ll = uint64_t;
//------------------------------------------------------------------------------
//#define int ll
const int MAXN = 200;
const int MAXV = 101;
int arr[MAXN];
ll dp[MAXV][(MAXV - 1) * MAXN];
ll pr[MAXV][(MAXV - 1) * MAXN];
int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n, s, v;
    cin >> n >> s >> v;
//    --n;
    for (int i = 0; i < n - 1; i++) cin >> arr[i];
    assert(s >= 0);
    rep(i, v + 1) rep(j, s + 1) pr[i][j] = 1e18;
    rep(i, min(v, s) + 1) pr[i][i] = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= s; j++){
            for (int k = 0; k <= min(j, v); k++){
                dp[k][j] = 1e18;
                for (int x = 0; x <= v && k + x <= j; x++){
                    if (pr[x][j - k] >= 1e17) continue;
                    dp[k][j] = min(dp[k][j], pr[x][j - k] + 1LL * arr[i - 1] * x * k);
                }
            }
        }
        swap(pr, dp);
    }
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i <= v; i++) ans = min(ans, (ll)pr[i][s]);
    cout << ans << '\n';
}
