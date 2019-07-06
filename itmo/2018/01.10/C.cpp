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
using ull = uint32_t;
 
const int MAXN = 3e3;
int n, m;
string s, t;
int dp[MAXN + 1][MAXN + 1];
ull hashesS[MAXN + 1];
ull hashesT[MAXN + 1];
ull bases[MAXN + 1];
int parent[MAXN + 1][MAXN + 1];
unordered_map<ull, int> left_enter[MAXN + 1];
// const ull MOD = 1e9 + 7;
const ull BASE = 239;
inline void init(){
    n = (int) s.size();
    m = (int) t.size();
    // cerr << "kek\n";
    // for (int i = 0; i <= n; i++){
    //     memset(dp[i], 0, sizeof(int) * (MAXN + 1));
    //     fill(parent[i], parent[i] + MAXN, -3);
    // }
    // for (int i = 0; i <= n; i++){
    //     left_enter[i] = unordered_map<ull, int>(int(sqrt(n)));
    // }
    hashesS[0] = 0;
    for (int i = 0; i < n; i++)
        hashesS[i + 1] = ((hashesS[i] * BASE) + s[i]);
 
    hashesT[0] = 0;
    for (int i = 0; i < m; i++)
        hashesT[i + 1] = ((hashesT[i] * BASE) + t[i]);
 
    bases[0] = 1;
    for (int i = 1; i <= max(n, m); i++)
        bases[i] = (bases[i - 1] * BASE);
}
 
 
ull getHashS(int l, int r){
    return (hashesS[r] - (hashesS[l] * bases[r - l]));
}
 
ull getHashT(int l, int r){
    return (hashesT[r] - (hashesT[l] * bases[r - l]));
}
inline void solve(){
    init();
    // cerr << "here\n";
    unordered_set<ull> hashes(n * (n - 1) / 2);
    for (int i = n - 1; i >= 0; --i){
        for (int j = i + 1; j <= n; j++){
            // cerr << getHashS(i, j) << " \n"[j == n];
            hashes.insert(getHashS(i, j));
            left_enter[j - i][getHashS(i, j)] = i;
        }
        int r = m;
        // cerr << i << '\n';
        for (int j = m - 1; j >= 0; j--){
            while (j < r && !hashes.count(getHashT(j, r))){
                // cerr << i << ' ' << j << ' ' << r << ' ' << getHashT(j, r) << '\n';
                r--;
            }
            int mx = max(max(dp[i][j + 1], dp[i + 1][j]), r - j);
            dp[i][j] = mx;
            if (mx == dp[i][j + 1])
                parent[i][j] = parent[i][j + 1];
            else if (mx == dp[i + 1][j])
                parent[i][j] = parent[i + 1][j];
            else
                parent[i][j] = i;
            // cerr << i << ' ' << j << ' ' << r << ' ' << dp[i][j] << '\n';
        }
    }
    cerr << "kek\n";
    int ans = 0;
    int l = -1;
    int r = -1;
    int len1 = -1;
    int len2 = -1;
    for (int i = 0; i < m; i++){
        for (int len = 1; i + len <= m; len++){
            if (!hashes.count(getHashT(i, i + len)))
                continue;
            int shiftr = i + len;
            int shiftl = left_enter[len][getHashT(i, i + len)] + len;
            int tmp = len + dp[shiftl][shiftr];
            if (ans < tmp){
                ans = tmp;
                l = left_enter[len][getHashT(i, i + len)];
                r = i;
                len1 = len;
                len2 = dp[shiftl][shiftr];
            }
        }
    }
    if (ans == 0){
        cout << "\n\n";
        return;
    }
    int shl = l + len1;
    int shr = r + len1;
    cout << t.substr(r, len1) << '\n';
    // cerr << len2 << '\n';
    if (len2 == 0){
        cout << '\n';
        return;
    }
    cout << s.substr(parent[shl][shr], len2) << '\n';
}
 
 
int main(){
    #ifdef LOCAL
        freopen("C.in", "r", stdin);
        freopen("C.out", "w", stdout);
    #else
        freopen("subpair.in", "r", stdin);
        freopen("subpair.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s >> t)
        solve();
 
}