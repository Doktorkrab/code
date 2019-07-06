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
using namespace std;

typedef long long ll;

#ifdef DEBUG
const int MAXN = 10;
#else
const int MAXN = 3e4;
#endif

#define int ll

int n, m;

int B = 1 << 30;

struct E {
    int from;
    int to;
    int cap;
    int flow;
    E(){}
    E(int a, int b, int c, int d) {
        from = a, to = b, cap = c, flow = d;
    }
};

vector<int> g[MAXN];
vector<E> edges;
int used[MAXN];
int d[MAXN];

inline void init() {

}

void bfs() {
    memset(d, -1, sizeof(d));
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto id : g[v]) {
            int to = edges[id].to;
            if (d[to] == -1 && edges[id].cap - edges[id].flow >= B) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
}

int dfs(int v, int mn = 1e9) {
    used[v] = 1;
    if (v == n - 1) {
        used[v] = 0;
        return mn;
    }
    for (auto id : g[v]) {
        int to = edges[id].to;
        if (used[to] || d[to] != d[v] + 1 || edges[id].cap == edges[id].flow) {
            continue;
        }
        int res = 0;
        if (res = dfs(to, min(mn, edges[id].cap - edges[id].flow))) {
            used[v] = 0;
            edges[id].flow += res;
            edges[id ^ 1].flow -= res;
            return res;
        }
    }
    return 0;
}

inline void solve() {
    init();
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges.emplace_back(a, b, c, 0);
        edges.emplace_back(b, a, 0, 0);
        g[a].push_back(edges.size() - 2);
        g[b].push_back(edges.size() - 1);
    }
    int ans = 0;
    while (B > 0) {
        int flow = 0;
        while (1) {
            bfs();
            memset(used, 0, sizeof(used));
            if (d[n - 1] == -1) {
                break;
            }
            while (flow = dfs(0)) {
                ans += flow;
            }
        }
        B >>= 1;
    }
    cout << ans << '\n';
}

signed main() {
#ifdef DEBUG
    freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
#else
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // while (cin >> n >> m)
    solve();
    return 0;
}