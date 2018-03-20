// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

struct Solver{
    int n;
    vector<vector<pair<int, int>>> g;
    vector<int> size;
    int dfs(int v, int p = -1){
        size[v] = 1;
        int ans = 0;
        for (auto u : g[v]){
            if (u.first == p) continue;
            int tmp = dfs(u.first, v);
            size[v] += size[u.first];
            ans += tmp + 1LL * u.second * (n - size[u.first]) * size[u.first];
            // cout << v << ' ' << u.first << ' ' << u.second * (n - size[u.first]) * size[u.first] << ' ' << size[u.first] << '\n';
        }
        return ans;
    }
    Solver(int n) : n(n), size(n), g(n){
        for (int i = 0; i < n - 1;i++){
            int v, u, w;
            cin >> v >> u >> w;
            g[--v].push_back({--u, w});
            g[u].push_back({v, w});
        }
        // cout << '\n';
        int kek = dfs(0);
        // cout << kek << '\n';
        cout.precision(20);

        cout << fixed << kek * 2.0L / n / (n - 1.0L) << '\n';
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    Solver solver(n);
}