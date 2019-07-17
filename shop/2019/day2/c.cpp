#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>

#define ft first
#define sc second
#define pb push_back
#define len(v) (int)v.size()
 
using namespace std;
 
 
 
struct edge {
    int u, v;
    int i;
};
 
 
 
 
vector<int> ans(2e6 + 100);
int color = 1;
int ttime = 0;
 
int pluss1, pluss2;
int l, r, m;
 
vector<int> paint(2e6 + 100, 0);
vector<int> was(2e6 + 100, 0);
vector<vector<pair<int, int>>> g;
 
void dfs(int v, int cnt) {
    while(g[v].size() > 0) {
        auto neww = g[v].back();
        if(was[neww.sc] == ttime) {
            g[v].pop_back();
            continue;
        }
        was[neww.sc] = ttime;
        if(neww.sc != -1) {
            paint[neww.sc] = cnt;
        }
        g[v].pop_back();
        dfs(neww.ft, 3 - cnt);
    }
}
 
void make(vector<edge> edges, int N) {
    ttime++;
    if(edges.size() == 0) 
        return;
    if(N == 1) {
        for (auto x : edges) {
            ans[x.i] = color;
        }
        color++;
        return;
    }
    vector<int> rasm;
    for (auto x : edges) {
        rasm.pb(x.u);
        rasm.pb(x.v);
        g[x.v].pb({x.u, x.i});
        g[x.u].pb({x.v, x.i});
    }
    int mnew = m;
    int zero = 0;
    for (auto& i : rasm) {
        if(g[i].size() % 2 == 1) {
            if(i < l) {
                g[pluss2].pb({i, mnew});
                g[i].pb({pluss2, mnew});
                mnew++;
            }
            else {
                g[pluss1].pb({i, mnew});
                g[i].pb({pluss1, mnew});
                mnew++;
            }
        }
    }
    if(g[pluss1].size() % 2 == 1) {
        g[pluss1].pb({pluss2, mnew});
        g[pluss2].pb({pluss1, mnew});
        mnew++;
    }
 
    for (auto x : rasm) 
        dfs(x, 1);
    vector<edge> lft;
    vector<edge> rght;
    for (auto x : edges) {
        if(paint[x.i] == 1) 
            lft.pb(x);
        else
            rght.pb(x);
    }
    edges.clear();
    rasm.clear();
    make(lft, N / 2);
    make(rght, N / 2);
}   
 
 
 
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r >> m;
    vector<edge> edges(m);
    vector<int> g1(l + r, 0);
    vector<int> g2(l + r, 0);
    int maxx = 0;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].v >> edges[i].u;
        edges[i].u += l;
        edges[i].v--, edges[i].u--;
        edges[i].i = i;
        g1[edges[i].v]++;
        g2[edges[i].u]++;
        maxx = max(maxx, max(g1[edges[i].v], g2[edges[i].u]));
    }
    pluss1 = l + r, pluss2 = l + r + 1;
    g = vector<vector<pair<int, int>>> (pluss2 + 1);
    int N = 1;
    while(N < maxx)
        N *= 2;
    make(edges, N);
    //cout << endl;
    cout << color - 1 << endl;
    for (int i = 0; i < m; i++)
        cout << ans[i] << '\n';
}