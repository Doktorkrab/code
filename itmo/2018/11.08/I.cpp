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

using namespace std;

mt19937 rnd((uint64_t) new char);
int64_t rand(int64_t x, int64_t y){ return rnd() % (y - x + 1) + x; }
template<typename t>
t min(t a){
    return a;
}
template<typename t, typename... ts>
t min(const t& a, const ts&... as){
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}
template<typename t>
t max(t a){
    return a;
}
template<typename t, typename... ts>
t max(const t& a, const ts&... as){
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}
void prn(ostream& os){
    os << '\n';
}
void prn(){
    cout << '\n';
}
template<typename t, typename... ts>
void prn(ostream& os, const t& a, const ts&... b){
    os << a << ' ';
    prn(os, b...);
}
template<typename t, typename... ts>
void prn(const t& a, const ts&... b){
    cout << a << ' ';
    prn(cout, b...);
}
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

vector<vector<int>> g;
vector<pair<int, int>> euler;
vector<int> id;

void dfs(int v, int p,int d = 0){
    id[v] = (int)euler.size();
    euler.emplace_back(d, v);
    for (int u : g[v]){
        if (u == p) continue;
        dfs(u, v, d + 1);
        euler.emplace_back(d, v);
    }

}
const int MAXLOG = 5;
vector<vector<pair<int, int>>> sparse;
vector<int> logs(2e5);
void build(){
    sparse.assign(MAXLOG, vector<pair<int, int>>(euler.size()));
    sparse[0] = euler;
//    cout << "0:";
//    for (auto i : sparse[0]) cout << "(" << i.first << ", " << i.second << ") ";
//    cout << "\n";
    for (int log = 1; log < MAXLOG; log++){
        cout << log << ":";
        for (int i = 0; i + (1 << (log - 1)) < (int) euler.size(); i++){
            sparse[log][i] = min(sparse[log - 1][i], sparse[log - 1][i + (1 << (log - 1))]);
//            cout << "(" << sparse[log][i].first << ", " << sparse[log][i].second << ") ";
        }
//        cout << '\n';
    }
    logs[2] = 1;
    for (int i = 3; i < (int) logs.size(); i++) logs[i] = logs[i / 2] + 1;
}

int get(int a, int b){
    a = id[a];
    b = id[b];
    if (a > b) swap(a, b);
    int len = b - a + 1;
    int power = logs[len];
    return min(sparse[power][a], sparse[power][b - (1 << power) - 1]).second;
}


int32_t main(){
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n, m;
    cin >> n;
    g.resize(n);
    id.resize(n);
    repab(i, 1, n){
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    dfs(0, -1, 0);
    build();
    cin >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        cout << get(--a, --b) + 1<< '\n';
    }
}
