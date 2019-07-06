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

template<typename T>
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



int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string FN = "parade";
    freopen((FN + ".in").c_str(), "r", stdin);
    freopen((FN + ".out").c_str(), "w", stdout);
#endif
    vector<int> primes(1e7 + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i <= 1e7; i++) {
        if (!primes[i]) continue;
        for (int j = i; 1LL * j * i <= 1e7; j++) primes[i * j] = 0;
    }
//    cout << INT_MAX << '\n';
    int n, k;
    cin >> k >> n;
    if (k > n * n) {
        cout << "-1\n";
        return 0;
    }

//    ll minus_n = 0;
//    ll minus_n_1 = 0;
//    ll n_sqr = n * n - k;
//    vector<int> types(n, -1);
//    if (n_sqr != 0) {
//        int good = 0;
//        for (minus_n_1 = 1; minus_n_1 <= n; minus_n_1++) {
//            ll tmp_k = n_sqr - minus_n_1 * (n - 1);
//            if (tmp_k < 0) continue;
//            cout << tmp_k << ' ' << minus_n_1 * (n - 1) << '\n';
//            if (tmp_k % n == 0 && tmp_k / n + minus_n_1 <= n) {
//                int i;
//                minus_n = tmp_k / n;
//                for (i = 0; i < minus_n_1; i++) types[i] = 0;
//                for (int j = 0; j < minus_n; j++) types[i + j] = 1;
//                good = 1;
//                break;
//            }
//        }
//        if (!good){
//            cout << "-1\n";
//            return 0;
//        }
//    }
//    vector<int> arr(n * n);
//    vector<int> primes_1(k);
//
//    int cur = 0;
//    rep(i, k) {
//        while (cur <= 1e7 && !primes[cur]) cur++;
//        if (cur > 1e7) {
//            cout << "-1\n";
//            return 0;
//        }
//        primes_1[i] = cur++;
//    }
//    vector<vector<int>> fld(n, vector<int>(n));
//
//    rep(i, n * n) {
//        fld[i / n][i % n] = i;
//    }
//    rep(i, n) {
//        if (types[i] == 0 || types[i] == -1) continue;
//        if (types[i] == 1) fld[0][i] = fld[0][i - 1];
//    }
//    repab(i, 1, n) {
//        rep(j, n) {
//            int type = ((n - i) + j) % n;
//            if (types[type] == -1) continue;
//            fld[i][j] = fld[0][type];
//        }
//    }
//    int now = 0;
//    unordered_map<int, int> used;
//    rep(i, n){
//        rep(j, n){
//            if (!used.count(fld[i][j])) used[fld[i][j]] = primes_1[now++];
//            fld[i][j] = used[fld[i][j]];
//        }
//    }
//    for (auto& i : fld) vec_out(i);
    vector<int> pr_1;
    for (int i = 0; i <= 1e7; i++) if (primes[i]) pr_1.push_back(i);
    if (pr_1.size() < k) {
        cout << "-1\n";
        return 0;
    }
    if (k <= n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << pr_1[(i + j) % k] << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    for (int i = 0; i < n * n; i++){
        if (n * n - i > k - n){
            cout << pr_1[(i + i / n) % n] << ' ';
        }
        else {
            cout << pr_1[n * n - 1 - i + n] << ' ';
        }
        if ((i + 1) % n == 0) cout << '\n';
    }
}
