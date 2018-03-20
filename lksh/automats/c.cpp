#include <bits/stdc++.h>

using namespace std;
int main(){
    freopen("hawfinch.in", "r", stdin);
    freopen("hawfinch.out", "w", stdout);
    string s;
    cin >> s;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<int>>> edges(26, vector<vector<int>>(n));
    vector<int> terminate(n);
    for (int i = 0; i < k; i++){
        int tmp;
        cin >> tmp;
        terminate[tmp - 1] = 1;
    }
    for (int i = 0; i < m; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        edges[c - 'a'][a - 1].push_back(b - 1);
    }
    vector<vector<int>> used(n, vector<int>(s.size() + 1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()){
        pair<int, int> a = q.front();
        q.pop();
        int pos_a = a.first, pos_s = a.second;
        if (pos_a >= n) continue;
        if (pos_s == (int) s.size() && terminate[pos_a]){
            cout << "Accepts\n";
            return 0;
        } 
        if (pos_s >= (int)s.size()) continue;
        if (used[pos_a][pos_s]) continue;
        used[pos_a][pos_s] = 1;
        for (int u : edges[s[pos_s] - 'a'][pos_a]){
            q.push({u, pos_s + 1});
        }
    }
    cout << "Rejects\n";
    return 0;
}