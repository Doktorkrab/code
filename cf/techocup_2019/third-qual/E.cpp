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
using ll = uint64_t;
//------------------------------------------------------------------------------

int MAXN = 100;
int MAXC = 10000;
bool is_prime(ll x){
    if (x <= 1) return 0;
    for (int f = 2; f * f <= x; f++){
        if (x % f == 0) return 0;
    }
    return 1;
}
int32_t main(){
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    ll MOD = rand((int)1e9, (int) 2e9);
    while (!is_prime(MOD)) MOD++;
    vector<int> arr(n);
    vec_in(arr);

    vector<int> cnt(101);
    unordered_set<int> kek;
    for (int i : arr) cnt[i]++, kek.insert(i);
    vector<vector<ll>> cnk(n + 1, vector<ll>(n + 1));
    for (int i = 0; i <= n; i++){
        cnk[i][0] = 1;
        for (int j = 1; j <= n && i > 0; j++){
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % MOD;
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(MAXC + 1)), dp1(n + 1, vector<ll>(MAXC + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        dp1 = dp;
        for (int cnt = 1; cnt <= n; cnt++){
            for (int w = arr[i]; w <= MAXC; w++){
                dp1[cnt][w] += dp[cnt - 1][w - arr[i]];
                dp1[cnt][w] %= MOD;
            }
        }
        swap(dp, dp1);
    }
    int ans = 1;
    for (int i = 1; i <= 100; i++){
        for (int j = ans; j <= cnt[i]; j++){
            if (dp[j][j * i] == cnk[cnt[i]][j]) {
                ans = j;
            }
        }
    }

    if (kek.size() == 2){
        cout << n << '\n';
        return 0;
    }
    cout << ans << '\n';

}
