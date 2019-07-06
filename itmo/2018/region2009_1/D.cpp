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
#define vec_out(v) for (int adsada = 0; adsada < v.size(); adsada++) cout << v[adsada] << " \n"[adsada == v.size() - 1];
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

struct Point {
    ll x, y;

    Point() {}

    Point(ll _x, ll _y) : x(_x), y(_y) {}

    Point operator-(const Point &a) const {
        return {x - a.x, y - a.y};
    }

    Point operator+(const Point &a) const {
        return {x + a.x, y + a.y};
    }

    Point(Point a, Point b) {
        Point tmp = b - a;
        x = tmp.x;
        y = tmp.y;
    }

    ll len() {
        return x * x + y * y;
    }

    bool operator<(const Point &rhs) const {
        return tie(x, y) < tie(rhs.x, rhs.y);
    }
};

ll cross_p(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string FN = "triangle";
//    freopen((FN + ".in").c_str(), "r", stdin);
//    freopen((FN + ".out").c_str(), "w", stdout);
#endif
    int n;
    cin >> n;
    vector<Point> points(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ll a = (points[k] - points[j]).len(), b = (points[k] - points[i]).len(), c = (points[j] -
                                                                                              points[i]).len();
                if (a != b && b != c && a != c){
                    continue;
                }
                if (cross_p(points[j] - points[i], points[k] - points[i]) == 0) continue;
                ans++;
            }
        }
    }
    cout << ans << '\n';
}
