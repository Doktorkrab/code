#include <bits/stdc++.h>


using namespace std;


int main() {
//    freopen("experiment.in", "r", stdin);
//    freopen("experiment.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    vector<set<int>> g1(m);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].insert(u);
        g1[u].insert(v);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            set<int> inter;
            set_intersection(g[i].begin(), g[i].end(), g[j].begin(), g[j].end(), inserter(inter, inter.begin()));
            if (inter.size() > 1){
                cout << "No\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (i == j) continue;
            set<int> inter;
            set_intersection(g1[i].begin(), g1[i].end(), g1[j].begin(), g1[j].end(), inserter(inter, inter.begin()));
            if (inter.size() > 1){
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}