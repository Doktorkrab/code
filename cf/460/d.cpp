#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> used;
vector<int> kek;
string s;
int ans = 0;
int dfs(int v, char c){
    used[v] = 1;
    int tmp = kek[v] = (c == s[v]);
    for (int u : g[v]){
        if (used[u] == 1){
            cout << -1;
            exit(0);
        }
        if (used[u] == 2){
            kek[v] = max(kek[v], kek[u] + tmp);
        }
        else{
            kek[v] = max(kek[v], dfs(u, c) + tmp);
        }
    }
    ans = max(ans, kek[v]);
    used[v] = 2;
    return kek[v];
}
int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    cin >> s;
    for (int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }
    for (char i = 'a';i <= 'z';i++){
        used.assign(n, 0);
        kek.assign(n, 0);
        for (int v = 0;v < n;v++){
            if (!used[v]) dfs(v, i);
        }
    }
    cout << ans << '\n';

}