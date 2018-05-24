#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void prep(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}

int n, k;
vector<vector<int>> ans, fld;
int paint(int x, int y, int d, int cnt){
  if (x == n || y == n) return 0;
  if (!fld[x][y]) return 0;
  if (cnt + 1 == k){
    ans[x][y]++;
    return k;
  }
  int tmp = paint(x + (d == 0), y + (d == 1), d, cnt + 1);
  if (tmp == k){
    ans[x][y]++;
  } 
  return tmp;
}
void run(){
    cin >> n >> k;
    ans.assign(n, vector<int>(n));
    fld.assign(n, vector<int>(n));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n; j++){
            char tmp;
            cin >> tmp;
            fld[i][j] = (tmp == '.');
      }
    }
    for (int i = 0;i < n;i++){
      for (int j = 0;j < n;j++){
        paint(i, j, 0, 0);
        paint(i, j, 1, 0);
      }
    }
    int x = 0, y = 0, mx = 0;
    for (int i = 0;i < n;i++){
      for (int j = 0;j < n;j++){
        // cout << ans[i][j] << ' ';
        if (ans[i][j] >= mx){
          x = i;
          y = j;
          mx = ans[i][j];
        }
      }
      // cout << '\n';
    }
    cout << x + 1 << ' ' << y + 1 << '\n';
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