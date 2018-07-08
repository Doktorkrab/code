#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int64_t INF = 1e18;
#endif

// -*-*-* All structures *-*-*-
struct Line {
    int64_t k, b;
};

struct Point {
    long double x, y;
    bool operator<(const Point &a) { return x < a.x; }
};
// -*-*-* All variables *-*-*-
vector<Line> stack_lines;
vector<Point> stack_points;
vector<int64_t> a, b, dp;

int n;

// -*-*-* All functions *-*-*-

Point intersect(Line a, Line b) {
    long double x = 1. * (b.b - a.b) / (a.k - b.k);
    long double y = a.k * x + a.b;
    return {x, y};
}
void insert(Line a) {
    while (!stack_lines.empty()) {
        auto lst_intersect = stack_points.back();
        auto lst_line = stack_lines.back();
        Point intr = intersect(a, lst_line);
        if (lst_intersect.x < intr.x) {
            stack_lines.push_back(a);
            stack_points.push_back(intr);
            return;
        }
        stack_points.pop_back();
        stack_lines.pop_back();
    }
    stack_lines.push_back(a);
    stack_points.push_back({1. * -INF, 1. * -INF});
}

int64_t get(int x) {
    int l = 0, r = stack_points.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (stack_points[m].x < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return stack_lines[l].b + stack_lines[l].k * x;
}
void init() {
    stack_lines.clear();
    stack_points.clear();
    a.clear();
    b.clear();
    dp.clear();
}

void solve() {
    init();
    cin >> n;
    a.resize(n);
    b.resize(n);
    dp.resize(n);
    for (int64_t &i : a)
        cin >> i;
    for (int64_t &i : b)
        cin >> i;
    insert({b[0], 0});
    for (int i = 1; i < n; i++) {
        dp[i] = get(a[i]);
        insert({b[i], dp[i]});
    }
    cout << dp.back() << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "E";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "lumber";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
#endif
    while (t--) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}