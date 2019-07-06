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
#define cerr if (false) cerr
using namespace std;

int n, m;
vector<vector<pair<int, int>>> m1, m2;
vector<vector<int>> g, g1;
vector<int> comp, ans, sz, used;
inline void init(){

}
void eq_dfs(int v){
    used[v] = 1;
    cerr << v << ' ' << comp[v] << '\n';
    for (int u : g[v]){
        cerr << "\t" << u << ' ' << used[u] << '\n';
        if (used[u])
            continue;
        comp[u] = comp[v];
        eq_dfs(u);
    }
}
inline void solve(){
    m1.assign(n, vector<pair<int, int>>(m));
    m2.assign(m, vector<pair<int, int>>(n));
    g.assign(n * m, {});
    g1.assign(n * m, {});
    comp.assign(n * m, 0);
    used.assign(n * m, 0);
    iota(comp.begin(), comp.end(), 0);
    ans.assign(n * m, 0);
    sz.assign(n * m, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> m1[i][j].first;
            m1[i][j].second = i * m + j;
            m2[j][i] = m1[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        sort(m1[i].begin(), m1[i].end());
        for (int j = 0; j < m - 1; j++){
            if (m1[i][j].first == m1[i][j + 1].first){
                g[m1[i][j].second].push_back(m1[i][j + 1].second);
                g[m1[i][j + 1].second].push_back(m1[i][j].second);
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cerr << "(" << m1[i][j].first << ", " << m1[i][j].second << ')' << " \n"[j == m - 1];
    for (int i = 0; i < m; i++){
        sort(m2[i].begin(), m2[i].end());
        for (int j = 0; j < n - 1; j++){
            if (m2[i][j].first == m2[i][j + 1].first){
                g[m2[i][j].second].push_back(m2[i][j + 1].second);
                g[m2[i][j + 1].second].push_back(m2[i][j].second);
                cerr << m2[i][j].second << "==" << m2[i][j + 1].second << '\n';
            }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cerr << "(" << m2[i][j].first << ", " << m2[i][j].second << ')' << " \n"[j == n - 1];
    for (int i = 0; i < n * m; i++)
        if (!used[i])
            eq_dfs(i);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m - 1; j++){
            if (m1[i][j].first < m1[i][j + 1].first){
                g1[comp[m1[i][j].second]].push_back(comp[m1[i][j + 1].second]);
                cerr << comp[m1[i][j].second] << '<' << comp[m1[i][j + 1].second] << '\n';
                sz[comp[m1[i][j + 1].second]]++;
            }
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n - 1; j++){
            if (m2[i][j].first < m2[i][j + 1].first){
                g1[comp[m2[i][j].second]].push_back(comp[m2[i][j + 1].second]);
                cerr << comp[m2[i][j].second] << '<' << comp[m2[i][j + 1].second] << '\n';
                sz[comp[m2[i][j + 1].second]]++;
            }
        }
    }
    vector<int> now, nxt;
    for (int i = 0; i < n * m; i++){
        if (sz[i] == 0)
            now.push_back(i);
        cerr << sz[i] << " \n"[i == n * m - 1];
    }
    now.erase(unique(now.begin(), now.end()), now.end());
    int lvl = 1;
    while (!now.empty()){
        for (int v : now){
            cerr << v << ", " << ans[v] << "!! ";
            ans[v] = lvl;
            for (int u : g1[v]){
                --sz[u];
                if (sz[u] == 0)
                    nxt.push_back(u);
            }
        }
        cerr << '\n';
        swap(nxt, now);
        nxt.clear();
        lvl++;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cerr << "\t\t" << comp[i * m + j] << '\n';
            assert(ans[comp[i * m + j] != 0]);
            cout << ans[comp[i * m + j]] << " \n"[j == m - 1];
        }
}


int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
