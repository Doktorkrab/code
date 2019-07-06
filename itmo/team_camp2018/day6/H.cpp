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

int n, m;
int timer = 0;
vector<int> up, tin;
vector<bool> used;

struct Edge {
    int to;
    bool bridge;
    int rev;
};
vector<vector<Edge>> g;

void dfs(int v, int p) {
    up[v] = tin[v] = timer++;
    used[v] = 1;
    for (Edge &u : g[v]) {
        if (u.to == p) continue;
        if (used[u.to]) {
            up[v] = min(up[v], tin[u.to]);
        } else {
            dfs(u.to, v);
            up[v] = min(up[v], up[u.to]);
        }
        if (up[u.to] > tin[v]) {
            u.bridge = 1;
            g[u.to][u.rev].bridge = 1;
        }
    }
}
int cnt = 0;

void dfs2(int v){
    used[v] = 1;
    for (Edge& e : g[v]){
        if (!used[e.to] && !e.bridge) dfs2(e.to);
        if (e.bridge) cnt++;
    }
}
int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("system.in", "r", stdin);
    freopen("system.out", "w", stdout);
#endif
    cin >> n >> m;
    g.resize(n);
    tin.resize(n);
    up.resize(n);
    used.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        int ind = g[v].size(), ind1 = g[u].size();
        g[v].push_back({u, 0, ind1});
        g[u].push_back({v, 0, ind});
    }
    rep(i, n) if (!used[i]) dfs(i, -1);
    used.assign(n, 0);
    int ans = 0;
    rep(i, n){
        if (!used[i]){
            cnt = 0;
            dfs2(i);
            if (cnt <= 1) ans++;
        }
    }
    prn(ans);
}
