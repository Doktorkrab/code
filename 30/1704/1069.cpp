#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main(){
    vector<int> seq;
    int tmp;
    while (cin >> tmp) seq.push_back(tmp);
    int len = seq.size();
    vector<int> last(len + 2, -1);
    for (int i = 0; i < len; i++) last[seq[i]] = i;
    vector<vector<int>> g(len + 2);
    priority_queue <int> min_queue;
    for (int i = 1; i <= len + 1; i++) if (last[i] == -1) min_queue.push(-i);
    for (int i = 0; i < len; i++){
        assert(min_queue.size());
        int mn = -min_queue.top();
        min_queue.pop();
        g[mn].push_back(seq[i]);
        g[seq[i]].push_back(mn);
        if (last[seq[i]] == i) min_queue.push(-seq[i]);
    }

    for (int i = 1; i <= len + 1; i++){
        if (g[i].size() == 0) continue;
        cout << i << ": ";
        sort(g[i].begin(), g[i].end());
        for (int j : g[i]) cout << j << ' ';
        cout << '\n';
    }
}