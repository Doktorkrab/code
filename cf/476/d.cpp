#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void prep(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}


void run(){
  int w, k;
  cin >> w >> k;
  --w;
  vector<int> a(w);
  int cur = 0, ans;
  for (int i = 0;i < w;i++){
    cin >> a[i];
    if (i < k)
    cur += a[i];
  }
  ans = cur;
  for (int i = k; i < w;i++){
    cur -= a[i - k];
    cur += a[i];
    ans = min(ans, cur);
  }
  cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#endif
   // string FN = "z-function";
   // assert(freopen((FN + ".in").c_str(), "r", stdin));
   // freopen((FN + ".out").c_str(), "w", stdout);


    int t = 1;
    prep();

#ifdef LOCAL
    cin >> t;
#endif
    while (t--) run();
#ifdef LOCAL
    cerr << "Elapsed: " << (clock() * 1.) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}