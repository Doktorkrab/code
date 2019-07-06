#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
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
using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------

const int MAXN = 2e5;
const int MAXLOG = 25;
pair<int, int> sparse[MAXLOG][4 * MAXN];
int logs[4 * MAXN];
int mark[MAXN];
vector<pair<int, int>> euler;
vector<vector<pair<int, int>>> g;
vector<int> id(MAXN, -1);
void dfs(int v, int d, int p = -1){
    id[v] = euler.size();
    euler.push_back({d, v});
    for (auto u : g[v]){
        if (u.first == p) continue;
        dfs(u.first, d + 1, v);
        euler.push_back({d, v}); 
    }
}

void build(){
    for (int i = 0; i < (int) euler.size(); i++) sparse[0][i] = euler[i];
    for (int l = 1; l < MAXLOG; l++){
        for (int i = 0; (i + (1 << (l - 1))) < (int) euler.size(); i++) sparse[l][i] = min(sparse[l - 1][i], sparse[l - 1][i + (1 << (l - 1))]);
    }
}

int get(int a, int b){
    a = id[a];
    b = id[b];
    if (a > b) swap(a, b);
    int len = b - a + 1;
    int power = logs[len];
    return min(sparse[power][a], sparse[power][b - (1 << power) + 1]).second;

}

vector<int> ans(MAXN);
int sum(int num, int v, int p = -1){
    int sm = mark[v];
    for (auto u : g[v]){
        if (u.first == p) continue;
        sm += sum(u.second, u.first, v);
    }
    if (num != -1) ans[num] = sm;
    return sm;
}
int32_t main(){
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    for (int i = 2; i < 4 * MAXN; i++) logs[i] = logs[i / 2] + 1;
    int n;
    cin >> n;
    g.resize(n);
    rep (i, n - 1){
        int v, u;
        cin >> v >> u;
        g[--v].push_back({--u, i});
        g[u].push_back({v, i});
    }
    dfs(0, 0);
    build();
    int k;
    cin >> k;
    rep(i, k){
        int a, b;
        cin >> a >> b;
        --a, --b;
        int lca = get(a, b);
        mark[a]++;
        mark[b]++;
        // cout << get(a, b) << '\n';
        mark[lca] -= 2;
    }
    sum(-1, 0);
    rep(i, n - 1) cout << ans[i] << ' ';
    cout << '\n';
}
