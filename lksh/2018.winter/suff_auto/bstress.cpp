#include <bits/stdc++.h>

using namespace std;

vector<bool> is_terminal;
vector<map<char, int>> g;
string s;

bool check(int pos, int v){
    if (pos == s.size())
        return is_terminal[v];
    if (!g[v].count(s[pos]))
        return 0;
    return check(pos + 1, g[v][s[pos]]);
}
int main(){
    int n, m, t;
    int cnt = 1;
    while (cin >> n >> m >> t){
        is_terminal.assign(n, 0);
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            is_terminal[--x] = 1;
        }
        g.assign(n, {});
        for (int i = 0; i < m; i++){
            int v, u;
            char c;
            cin >> v >> u >> c;
            g[--v][c] = --u;
        }
        cin >> s;
        if (check(0, 0))
            cout << "Automaton " << cnt++ << " is a machinegun.\n";
        else
            cout << "Automaton " << cnt++ << " is not a machinegun.\n";
    }
}