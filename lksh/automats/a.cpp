#include <bits/stdc++.h>
using namespace std;

struct Node{
    vector<int> edges;
    bool is_terminate;
    Node() : edges(26, -1), is_terminate(0) {}
};

int main(){
    freopen("bulbul.in", "r", stdin);
    freopen("bulbul.out", "w", stdout);
    string s;
    cin >> s;
    vector<Node> nodes;
    int n, m, k;
    cin >> n >> m >> k;
    nodes.resize(n);
    for (int i = 0; i < k; i++){
        int tmp;
        cin >> tmp;
        nodes[tmp - 1].is_terminate = 1;
        // cout << tmp - 1 << "TERMINATE\n";
    }
    for (int i = 0; i < m; i++){
        int v, u;
        char c;
        cin >> v >> u >> c;
        nodes[v - 1].edges[c - 'a'] = u - 1;
        // cout << nodes[v - 1].edges[c - 'a'] << " LUL " << c - 'a' << '\n'; 
    }
    int pos = 0, pos_s = 0;
    while (pos_s < (int) s.size() && pos != -1) {
        // cout << pos << " BEFORE " << pos_s << ' ' << nodes[pos].edges[s[pos_s] - 'a'] << '\n';
        pos = nodes[pos].edges[s[pos_s++] - 'a'];
        // cout << pos << ' ' << pos_s << '\n';
    }
    // cout << pos_s << ' ' << pos << ' ' << nodes[pos].is_terminate << '\n';
    if (pos_s == (int) s.size() && pos != -1 && nodes[pos].is_terminate) cout << "Accepts\n";
    else cout << "Rejects\n";
}