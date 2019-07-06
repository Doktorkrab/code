#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> d;

int main(){
    cin >> n >> m;
    g.resize(n);
    d.resize(n, 0x3f3f3f3f);
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    pair<int, int> restricted;
    cin >> restricted.first >> restricted.second;
    restricted.first--, restricted.second--;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> setik;
    setik.push({0, restricted.first});
    while (!setik.empty()){
        auto [dd, v] = setik.top();
        setik.pop();
        if (d[v] <= dd)
            continue;
        d[v] = dd;
        for (int u : g[v]){
            if (make_pair(v, u) == restricted || make_pair(u, v) == restricted)
                continue;
            if (d[u] > d[v] + 1)
                setik.push({d[v] + 1, u});
        }
    }
    if (d[restricted.second] == 0x3f3f3f3f)
        cout << "Infinity\n";
    else
        cout << d[restricted.second] - 1 << '\n';
}

