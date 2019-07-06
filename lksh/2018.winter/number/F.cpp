#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
using namespace std;
using ll = long long;
#define int ll
int n, a;
int mod;

int bp(int x, int N) {
  x %= mod;
  if (N == 0) {
    return 1;
  }
  if (N & 1) {
    return (x * bp(x, N - 1)) % mod;
  }
  return bp((x * x) % mod, N >> 1);
}

inline void solve() {
  int block_size = 3e4;
  map<int, int> val;
  for (int i = 1; i <= block_size; i++) {
    int cur = bp(a, i * block_size);
    if (!val.count(cur)) {
      val[bp(a, i * block_size)] = i;
    }
  }
  int ans = 1e10;
  for (int i = 0; i <= block_size; i++) {
    int cur = (bp(a, i) * n) % mod;
    if (val.count(cur)) {
      int res = val[cur] * block_size - i;
      if (res < mod) {
        ans = min(ans, res);
      }
    }
  }
  if (ans < mod) {
    cout << ans << '\n';
  }
  else {
    cout << "no solution\n";
  }
}

signed main() {
  while (cin >> mod >> a >> n)
    solve();
  return 0;
}