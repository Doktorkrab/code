#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull BASE = 127;
vector<vector<vector<int>>> eq;
vector<string> matrix;
vector<vector<ull>> h1, h2;
vector<ull> bases;

ull get_hash(int i, int l, int r) {
  return h1[i][r + 1] - h1[i][l] * bases[r - l + 1];
}
inline ull get_hash1(int i, int l, int r) {
  return h2[i][l] - h2[i][r + 1] * bases[r - l + 1];
}
int main() {
  int n, m;
  cin >> n >> m;
  bases.resize((max(n, m) + 1));
  eq.assign(2, vector<vector<int>>(n, vector<int>(m + 1)));
  matrix.resize(n);
  h1.assign(n, vector<ull>(m + 1));
  h2.assign(n, vector<ull>(m + 1));
  bases[0] = 1;
  for (int i = 1; i <= max(n, m); i++) bases[i] = bases[i - 1] * BASE;
  for (int i = 0;i < n;i++) cin >> matrix[i];
  for (int i = 0;i < n;i++){
    for (int j = 0; j < m; j++){
      h1[i][j + 1] = h1[i][j] * BASE + matrix[i][j];
    }
  }
  for (int i = 0;i < n;i++){
    for (int j = m - 1; j >= 0;j--){
      h2[i][j] = h2[i][j + 1] * BASE + matrix[i][j];
    }
  }
  cerr << "kek";
  ull sum = 0;
  for (int t1 = 0; t1 < 2; t1++){
    for (int t2 = 0; t2 < 2; t2++){
      for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
          int k = m;
          while(j - k > 0 || j + k + t2 >= m) --k;
          for (int l = 0; 0 <= i - l && i + l + t1 < n; l++){
            while (k >= 0 && get_hash(i - l, j - k, j + k + t2) != get_hash1(i + l + t1, j - k, j + k + t2)) --k;
            sum += k + 1;
          }
        }
      }
    }
  }
  cout << sum << '\n';
  return 0;
}