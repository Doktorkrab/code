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
#include <climits>
using namespace std;

int n;
struct expe{
    int l, r, c;
};
const int MAXC = 1e3 + 7;
const int MAXN = 12;
int a;
int64_t dp[MAXC];
expe arr[MAXN];
inline void init(){
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> arr[i].l >> arr[i].r >> arr[i].c;
    int64_t kek = 1e9;
    for (int l = a; l >= 0; --l){
        dp[l] = kek * l;
        for (int i = 0; i < n; i++){
            if (l + arr[i].r > a)
                continue;
            int64_t mn = LONG_LONG_MAX;
            for (int j = arr[i].l; j <= arr[i].r; j++)
                mn = min(mn, dp[l + j]);
            dp[l] = max(mn - arr[i].c, dp[l]);
        }
    }
    cout << dp[0] << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> a)
        solve();

}
