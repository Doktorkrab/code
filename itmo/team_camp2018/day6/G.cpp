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
    freopen("marks.in", "r", stdin);
    freopen("marks.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int type[7] = {0, 0, 0, 0, 0, 0, 0};
    rep(i, n) {
        string s;
        cin >> s;
        if (s == "-" || s == "2") {
            cout << "1\n";
            return 0;
        }
        if (s == "0") {
            type[0] = 1;
            continue;
        }
        if (s == "+") {
            type[1]++;
            continue;
        }
        int num = stoi(s);
        if (num >= 8) type[2]++;
        if (num >= 6) type[3]++;
        if (4 <= num && num <= 5) type[4]++;
    }
    if (type[0]) {
        cout << "2\n";
        return 0;
    }
//    for (int i = 0; i < 7; i++) cout << type[i] << ' ';
//    cout << '\n';
    if (type[1] == n) {
        cout << "3\n";
        return 0;
    }
    if (type[2] + type[1] == n) {
        cout << "4\n";
        return 0;
    }
    if (type[3] + type[1] == n) {
        cout << "5\n";
        return 0;
    }
    if (type[4] + type[1] == n) {
        cout << "6\n";
        return 0;
    }
    cout << 7 << "\n";
}
