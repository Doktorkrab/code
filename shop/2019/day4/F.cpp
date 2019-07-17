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
int n;
const int MAXN = 1e5 + 7;
int arr[MAXN], pref[MAXN], suf[MAXN];
inline void init(){

}

inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        if (i == 0)
            pref[i] = arr[i];
        else
            pref[i] = max(pref[i - 1], arr[i]);
    for (int i = n - 1; i >= 0; i--)
        if (i == n - 1)
            suf[i] = arr[i];
        else
            suf[i] = max(suf[i + 1], arr[i]);
    int64_t ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(pref[i], suf[i]) - arr[i];
    cout << ans << '\n';

}


int main(){
	#ifdef LOCAL
		freopen("F.in", "r", stdin);
		freopen("F.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}