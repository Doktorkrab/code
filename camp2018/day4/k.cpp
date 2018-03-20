#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> p, sz;
vector<bool> cross;
int find(int a){
    return p[a] == a ? a : (p[a] = find(p[a]));
}
bool un(int a, int b){
    a = find(a), b = find(b);
    if (sz[a] > sz[b]) swap(a, b);
    if (a == b) return 0;
    p[a] = b;
    sz[b] += sz[a];
    return 1;
}

int main(){
    int n;
    cin >> n;
    p.resize(n), sz.assign(n, 1);
    for (int i = 0;i < n;i++) p[i] = i;
    vector<pair<int, int>> to_delete;
    for (int i = 0;i < n - 1;i++){
        int v, u;
        cin >> v >> u;
        --v, --u;
        if (!un(v, u)) to_delete.push_back({v, u});
    }
    vector<vector<int>> ans;
    int cnt = 0;
    for (int i = 1;i < n;i++){
        if (find(p[i]) != find(p[i - 1])){
            ans.push_back({to_delete[cnt].first + 1, to_delete[cnt].second + 1, i, i + 1});
            cnt++;
            un(i, i - 1);
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans){
        for (int j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
}