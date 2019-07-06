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

vector<vector<int>> g;
vector<vector<int>> dists;
void bfs(int i, int st){
    deque<int> q = {st};
    dists[i][st] = 0;
    while (!q.empty()){
        int top = q.front();
        q.pop_front();
        for (int u : g[top]){
            if (dists[i][u] > dists[i][top] + 4){
                dists[i][u] = dists[i][top] + 4;
                q.push_back(u);
            }
        }
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
    dists.assign(2, vector<int>(n, 1e9));
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b, --c;
    bfs(0, a);
    bfs(1, c);
    cout << dists[0][b] + min(dists[1][a], dists[1][b]) + 10 << '\n';
}
