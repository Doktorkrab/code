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

typedef long long ll;

#ifdef DEBUG
  const int MAXN = 10;
#else
  const int MAXN = 1e5;
#endif
#define int ll
int a, b, m;

int bp(int x, int N, int mod) {
  x %= mod;
  if (N == 0) {
    return 1;
  }
  if (N & 1) {
    return (x * bp(x, N - 1, mod)) % mod;
  }
  return bp((x * x) % mod, N >> 1, mod);
}

int log(int a, int n, int mod) {
  int block_size = 3e4;
  map<int, int> val;
  for (int i = 1; i <= block_size; i++) {
    int cur = bp(a, i * block_size, mod);
    if (!val.count(cur)) {
      val[bp(a, i * block_size, mod)] = i;
    }
  }
  int ans = 1e10;
  for (int i = 0; i <= block_size; i++) {
    int cur = (bp(a, i, mod) * n) % mod;
    if (val.count(cur)) {
      int res = val[cur] * block_size - i;
      if (res < mod) {
        ans = min(ans, res);
      }
    }
  }
  if (ans < mod) {
    return ans;
  }
  else {
    return -1;
  }
}

int generator(int p) {
    vector<int> fact;
    int phi = p - 1, n = phi;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back(n);

    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (size_t i = 0; i < fact.size() && ok; ++i)
            ok &= bp(res, phi / fact[i], p) != 1;
        if (ok) return res;
    }
    return -1;
}

void solve(){
	for (int i = 0; i < 1000; i++){
		if (bp(i, b, m) == a){
			cout << i << '\n';
			return;
		}
	}
	// swap(a, b);
	// if (b == 0){
	// 	cout << "1\n";
	// 	// assert(0);
	// 	return;
	// }
	// if (a == 0){
	// 	cout << "0\n";
	// 	return;
	// }
	// if (a > 1 && b == 0){
	// 	cout << "-1\n";
	// 	return;
	// }
	// if (b == 1){
	// 	cout << a << '\n';
	// 	return;
	// }
	int gened = generator(m);
	if (gened == -1){
		cout << -1 << '\n';
		return;
	}
	int log_ = log(bp(gened, b, m), a, m);
	if (log_ == -1){
		cout << -1 << '\n';
		return;
	}
	int ans = bp(gened, log_, m);
	// if (bp(ans, b, m) == a)
		cout << ans << '\n';
	// else
	// 	cout << "-1\n";
}
signed main() {
  #ifdef LOCAL
    freopen("K.in", "r", stdin);
    freopen("K1.out", "w", stdout);
  #else
  
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (cin >> a >> b >> m)
    solve();
  return 0;
}