#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

struct Point {
    int m, m1, a, b, c, d;
};

// -*-*-* All variables *-*-*-
vector<vector<int>> g;
vector<int> matching;
vector<int> used;
vector<Point> arr;
const int NO_MATCHING = -INF;
int n, m, k, iteration = 0;
// -*-*-* All functions *-*-*-
void init() {
    g.clear();
    matching.clear();
    used.clear();
    arr.clear();
}
int dfs(int v) {
    if (used[v] == iteration)
        return 0;
    used[v] = iteration;
    for (int u : g[v]) {
        if (matching[u] == NO_MATCHING) {
            matching[u] = v;
            return 1;
        }
    }
    for (int u : g[v]) {
        if (dfs(matching[u])) {
            matching[u] = v;
            return 1;
        }
    }
    return 0;
}
void solve() {
    init();
    cin >> n;
    g.resize(n);
    matching.assign(n, NO_MATCHING);
    used.assign(n, -1);
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        int h, m, a, b, c, d;
        scanf("%d:%d %d %d %d %d", &h, &m, &a, &b, &c, &d);
        arr[i] = {h * 60 + m, h * 60 + m + abs(a - c) + abs(b - d), a, b, c, d};
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // cerr << (arr[i].m1 + abs(arr[i].c - arr[j].a) + abs(arr[i].d -
            // arr[j].b)) << ' ' << arr[j].m << '\n';
            if (arr[i].m1 + abs(arr[i].c - arr[j].a) +
                    abs(arr[i].d - arr[j].b) <
                arr[j].m)
                g[i].push_back(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dfs(i)) {
            ans++;
            iteration++;
        }
    }
    cout << n - ans << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "C";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
#endif
    while (t--) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}