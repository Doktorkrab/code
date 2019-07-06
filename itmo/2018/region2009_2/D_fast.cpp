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
template <typename T>
void vec_out(const T &v) {
    auto end = v.end();
    --end;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " \n"[it == end];
    }
}

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


int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string FN = "perm";
    freopen((FN + ".in").c_str(), "r", stdin);
    freopen((FN + ".out").c_str(), "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    vec_in(arr);
    sort(all(arr));
    vector<vector<int>> dp(n, vector<int>(1 << n));
    for (int i = 0; i < n; i++) dp[i][(1 << n) - 1] = 1;
    for (int mask = (1 << n) - 1; mask >= 0; mask--){
        for (int last = 0; last < n; last++){
            if (!((1 << last) & mask)) continue;
            for (int nw = 0; nw < n; nw++){
                if ((1 << nw) & mask) continue;
                if (__gcd(arr[last], arr[nw]) < k) continue;
                dp[last][mask] += dp[nw][mask | (1 << nw)];
            }
        }
    }
    vector<int> ans(n);
    --m;
    int mask = 0;
    for (int i = 0; i < n; i++){
        int good = 0;
        for (int j = 0; j < n; j++){
            if (mask & (1 << j)) continue;
            if (i > 0 && __gcd(ans[i - 1], arr[j]) < k) continue;
            if (m < dp[j][mask | (1 << j)]){
                mask |= 1 << j;
                ans[i] = arr[j];
                good = 1;
                break;
            }
            else m -= dp[j][mask | (1 << j)];
        }
        if (!good){
            cout << "-1\n";
            return 0;
        }
    }
    vec_out(ans);
}
