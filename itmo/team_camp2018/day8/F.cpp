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
#include <deque>

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
#define vec_out(v) for (int asdasdsad = 0; asdasdsad < v.size(); asdasdsad++) cout << v[asdasdsad] << " \n"[asdasdsad == v.size() - 1];
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
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> fld(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> fld[i][j];
        }
    }
    vector<vector<pii>> shift = {
            {{0, 0}, {1,  0},  {0,  1}, {1,  1}},
            {{0, 0}, {0,  1},  {-1, 0}, {-1, 1}},
            {{0, 0}, {0,  -1}, {-1, 0}, {-1, -1}},
            {{0, 0}, {0, -1},  {1, -1}, {1,  0}}};
    auto check = [&](int i, int j) -> int {
        int cnt = 0;
        if (fld[i][j] == '#') return 2;
        for (auto square : shift){
            cnt = 0;
            for (auto sh : square){
                int x = i + sh.first, y = j + sh.second;
                if (0 <= x && x < n && 0 <= y && y < m) cnt += fld[x][y] == '#';
            }
            if (cnt >= 3) return 1;
        }
        return 0;
    };
    deque<pii> q;
    rep(i, n) {
        rep(j, m) {
            if (check(i, j) == 1) q.push_back({i, j});
        }
    }
    while (!q.empty()) {
        auto pop = q.front();
        q.pop_front();
        int x = pop.first, y = pop.second;
        if (check(x, y) != 1) continue;
        fld[x][y] = '#';
        repab(sh_x, -1, 2) {
            repab(sh_y, -1, 2) {
                int nx = x + sh_x, ny = y + sh_y;
                if (0 <= nx && nx < n && 0 <= ny && ny < m && fld[nx][ny] == '.') q.push_back({nx, ny});
            }
        }
    }

    int ans = 0;
//    for (auto i : fld) {
//        vec_out(i);
//    }
//    cout << check(1, 1) << '\n';
    rep(i, n) rep(j, m) ans += fld[i][j] == '#';
    cout << ans << '\n';

}
