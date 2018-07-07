#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
const int MAXC = 1e4;

signed main() {
  int n, s;
  cin >> n >> s;
  vector<vector<int>> dp(n, vector<int>(MAXC + 1, INF)),
      parent(n, vector<int>(MAXC + 1, -2));
  vector<int> w(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> c[i];
  }
  for (int i = 0; i < n; i++) {
    dp[i][0] = 0;
    if (!i) {
      dp[i][c[i]] = (w[i] <= s ? w[i] : INF);
      continue;
    }
    for (int j = 0; j <= MAXC; j++) {
      dp[i][j] = dp[i - 1][j];
      parent[i][j] = -1;
      if (j - c[i] < 0 || dp[i - 1][j - c[i]] + w[i] > s)
        continue;
      if (dp[i][j] > dp[i - 1][j - c[i]] + w[i]) {
        parent[i][j] = i;
        dp[i][j] = dp[i - 1][j - c[i]] + w[i];
      }
    }
  }
  int ans = 0;
  for (int k = MAXC; k >= 0; k--) {
    if (dp[n - 1][k] != INF) {
      ans = k;
      break;
    }
  }
  cout << ans << '\n';
  int i = n - 1, j = ans;
  vector<int> ans1;
  // int cnt = 0;
  while (i != 0) {
    assert(parent[i][j] != -2);
    if (parent[i][j] >= 0) {
      ans1.push_back(i + 1);
      j -= c[i];
    }
    --i;
    // cnt++;
    // if (cnt > 1000) break;
  }
  if (j != 0)
    ans1.push_back(i + 1);
  cout << ans1.size() << '\n';
  for (int i : ans1)
    cout << i << ' ';
  cout << '\n';
}