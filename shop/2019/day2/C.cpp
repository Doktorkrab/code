#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

struct Edge{
    int from, to, id;
};
const int MAXN = 2e6 + 7;
int paint[MAXN], ans[MAXN];
int ban[MAXN];
vector<vector<pair<int, int>>> g;
int color = 1, iter = 0;

int l, r, m, FAKE_LEFT, FAKE_RIGHT;

inline void init(){
    g.resize(l + r + 2, {});
    FAKE_LEFT = l + r;
    FAKE_RIGHT = l + r + 1;
}

void dfs(int v, int cl){
    while (!g[v].empty()){
        auto tmp = g[v].back();
        g[v].pop_back();
        if (ban[tmp.second] == iter)
            continue;
        ban[tmp.second] = iter;
        paint[tmp.second] = cl;
        dfs(tmp.first, 3 - cl);
    }
}

void rec(vector<Edge>& edges, int degree){
    if (edges.empty())
        return;
    if (degree == 1){
        for (auto e : edges)
            ans[e.id] = color;
        color++;
        return;
    }

    vector<int> vertexes;
    int m1 = m;
    for (const Edge& e : edges){
        vertexes.push_back(e.from);
        vertexes.push_back(e.to);
        g[e.from].emplace_back(e.to, e.id);
        g[e.to].emplace_back(e.from, e.id);
    }

    for (int v : vertexes){
        if (g[v].size() % 2 == 0)
            continue;
        if (v < l){
            g[v].emplace_back(FAKE_LEFT, m1);
            g[FAKE_LEFT].emplace_back(v, m1++);
        } else {
            g[v].emplace_back(FAKE_RIGHT, m1);
            g[FAKE_RIGHT].emplace_back(v, m1++);
        }
    }
    if (g[FAKE_LEFT].size() % 2){
        g[FAKE_LEFT].emplace_back(FAKE_RIGHT, m1);
        g[FAKE_RIGHT].emplace_back(FAKE_LEFT, m1++);
    }

    iter++;
    for (int i : vertexes)
        dfs(i, 1);

    vector<Edge> lft, rgt;
    for (auto x : edges){
        if (paint[x.id] == 1)
            lft.push_back(x);
        else
            rgt.push_back(x);
    }
    rec(lft, degree / 2);
    rec(rgt, degree / 2);
}

inline void solve(){
    init();
    vector<Edge> edges(m);
    vector<int> g1(l), g2(r);
    int mx = 0;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        edges[i] = {a, b + l, i};
        // cerr << g1.size() << ' ' << a << ' ' << g2.size() << ' ' << b << '\n';
        mx = max(max(++g1[a], ++g2[b]), mx);
    }
    int max_degree = 1;
    while (max_degree < mx)
        max_degree <<= 1;

    rec(edges, max_degree);
    cout << color - 1 << '\n';
    for (int i = 0; i < m; i++)
        cout << ans[i] << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> l >> r >> m)
        solve();

}