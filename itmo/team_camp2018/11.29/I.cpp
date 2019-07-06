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
using ll = int64_t;
//------------------------------------------------------------------------------



int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    string s0;
    string t;
    cin >> s0 >> t;
    vector<int> type;
    const int STAR = 2;
    string s;
    for (char c : s0) {
        if (c == '+') {
            s += '?';
            type.push_back(STAR);
        } else if (c == '*') {
            type.back() = STAR;
        } else s += c, type.push_back(0);
    }
    int n = (int) s.size(), m = (int) t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[n][m] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m; j >= 0; --j) {
            if (type[i] == 0) {
                dp[i][j] = j < m && (s[i] == '?' || s[i] == t[j]) && dp[i + 1][j + 1];
            }
            if (type[i] == STAR) {
                dp[i][j] = (j < m && dp[i][j + 1]) || ((j == m || (j < m && s[i] == t[j])) && dp[i + 1][j]);
            }
        }
    }
    cout << s << '\n';
    for (int i : type) cout << i;
    cout << '\n';
//    for (auto i : dp){
//        for (auto j : i) cout << j << ' ';
//        cout << '\n';
//    }
    if (dp[0][0]) cout << "Yes\n";
    else cout << "No\n";
}
