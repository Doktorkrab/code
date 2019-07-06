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
#include <iomanip>

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

struct Point {
    int x, y;

    friend istream &operator>>(istream &os, Point& point) {
        os >> point.x >> point.y;
        return os;
    }
};



struct Line {
    int a, b, c;

    Line(const Point &p1, const Point &p2) {
        this->a = p1.y - p2.y;
        this->b = p2.x - p1.x;
        this->c = -this->a * p1.x - this->b * p1.y;
    }
    Line () {}
};

Line a, b;

double f(double h) {
    double x1 = -(a.b * h + a.c) / a.a;
    double x2 = -(b.b * h + b.c) / b.a;
    return fabs(x2 - x1) * h;
}


int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    Point p1, p2, p3;
//    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p
    cin >> p1 >> p2 >> p3;
    a = Line(p1, p2);
    b = Line(p1, p3);
    double l = max(p2.y, p3.y);
    double r = p1.y;
    for (int i = 0; i < 1e6; ++i) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    cout.setf(ios::fixed);
    cout << setprecision(20) << f(l) << '\n';
//    cout << f(l) << '\n';
}
