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
#define int int64_t
using namespace std;
int n;
string s;

inline void init(){
    n = s.size();
}
int ans;
vector<int> z_function(const string& s, bool need){
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int r = -1, l = -1;
    for (int i = 1; i < n; i++){
        if (i < r)
            z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] > r){
            r = i + z[i];
            l = i;
        }
        if (need && i + z[i] == n && i < z[i] && i * 2 != z[i]) ans--;
    }
    return z;
}
inline void solve(){
    init();
    ans = (n - 1) * (n - 2) / 2;
    auto z = z_function(s, 1);
    reverse(s.begin(), s.end());
    auto z1 = z_function(s, 0);
    // reverse(z1.begin(), z1.end());
    for (int i = 2; i < n; i += 2){
        if (z[i / 2] >= i / 2)
            ans--;
    }
    for (int i = 2; i < n; i += 2){
        if (z1[i / 2] >= i / 2 && i / 2 * 3 != n)
            ans--;
    }
    cout << ans << '\n';

}


int32_t main(){
	#ifdef LOCAL
		freopen("M.in", "r", stdin);
		freopen("M.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}