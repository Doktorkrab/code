#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<ll> cnt(n);
  for (int i = 0; i < n; i++) cin >> cnt[i];
  vector<ll> need(n + 1);
  vector<ll> can_up(n + 1);
  need[0] = 0;
  can_up[0] = 1;
  for (int i = 1; i <= n; i++) {
    need[i] = need[i - 1] * cnt[i - 1] + 1;
    can_up[i] = can_up[i - 1] * cnt[i - 1];
  }
  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;
    ll ans = 0;
    int level = n;
    while (x != 0) {
      ans += need[level] * (x / can_up[level]) + 1;
      x %= can_up[level--];
    }
    cout << ans - 1 << '\n';
  }
}
