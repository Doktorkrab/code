#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui = unsigned int;
using namespace std;
using pii = pair<int, int>;

void print(ostream &st) { st << '\n'; }

template <typename Arg, typename... Arg1>
void print(ostream &st, const Arg &a, const Arg1 &... a1) {
  st << a << ' ';
  print(st, a1...);
}

void input() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#else
  ios_base::sync_with_stdio(0);
  cout.tie(0);
#endif
}

int main() {
  input();
  int n, m, timer = 1;
  cin >> n >> m;
  vector<vector<pii>> g(n);
  vector<int> used(n);
  vector<int> dist(n);
  rep(i, m) {
    int v, u, c;
    cin >> v >> u >> c;
    --v;
    --u;
    g[v].push_back({u, c});
    g[u].push_back({v, c});
  }
  int q;
  cin >> q;
  rep(query, q) {
    int v, u, c, type;
    cin >> type >> v >> u;
    if (type == 1) {
      cin >> c;
      g[--v].push_back({--u, c});
      g[u].push_back({v, c});
    }
    if (type == 2) {
      int i = 0;
      --v;
      --u;
      for (i = 0; i < g[v].size() && g[v][i].first != u; i++)
        ;
      assert(i != g[v].size());
      swap(g[v][i], g[v].back());
      g[v].pop_back();
      for (i = 0; i < g[u].size() && g[u][i].first != v; i++)
        ;
      assert(i != g[u].size());
      swap(g[u][i], g[u].back());
      g[u].pop_back();
    }
    if (type == 3) {
      --v;
      --u;
      for (auto u1 : g[v]) {
        used[u1.first] = timer;
        dist[u1.first] = u1.second;
        // print(cout, u1.first, u1.second);
      }
      ll ans = LONG_LONG_MAX;
      for (auto u1 : g[u]) {
        // print(cout, u1.first, used[u1.first], u1.second);
        if (used[u1.first] == timer) {
          ans = min(ans, (ll)dist[u1.first] + u1.second);
        }
      }
      if (used[u] == timer)
        ans = min(ans, (ll)dist[u]);
      if (ans != LONG_LONG_MAX)
        print(cout, ans);
      else
        print(cout, -1);
      timer++;
    }
  }
}
