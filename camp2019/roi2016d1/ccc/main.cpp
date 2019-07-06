#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

const int MAXN = 1e3 + 5;
int n, m, g;
char field[MAXN][MAXN];
int used[MAXN][MAXN];
int depth[MAXN][MAXN];
int cycle_len[MAXN * MAXN / 2];
int d[MAXN][MAXN];
vector<pair<int, int>> cycle[MAXN * MAXN];
int in[MAXN * MAXN];

inline void init() {
    for (int i = 0; i < MAXN; i++) {
        memset(field[i], 0, MAXN);
        memset(used[i], 0, MAXN * sizeof(int));
        memset(d[i], -1, MAXN * sizeof(int));
    }
}

map<char, pair<int, int>> shift = {{'e', {0,  1}},
                                   {'n', {-1, 0}},
                                   {'s', {1,  0}},
                                   {'w', {0,  -1}}};
int now = 1;

int dfs(int x, int y, int dep = 1) {
    int sx, sy;
    used[x][y] = now;
    depth[x][y] = dep;
    tie(sx, sy) = shift[tolower(field[x][y])];
    if (used[x + sx][y + sy]) {
        used[x][y] = used[x + sx][y + sy];
        if (!cycle_len[used[x + sx][y + sy]]) {
            cycle_len[used[x + sx][y + sy]] = dep - depth[x + sx][y + sy] + 1;
            d[x][y] = 0;
        }
    } else
        used[x][y] = dfs(sx + x, sy + y, dep + 1);
    if (isupper(field[x][y])) {
        in[used[x][y]]++;
        cycle[used[x][y]].emplace_back(x, y);
    }
    return used[x][y];
}

const int KEK = 1e6 + 7;

void dfs2(int x, int y, int dep = 0) {
    if (cnt[x][y] == 3)
        return;
    int sx, sy;
    tie(sx, sy) = shift[tolower(field[x][y])];
    cnt[x][y]++;
    dfs2(x + sx, y + sy);
}

int dfs3(int x, int y) {
    if (d[x][y] != -1)
        return d[x][y];
    int sx, sy;
    tie(sx, sy) = shift[tolower(field[x][y])];
    return d[x][y] = dfs3(x + sx, y + sy) + 1;
}

inline void solve() {
    init();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> field[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j])
                continue;
            dfs(i, j);
            now++;
        }
    }
    int ans = 0;
    for (int i = 1; i < now; i++) {
        ans += min(in[i], cycle_len[i]);
    }
    cout << ans << '\n';
    if (g == 0)
        return;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dfs3(i, j);
    for (int i = 1; i < now; i++) {
        sort(cycle[i].begin(), cycle[i].end(), [&](pair<int, int> a, pair<int, int> b) {
            int on_cycle = 0;
            int on_cycle1 = 0;
            return tie(on_cycle, d[a.first][a.second], a) < tie(on_cycle1, d[b.first][b.second], b);
        });
        for (int j = 0; j < min(in[i], cycle_len[i]); j++)
            cout << cycle[i][j].first + 1 << ' ' << cycle[i][j].second + 1 << ' '
                 << KEK - d[cycle[i][j].first][cycle[i][j].second] + j + 1 << '\n';
    }
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cout << d[i][j] << " \n"[j == m - 1];
}


int main() {
#ifdef LOCAL
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
#else
    freopen("robots.in", "r", stdin);
    freopen("robots.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> g)
        solve();

}
