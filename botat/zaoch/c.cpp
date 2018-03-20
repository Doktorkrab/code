#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui = unsigned int;
using namespace std;
using pii = pair<int, int>;

void print(ostream& st) { st << '\n'; }

template <typename Arg, typename... Arg1>
void print(ostream& st, const Arg& a, const Arg1&... a1) {
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

string s;
string t;
vector<vector<int>> dp;
int rec(int i, int j) {
  if (j >= t.size()) return INT_MAX - 10;
  if (i >= s.size()) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  if (s[i] == t[j]) {
    dp[i][j] = min(rec(i + 1, j + 1), rec(i + 1, j) + 1);
    dp[i][j] = min(dp[i][j], INT_MAX - 10);
  } else
    dp[i][j] = rec(i + 1, j);
  return dp[i][j];
}
int main() {
  input();
  cin >> s >> t;
  dp.assign(s.size() + 1, vector<int>(t.size() + 1, -1));
  for (int i = 0; i <= t.size(); i++) dp[s.size()][i] = 0;
  for (int i = 0; i <= s.size(); i++) dp[i][t.size()] = INT_MAX;
  rec(0, 0);
  int i = 0, j = 0;
  while (i < s.size()) {
    if (s[i] != t[j])
      cout << s[i];
    else {
      if (dp[i + 1][j + 1] <= dp[i + 1][j] + 1) {
        cout << s[i];
        j++;
      }
    }
    i++;
  }
  cout << '\n';
}
