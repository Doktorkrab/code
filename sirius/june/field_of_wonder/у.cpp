#include <bits/stdc++.h>

using namespace std;



int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(m);
    vector<int> dist(m, INT_MAX);
    vector<vector<int>> stat(n);
    for (int i = 0;i < m;i++){
        int cnt;
        cin >> cnt;
        for (int k = 0;k < cnt;k++){
            int x;
            cin >> x;
            --x;
            // cerr << x << stat.size() << '\n';
            for (int j : stat[x]){
                // cerr << "!!!!!!!!! " << j << ' ' << i << g.size() << '\n';
                g[j].push_back(i);
                g[i].push_back(j);
            }
            // cerr << x << '\n';
            stat[x].push_back(i);
        }
    }
    int a, b;
    cin >> a >> b;
    --a, --b;
    // cerr << a << ' ' << b << '\n';
    deque<int> q;
    for (int i : stat[a]){
        // cerr << ibld << '\n';
        q.push_back(i);
        dist[i] = 0;
    }
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for (int u : g[v]){
            if (dist[u] > dist[v] + 1){
                dist[u] = dist[v] + 1;
                q.push_back(u);
            }
        }
    }
    int mn = INT_MAX;
    for (int i : stat[b]) mn = min(mn, dist[i]);
    cout << (mn == INT_MAX ? -1 : mn) << '\n';
}