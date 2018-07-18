#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

// -*-*-* All variables *-*-*-
vector<int> ans;
vector<vector<int>> g_2sat, g_2sat_trans;
vector<vector<int>> g, comps;
vector<int> topsort;
vector<int> color_in;
vector<int> color_2sat;
map<char, int> color_to_int;
vector<vector<int>> can_color;
vector<int> used;
vector<char> get_ans;
int n, m;
// -*-*-* All functions *-*-*-
void init() {
    ans.clear();
    g_2sat.clear();
    g.clear();
    topsort.clear();
    color_in.clear();
    color_2sat.clear();
    can_color.clear();
    used.clear();
    comps.clear();
    color_to_int = {{'R', 0}, {'G', 1}, {'B', 2}};
    get_ans = {'R', 'G', 'B'};
}
void get_topsort(int v) {
    used[v] = 1;
    for (int u : g_2sat[v]) {
        if (!used[u])
            get_topsort(u);
    }
    topsort.push_back(v);
}
int get(int v) { return (v >= n ? v - n : v); }

int get_second(int v) { return (v >= n ? v - n : v + n); }
void paint(int v, int color) {
    // cerr << color_2sat[v] << ' ' << color << '\n';
    color_2sat[v] = color;
    comps[color].push_back(v);
    if (color_2sat[get_second(v)] == color) {
        cout << "Impossible\n";
        exit(0);
    }
    for (int u : g_2sat_trans[v]) {
        if (color_2sat[v] == -1)
            paint(u, color);
    }
}
void solve() {
    init();
    g.resize(n);
    g_2sat.resize(2 * n);
    g_2sat_trans.resize(2 * n);
    color_2sat.assign(2 * n, -1);
    color_in.resize(n);
    can_color.resize(n);
    used.resize(2 * n);
    ans.assign(n, -1);
    comps.assign(2 * n, {});
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        color_in[i] = color_to_int[c];
        for (int j = 0; j < 3; j++) {
            if (j != color_in[i]) {
                can_color[i].push_back(j);
                // cerr << j << ' ';
            }
        }
        // cerr << '\n';
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            for (int cl = 0; cl < 2; cl++) {
                for (int cl1 = 0; cl1 < 2; cl1++) {
                    if (can_color[i][cl] == can_color[j][cl1]) {
                        g_2sat_trans[j + (1 - cl1) * n].push_back(i + cl * n);
                        g_2sat[i + cl * n].push_back(j + (1 - cl1) * n);
                        // cerr << i + 1 << "(" << cl << ") =>" << j + 1 << "("
                        // << cl1 << ")\n";
                    }
                }
            }
        }
    }
    for (int i = 0; i < 2 * n; i++)
        if (!used[i])
            get_topsort(i);
    reverse(topsort.begin(), topsort.end());
    int cl = 0;
    for (int i : topsort) {
        if (color_2sat[i] == -1)
            paint(i, cl++);
    }
    while (--cl) {
        for (int i : comps[cl]) {
            if (ans[get(i)] == -1)
                ans[get(i)] = i >= n;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            if (can_color[i][ans[i]] == can_color[j][ans[j]]) {
                cout << "Impossible\n";
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << get_ans[can_color[i][ans[i]]];
    }
    cout << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "B";
    assert(freopen((taskName + ".in").c_str(), "r", stdin));
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
#else
    string taskName = "";
// freopen((taskName + ".in").c_str(), "r", stdin);
// freopen((taskName + ".out").c_str(), "w", stdout);
#endif
    while (cin >> n >> m) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}