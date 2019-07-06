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
const int MAXN = 1e3;
int dp[MAXN][2 * MAXN + 1][4];
const int MOD = 998244353;
int32_t main(){
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n, k;
    cin >> n >> k;
    dp[0][1][0b00] = 1;
    dp[0][2][0b01] = 1;
    dp[0][2][0b10] = 1;
    dp[0][1][0b11] = 1;
    for (int i = 1; i < n; ++i) {
        // cout << "i: " << i << '\n';
        for (int j = 1; j <= k; j++){
            dp[i][j][0b00] = ((dp[i - 1][j][0b00] + dp[i - 1][j][0b10]) % MOD + dp[i - 1][j][0b01]) % MOD;
            dp[i][j][0b11] = ((dp[i - 1][j][0b11] + dp[i - 1][j][0b10]) % MOD + dp[i - 1][j][0b01]) % MOD;
            dp[i][j][0b01] = (dp[i - 1][j][0b01]) % MOD;
            dp[i][j][0b10] = (dp[i - 1][j][0b10]) % MOD;
            if (j - 1 > 0){
                dp[i][j][0b00] += dp[i - 1][j - 1][0b11];
                dp[i][j][0b00] %= MOD;
                dp[i][j][0b11] += dp[i - 1][j - 1][0b00];
                dp[i][j][0b11] %= MOD;
                dp[i][j][0b01] += (dp[i - 1][j - 1][0b00] + dp[i - 1][j - 1][0b11]) % MOD;
                dp[i][j][0b01] %= MOD;
                dp[i][j][0b10] += (dp[i - 1][j - 1][0b00] + dp[i - 1][j - 1][0b11]) % MOD;
                dp[i][j][0b10] %= MOD;
            }
            if (j - 2 > 0){
                dp[i][j][0b10] += dp[i - 1][j - 2][0b01];
                dp[i][j][0b10] %= MOD;
                dp[i][j][0b01] += dp[i - 1][j - 2][0b10];
                dp[i][j][0b01] %= MOD;
            }
            // prn("j:",j,"\n\t", dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]);

        }
    }
    int ans = 0;
    for (int i = 0;i < 4; i++) {
        ans += dp[n - 1][k][i];
        ans %= MOD;
    }
    cout << ans << '\n';
}
