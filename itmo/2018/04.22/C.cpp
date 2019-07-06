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
int arr[MAXN];
inline void init(){
    memset(arr, 0, sizeof(int) * MAXN);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    int pnt = 0;
    int sm = 0;
    for (int i = 0; i < n; i++){
        while (pnt < n && arr[pnt] <= 2 * (arr[i] + sm - (pnt > i) * arr[i])){
            sm += arr[pnt];
            pnt++;
        }
        // cerr << pnt << '\n';
        ans += pnt == n;
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