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
#include <climits>
using namespace std;

int n;
const int MAXN = 1e5 + 7;
vector<int> g[MAXN];
vector<int> ans;
int c[MAXN];
inline void init(){
    for (int i = 0; i < n; i++)
        g[i].clear();
    memset(c, 0, sizeof(int) * MAXN);
}
int dfs(int v, int p){
    int cnt = c[v];
    for (int u : g[v]){
        if (u == p)
            continue;
        cnt += c[u];
    }
    if (cnt != g[v].size() || c[v] == 0){
        for (int u : g[v])
            if (u != p)
                dfs(u, v);
        return INT_MAX;
    }
    int mx = -1;
    for (int u : g[v]){
        if (u == p)
            continue;
        mx = max(mx, dfs(u, v));
    }
    if (mx != -1 && mx < v){
        return INT_MAX;
    }
    ans.push_back(v);
    return mx;
}
inline void solve(){
    int root = -1;
    for (int i = 0; i < n; i++){
        int p, cc;
        cin >> p >> cc;
        --p;
        if (p < 0){
            root = i;
            continue;
        }
        c[i] = cc;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(root, -1);
    sort(ans.begin(), ans.end());
    if (ans.size() == 0){
        cout << "-1\n";
        return;
    }
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
