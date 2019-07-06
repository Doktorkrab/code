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
#define int int64_t
const int MAXN = 1e5 + 7;
int n;
pair<int, int> a[MAXN];
pair<int, int> b[MAXN];
int fail[MAXN];
inline void init(){

}

inline void solve(){
    for (int i = 0; i < n; i++){
        int aa, bb;
        cin >> aa >> bb;
        a[i] = {aa, i};
        b[i] = {bb, i};
        fail[i] = 0;
    }
    sort(a, a + n);
    sort(b, b + n);
    int64_t ans = 0;
    int now = n;
    for (int i = 0; i < n; i++){
        int64_t plus_pr = a[i].first * now;
        int64_t cnt = 0;
        int64_t reg_pr = 0;
        for (int j = n - 1; j >= 0 && n <= 3000; j--){
            if (!fail[b[j].second])
                continue;
            cnt++;
            if (b[j].first > a[j].first)
                continue;
            // cerr << '\t' << b[j].first << ' ' << cnt * b[j].first << '\n';
            reg_pr = max(reg_pr, cnt * b[j].first);
        }
        // cerr << a[i].first << ' ' << plus_pr << ' ' << reg_pr << '\n';
        ans = max(ans, plus_pr + reg_pr);
        now--;
        fail[a[i].second] = 1;
    }
    cout << ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}