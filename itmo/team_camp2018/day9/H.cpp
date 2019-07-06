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

int ask(int v){
    cout << "? " << v + 1 << endl;
//    cout.flush();
    int ret;
    cin >> ret;
    if (ret == -2){
//        cout << "! No" << endl;
        exit(0);
    }
    return ret - 1;
}
vector<int> tin, fup;
vector<int> used;
int timer = 1;
vector<vector<int>> g;
set<pair<int, int>> br;
void dfs(int v, int p = -1){
    tin[v] = fup[v] = timer++;
    used[v] = 1;
    for (int u : g[v]){
        if (u == p) continue;
        if (!used[u]){
            dfs(u, v);
            fup[v] = min(fup[v], fup[u]);
        }
        else {
            fup[v] = min(fup[v], tin[u]);
        }
        if (fup[u] > tin[v]){
            br.insert({min(v, u) + 1, max(v, u) + 1});
        }
    }
}
int32_t main(){
#ifdef LOCAL
#else
//    ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    if (2 * (n - 1) < m){
//        assert(0);
        cout << "! No" << endl;
        return 0;
    }

    g.resize(n);
    used.resize(n);
    tin.resize(n);
    fup.resize(n);
    set<pair<int, int>> edges;
    set<pii> kratnoe;
    rep(i, n){
        int ret = ask(i);
        while (ret != -2){
            pii edge = {min(ret, i) + 1, max(ret, i) + 1};
            if (edges.count(edge)){
                kratnoe.insert(edge);
                ret = ask(i);
                continue;
            }
            edges.insert(edge);
            g[ret].push_back(i);
            g[i].push_back(ret);
            ret = ask(i);
        }
    }
    rep(i, n) if (!used[i]) dfs(i);
    for (auto i : kratnoe) br.erase(i);
    if (br.size() >= (m + 1) / 2) {
        cout << "! Yes\n";
        int cnt = 0;
        for (auto& i : br){
            cout << i.first << ' ' << i.second << '\n';
            cnt++;
            if (cnt == (m + 1) / 2) break;
        }
        cout.flush();
    }
    else{
        cout << "! No" << endl;
    }

}
