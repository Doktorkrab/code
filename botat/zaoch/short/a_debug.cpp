#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, m, t, k;
  cin >> n >> m >> t >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<ll> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  ll pos = 0;
  ll ans = 0, ans1 = 0;
  bool cur = 1;
  int left = 0, right = 0;
  bool can_change = 1;
  while (pos < t) {
    // cerr << pos << ' ' << ans << ' ' << ans1 << ' ' << cur << '\n';
    if (cur) {
      while (left < n && a[left] + k < pos) {
        left++;
        can_change = 1;
      }
      if (left >= n) {
        ans++;
      } else if (can_change && a[left] <= pos && a[left] + k > pos) {
        cur = 0;
        pos--;
        can_change = 0;
      } else if (!can_change) {
        if (a[left] + k <= pos || a[left] > pos) {
          can_change = 1;
          ans++;
        }
      } else {
        ans++;
      }
    } else {
      while (right < m && b[right] + k < pos) {
        right++;
        can_change = 1;
      }
      if (right >= m) {
        ans1++;
      } else if (can_change && b[right] <= pos && b[right] + k > pos) {
        cur = 1;
        pos--;
      } else if (!can_change) {
        if (b[right] + k <= pos || b[right] > pos) {
          can_change = 1;
          ans1++;
        }
      } else {
        ans1++;
      }
    }
    pos++;
  }
  cout << ans << ' ' << ans1 << '\n';
}
