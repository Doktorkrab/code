#include <bits/stdc++.h>

using namespace std;

template<typename Arg1, typename... Args>
void Print(const Arg1 &arg1, const Args &... args) {
    cout << arg1 << " ";
    Print(args...);
}

void Print() {
    cout << '\n';
}

struct Edge {
    long long f, t, w;
};

using ll = long long;

const ll INF = 1e15 + 3;
set<long long> changes;
vector<bool> used;
vector<vector<long long>> g;

void dfs(long long v) {
    if (used[v]) return;
    changes.insert(v);
    used[v] = 1;
    for (long long u : g[v]) dfs(u);
}

int main() {
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    ll n, m, s;
    cin >> n >> m >> s;
    vector<Edge> edges;
    used.resize(n + 1);
    g.resize(n + 1);
    for (long long i = 0; i < m; i++) {
        ll v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges.push_back({v1, v2, w});
        g[v1].push_back(v2);
    }
    ll dist[n + 1];
    for (long long i = 0; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    for (long long i = 0; i <= n; i++) {
        for (Edge u : edges) {
            if (dist[u.f] != INF)
            dist[u.t] = min(min(dist[u.t], dist[u.f] + u.w), INF);
        }
    }
    //set<long long> changes; // if cycle with minus weight
    for (long long i = 0; i <= n; i++) {
        for (Edge u : edges) {
            if (dist[u.t] > dist[u.f] + u.w && dist[u.f] != INF) {
                changes.insert(u.t);
                dfs(u.t);
                dist[u.t] = min(min(dist[u.t], dist[u.f] + u.w), INF);
            }
        }
    }
    //cout << n << '\n';
    for (long long i = 1; i <= n; i++) {
        if (dist[i] >= INF) cout << "*\n";
        else if (changes.count(i)) cout << "-\n";
        else cout << dist[i] << '\n';
    }
}