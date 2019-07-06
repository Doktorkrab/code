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

vector<vector<int>> g, g1;
vector<int> comps;
vector<vector<int>> comp;
int dfs(int v, int color){
    comps[v] = color;
    comp[color].push_back(v);
    for (int u : g[v]){
        if (comps[u] != -1) continue;
        dfs(u, color);
    }
}
int32_t main(){
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    g.resize(n);
    g1.resize(n);
    comps.assign(n, -1);
    rep(i, m){
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }

    cin >> m;
    rep(i, m){
        int v, u;
        cin >> v >> u;
        g1[--v].push_back(--u);
        g1[u].push_back(v);
    }
    int cl = 0;
    rep(i, n){
        if (comps[i] == -1) comp.push_back({}), dfs(i, cl++);
    }
    int ans = 0;
    for (int i = 0; i < cl; i++){
        int good = 1;
        for (int j : comp[i]){
            for (int k : g1[j]){
                if (comps[j] == comps[k]){
                    good = 0;
                    break;
                }
            }
            if (!good) break;
        }
//        prn(good);
//        cout << "\t";
//        vec_out(comp[i]);
        if (good) ans = max(ans, comp[i].size());
    }
    cout << ans << '\n';

}
