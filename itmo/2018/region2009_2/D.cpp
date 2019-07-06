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

vector<int> arr, used, used1, rdy;
vector<vector<int>> g;
int n, m, k;

int dfs(int v) {
    used1[v] = 1;
    int cnt = 1;
    for (int u : g[v]) {
        if (!used1[u]) cnt += dfs(u);
    }
    return cnt;
}

void gen(int pos) {
    if (pos == n) {
        --m;
            for (int i = 0; i < n; i++) cout << arr[rdy[i]] << " \n"[i == n - 1];
//            exit(0);
        return;
    }
    if (pos == 0) {
        for (int i = 0; i < n; i++) {
            used1 = used;
            if (pos + dfs(i) != n) continue;
            used[i] = 1;
            rdy[pos] = i;
            gen(pos + 1);
            used[i] = 0;
        }
        return;
    }
    for (int u : g[rdy[pos - 1]]) {
        if (used[u]) continue;
        used1 = used;
        if (pos + dfs(u) != n) continue;
        used[u] = 1;
        rdy[pos] = u;
        gen(pos + 1);
        used[u] = 0;
    }
}

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string FN = "perm";
    freopen((FN + ".in").c_str(), "r", stdin);
    freopen((FN + ".out").c_str(), "w", stdout);
#endif
//    int n, m, k;
    cin >> n >> m >> k;
    arr.resize(n);
    used.resize(n);
    used1.resize(n);
    g.resize(n);
    rdy.resize(n);
    vec_in(arr);
    sort(all(arr));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (__gcd(arr[i], arr[j]) >= k) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    gen(0);
    cout << "-1\n";
}
