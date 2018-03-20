#include <bits/stdc++.h>
using namespace std;

vector<bool> used(26);
vector<vector<char>> g('z' + 1);
vector<pair<char, char>> ans;
void dfs(char v){
    used[v] = 1;
    for (char u : g[v]){
        if (!used[u]){
            ans.push_back({v, u});
            dfs(u);
        }
    }
}
int main(){
    int n;
    cin >> n;
    string s;
    string t;
    cin >> s >> t;
    for (int i = 0;i < n; i++){
        g[s[i]].push_back(t[i]);
        g[t[i]].push_back(s[i]);
    }
    for (int i = 'a';i <= 'z';i++) if (!used[i]) dfs(i);
    cout << ans.size() << '\n';
    for (auto i : ans){
        cout << i.first << ' ' << i.second << '\n';
    }
}