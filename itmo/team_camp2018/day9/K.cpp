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

struct Vertex{
    int x, y, left, right;
};

vector<vector<char>> fld;
vector<vector<int>> used;
int n, m;
int check(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && used[x][y] == 0 && fld[x][y] != '*';
}
void bfs(Vertex st){
    deque<Vertex> q = {st};
    while (!q.empty()){
        Vertex pop = q.front();
        q.pop_front();
        if (used[pop.x][pop.y] == 1) continue;
        used[pop.x][pop.y] = 1;
        if (check(pop.x - 1, pop.y)) q.push_front({pop.x - 1, pop.y, pop.left, pop.right});
        if (check(pop.x + 1, pop.y)) q.push_front({pop.x + 1, pop.y, pop.left, pop.right});
        if (check(pop.x, pop.y + 1) && pop.right >= 1) q.push_back({pop.x, pop.y + 1, pop.left, pop.right - 1});
        if (check(pop.x, pop.y - 1) && pop.left >= 1) q.push_back({pop.x, pop.y - 1, pop.left - 1, pop.right});
    }
}
int32_t main(){
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    cin >> n >> m;
    fld.assign(n, vector<char>(m));
    used.assign(n, vector<int>(m, 0));

    Vertex st = {0, 0, 0, 0};
    cin >> st.x >> st.y >> st.left >> st.right;
    st.x--, st.y--;
    rep(i, n) rep(j, m) cin >> fld[i][j];
    bfs(st);
    int ans = 0;
//    for (auto i : used){
//        vec_out(i);
//    }
//    cout << fld[1][1];
    rep(i, n) rep(j, m) ans += used[i][j];
    prn(ans);
}
