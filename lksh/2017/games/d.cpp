#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> gr;
unordered_map<pair<int, int>, int> id;
int get_id(int v, int u){
    pair<int, int> p = {min(v, u), max(v, u)};
    return id[p];
}
int dfs(int v){
    for (int u : graph[v]){
        gr[v] ^= dfs(u);
    }
    return gr[v] + 1;
}
int get_ans(int v, int need, int p){
    if (gr[v] == need) return get_id(v, p);
    need ^= gr[v];
    for (int u : graph[v]){
        int ret = get_ans(u, (need ^ gr[u]) - 1, v);
        if (ret != -1) return ret;
    }
    return -1;
}
int main(){
    int n, r;
    cin >> n >> r;
    --r;
    graph.resize(n);
    gr.resize(n);
    for (int i = 0; i < n; i++){
        int v, u;
        cin >> v >> u;
        --v; --u;
        id[]
        graph[v].push_back(u);
    }
    int game = dfs(r);
    if (!game){
        cout << "2\n";
        return 0;
    }
    cout << "1\n";
    cout << get_ans(r, 0, -1) << '\n';

}