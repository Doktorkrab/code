#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define ea(i, v) for (auto i : v)

using ll = long long;
int main(){
    freopen("retro.in", "r", stdin);
    freopen("retro.out", "w", stdout);
    int n, m;
    while (cin >> n >> m){
        vector<vector<int>> trans;
        trans.resize(n);
        vector<bool> terminate(n, 1);
        vector<int> counter(n, 0);
        rep(i, m){
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            if (terminate[v] == 1){
                terminate[v] = 0;
            }
            trans[u].push_back(v);
            counter[v]++;
        }
        deque<int> q;
        vector<int> state(n, 0); // -1 - FIRST_LOSE, 0 - DRAW, 1 - FIRST_WIN
        rep(i, n) {
            if (terminate[i]) {
                q.push_back(i);
                state[i] = -1;
                //cerr << i << "!!!!\n";
            }
            // counter[i] = trans[i].size();
        }
        while (q.size()){
            int v = q.front();
            q.pop_front();
            ea(u, trans[v]){
                if (state[u] != 0) continue;
                if (--counter[u] <= 0){
                    state[u] = (state[v] == -1 ? 1 : -1);
                    q.push_back(u);
                }
                else if (state[v] == -1){
                    state[u] = 1;
                    counter[u] = 0;
                    q.push_back(u);
                }
            }
        }
        rep(i, n){
            if (state[i] == 0) cout << "DRAW\n";
            else if (state[i] == 1) cout << "FIRST\n";
            else if (state[i] == -1) cout << "SECOND\n";
            else cout << state[i] << '\n';
        }
    }
}