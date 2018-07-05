#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXLOG = 25;
vector<vector<int>> bin_up;
vector<vector<int>> g;
vector<int> q;
void switch_father(int v, int u){
    bin_up[0][u] = v;
    q[u] = 1;
}

int lca(int a, int b){
    for (int i = MAXLOG; i >= 0; i--){
        int v = bin_up[a][i];
        if (!is_ans(v, b)) a = v;
    }
    return bin_up[a][0];
}

int main(){
    int n;
    cin >> n;
    q.resize(n, 0);
    g.resize(n);
    bin_up.resize(MAXLOG, vector<int>(n, -1));
    for (int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        if (!tmp) continue;
        bin_up[0][i] = tmp - 1;
        q[i]++;
        g[tmp - 1].push_back(i);
    }

}