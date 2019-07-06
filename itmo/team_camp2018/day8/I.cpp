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
#define vec_out(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " \n"[i == v.size() - 1];
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



int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("i.in", "r", stdin);
    freopen("i.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ll> types(n), plus(n), dp(n, LLONG_MAX / 4);
    ll a, b;
    rep(i, n) {
        char c;
        cin >> c;
        if (i) plus[i] = plus[i - 1];
        if (c == '-') types[i] = 1;
        else plus[i]++;
    }
    cin >> a >> b;
    ll minrel = LLONG_MAX / 4;
    rep(i, n){
        if (types[i]){
            if (i) dp[i] = dp[i - 1];
            else dp[i] = 0;
            dp[i] += a;
        }
        else{
            if (i) dp[i] = dp[i - 1];
            else dp[i] = 0;
        }
        dp[i] = min(dp[i], a * plus[i] + b + minrel + a);
        minrel = min(minrel, (i ? dp[i - 1] : 0) - a * (i ? plus[i - 1] : 0));
    }
    cout << dp[n - 1];

}
