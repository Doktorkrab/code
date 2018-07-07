#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> dp;
vector<int> sz;
int n, p1;
int INF = 1e7;

void dfs(int v, int p) {
    int mx = 0, ind = -1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        if (mx < sz[u]) {
            mx = sz[u];
            ind = u;
        }
    }
    if (ind == -1) { // is leaf
        dp[v][1] = 0;
        dp[v][0] = 1;
        return;
    }
    dp[v][1] = 0;
    int cnt = 0;
    for (int u : g[v]) {
        if (u == p)
            continue;
        for (int i = 1; cnt != 0 && i <= p1; i++) {
            // dp[v][i] = min(INF, dp[v][i] + 1);
        }
        vector<int> nxt(n + 1, INF);
        // nxt[0] = 1;
        for (int k = 1; k <= p1; k++) {
            for (int i = 0; i <= min(sz[u], k); i++) {
                // if (v == 0){
                //     cout << k << ' ' << i << ' ' << dp[v][k - i] << ' ' <<
                //     dp[u][i] << '\n';
                // }
                nxt[k] = min(dp[v][k - i] + dp[u][i], nxt[k]);
            }
        }
        swap(nxt, dp[v]);
        cnt++;
    }
    dp[v][0] = 1;
    // cout << "Now " << v + 1 << ":\n";
    // for (int i = 1; i <= p1; i++){
    //     cout << dp[v][i] << ' ';
    // }
    // dp[v][sz[v]] = 0;
    // cout << '\n';
}

int get_sz(int v, int p) {
    sz[v] = 1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        sz[v] += get_sz(u, v);
    }
    return sz[v];
}

int main() {
    cin >> n >> p1;
    g.resize(n);
    dp.assign(n, vector<int>(n + 1, INF));
    sz.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    get_sz(0, -1);
    dfs(0, -1);
    if (n == p1) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = INF;
    for (int v = 0; v < n; v++) {
        ans = min(ans, dp[v][p1] + (v != 0));
    }
    cout << ans << '\n';
}