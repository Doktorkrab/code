#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXLOG = 5;
const int MAXN = 100;
#else
const int INF = 1e9;
const int MAXLOG = 25;
const int MAXN = 3e5;
#endif

// -*-*-* All variables *-*-*-

int bin_up[MAXN][MAXLOG];
int level[MAXN];
int n, timer = 0;

struct DSU {
    vector<int> p;
    DSU(int n_) : p(n_) {
        for (int i = 0; i < n_; i++) {
            p[i] = i;
        }
    }

    int get(int a) { return p[a] = (a == p[a] ? a : get(p[a])); }

    void un(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return;
        if (level[a] < level[b])
            swap(a, b);
        p[a] = b;
    }
};

// -*-*-* All functions *-*-*-
void add(int a, int par) {
    bin_up[a][0] = par;
    for (int i = 1; i < MAXLOG; i++) {
        bin_up[a][i] = bin_up[bin_up[a][i - 1]][i - 1];
    }
}

void calc(int v, int p) {
    level[v] = level[p] + 1;
    add(v, p);
}

int jump(int v, int a) {
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (a & (1 << i)) {
            v = bin_up[v][i];
        }
    }
    return v;
}

int lca(int a, int b) {
    a = jump(a, max(level[a] - level[b], 0));
    b = jump(b, max(level[b] - level[a], 0));
    if (a == b)
        return a;
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (bin_up[a][i] != bin_up[b][i]) {
            a = bin_up[a][i];
            b = bin_up[b][i];
        }
    }
    return bin_up[a][0];
}

void init() {}

void solve() {
    add(0, 0);
    int nxt = 1;
    DSU dsu(MAXN);
    while (n--) {
        char c;
        int v;
        cin >> c >> v;
        if (c == '+') {
            calc(nxt++, v - 1);
        }
        if (c == '?') {
            int u;
            cin >> u;
            int tmp = lca(v - 1, u - 1);
            cout << dsu.get(tmp) + 1 << '\n';
        }
        if (c == '-') {
            int pr = bin_up[v - 1][0];
            dsu.un(pr, v - 1);
        }
        // for (int i = 0;i < nxt; i++) cerr << level[i] << ' ';
        // cerr << '\n';
    }
}
int main() {
#ifdef LOCAL
    string taskName = "D";
    assert(freopen((taskName + ".in").c_str(), "r", stdin));
    assert(freopen((taskName + ".out").c_str(), "w", stdout));
    clock_t start = clock();
#else
// string taskName = "";
// freopen((taskName + ".in").c_str(), "r", stdin);
// freopen((taskName + ".out").c_str(), "w", stdout);
#endif
    while (cin >> n) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}