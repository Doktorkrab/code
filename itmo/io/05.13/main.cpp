#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void prep() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}


int n, m, cnt;
vector<vector<bool>> g;
unordered_map<int, unordered_map<int, vector<vector<int>>>> dp;


bool check(int x, int y, int dist_x, int dist_y) {
    return x + 2 * dist_x >= 0 && x + 2 * dist_x < n && y + 2 * dist_y >= 0 && y + 2 * dist_y < m &&
           g[x + dist_x][y + dist_y] && !g[x + 2 * dist_x][y + 2 * dist_y];
}


vector<pair<int, int>> change = {{-1, -1},
                                 {1,  1},
                                 {-1, 1},
                                 {1,  -1}};
vector<int> anti = {1, 0, 3, 2};


int dfs(int x, int y, int can_turn, int dst) {
    if (can_turn < 0) return 0;
    if (dp.count(x) && dp[x].count(y) && dp[x][y][dst][can_turn] != -1) return dp[x][y][dst][can_turn];
    else if (dp.count(x) == 0 || dp[x].count(y) == 0) {
        dp[x][y] = vector<vector<int>>(4, vector<int>(3, -1));
    }
//    bool gg = dp.count(x) == 0 || dp[x].count(y) == 0;
    dp[x][y][dst][can_turn] = 0;
    for (int i = 0; i < 4; i++) {
        if (!check(x, y, change[i].first, change[i].second) || i == anti[dst]) continue;
        dp[x][y][dst][can_turn] = max(dfs(x + 2 * change[i].first, y + 2 * change[i].second, can_turn - (dst != i), i),
                                      dp[x][y][dst][can_turn]);
    }
    return ++dp[x][y][dst][can_turn];
}


void run() {
    cin >> n >> m >> cnt;
    g.assign(n, vector<bool>(m));
//    dp.assign(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(3, -1)))); // MMMMMMMMM KAEF
    int st_x, st_y;
    cin >> st_x >> st_y;
    for (int i = 0; i < cnt; i++) {
        int x, y;
        cin >> x >> y;
        g[--x][--y] = 1;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = max(ans, dfs(st_x - 1, st_y - 1, 2, i));
    }
    cout << ans - 1 << '\n';
}


int main() {
    int t = 1;
#ifdef LOCAL
    string FN = "local";
    assert(freopen((FN + ".in").c_str(), "r", stdin));
//    freopen((FN  + ".out").c_str(), "w", stdout);
    cin >> t;
#endif
    prep();
    while (t--) {
        clock_t start = clock();
        run();
#ifdef LOCAL
        cout << setprecision(5) << fixed << "Elapsed " << fabs(clock() - start) / CLOCKS_PER_SEC << '\n';
#endif
    }
}

