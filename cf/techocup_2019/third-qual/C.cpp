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



int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    vec_in(arr);
    vector<vector<int>> dp(6, vector<int>(n, 0));
    vector<vector<int>> par(6, vector<int>(n, -1));
    repab(i, 1, 6) dp[i][0] = 1;
    repab(i, 1, n) {
        if (arr[i] == arr[i - 1]) {
            repab(j, 1, 6) {
                repab(k, 1, 6) {
                    if (j == k) continue;
                    if (dp[k][i - 1]) {
                        par[j][i] = k;
                        dp[j][i] = 1;
//                        break;
                    }
                }
//                if (dp[j][i]) break;
            }
        }
        if (arr[i - 1] < arr[i]) {
            repab(j, 1, 6) {
                repab(k, 1, j) {
                    assert(j != k);
                    if (dp[k][i - 1]) {
                        par[j][i] = k;
                        dp[j][i] = 1;
//                        break;
                    }
                }
//                if (dp[j][i]) break;
            }
        }
        if (arr[i - 1] > arr[i]) {
            repab(j, 1, 6) {
                repab(k, j + 1, 6) {
                    assert(j != k);
                    if (dp[k][i - 1]) {
                        par[j][i] = k;
                        dp[j][i] = 1;
//                        break;
                    }
                }
//                if (dp[j][i]) break;
            }
        }
    }
    int now = 0;
    for (now = 5; now >= 1; now--){
        if (dp[now][n - 1]) break;
    }
    if (now < 1){
        cout << -1;
        return 0;
    }
    int i = n - 1;
    vector<int> ans;
    while (now != -1){
        assert(i != -1);
        ans.push_back(now);
        now = par[now][i--];
    }
    reverse(all(ans));
    vec_out(ans);
}
