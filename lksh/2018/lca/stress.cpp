#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> parent = {-1};
    vector<int> deleted = {0};
    int m;
    cin >> m;
    while(m--){
        char ch;
        cin >> ch;
        if (ch == '?'){
            vector<int> color(parent.size());
            int v, u;
            cin >> v >> u;
            --v, --u;
            while (v != -1){
                color[v] = 1;
                v = parent[v];
            }
            while (!color[u] || deleted[u]){
                u = parent[u];
            }
            cout << u + 1 << '\n';
        }
        if (ch == '-'){
            int v;
            cin >> v;
            --v;
            deleted[v] = 1;
        }
        if (ch == '+'){
            int v;
            cin >> v;
            --v;
            parent.push_back(v);
            deleted.push_back(0);
        }
    }
}