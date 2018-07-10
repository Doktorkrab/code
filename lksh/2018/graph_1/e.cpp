#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const int INF = 1000;
#else
const int INF = 1e9;
#endif

struct Edge {
    string v, u;
    bool is_fake;
};

// -*-*-* All variables *-*-*-

map<string, vector<int>> g;
map<string, int> in_degree, out_degree;
vector<char> ans;
unordered_set<int> banned;
unordered_set<string> was;
vector<Edge> edges;
int n;

// -*-*-* All functions *-*-*-

void init() {
    g.clear();
    in_degree.clear();
    out_degree.clear();
    ans.clear();
    banned.clear();
    edges.clear();
    was.clear();
}

void dfs(const string &v) {
    while (g[v].size() != 0) {
        auto tmp = edges[g[v].back()];
        g[v].pop_back();
        dfs(tmp.u);
        ans.push_back(tmp.u[1]);
    }
}

void solve() {
    init();
    cin >> n;
    unordered_set<string> substrs;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        substrs.insert(tmp.substr(0, 2));
        substrs.insert(tmp.substr(1, 2));

        g[tmp.substr(0, 2)].push_back(edges.size());
        in_degree[tmp.substr(1, 2)]++;
        out_degree[tmp.substr(0, 2)]++;

        edges.push_back({tmp.substr(0, 2), tmp.substr(1, 2), 0});
    }
    string one = "--"s, minus_one = "--"s;

    for (auto &i : substrs) {
        if (in_degree[i] == out_degree[i])
            continue;
        else if (one == "--" && (in_degree[i] - out_degree[i]) == 1) {
            one = i;
        } else if (minus_one == "--" && (in_degree[i] - out_degree[i]) == -1) {
            minus_one = i;
        } else {
            cout << "NO\n";
            return;
        }
    }

    if ((one != "--") ^ (minus_one != "--")) {
        cout << "NO\n";
        return;
    }

    if (minus_one == "--")
        minus_one = g.begin()->first;
    dfs(minus_one);

    reverse(ans.begin(), ans.end());
    for (auto &i : g) {
        if (i.second.size() != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    cout << minus_one[0] << minus_one[1];
    for (char c : ans)
        cout << c;
    cout << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "E";
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