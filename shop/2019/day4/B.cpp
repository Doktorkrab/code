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
vector<int> arr;
inline void init(){
    arr.resize(n, 0);
}
// 0 1 2 3 4 5 6 7 8 9
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int ans = 0x3f3f3f3f;
    for (int three = 0; three <= n; three += 3){
        if (three != 0 && arr[three - 1] != 100)
            break;
        int cur_ans = three / 3;
        int l = three, r = n - 1;
        while (l <= r){
            // cerr << three << ' ' << l << ' ' << r << '\n';
            // cerr << '\t' << arr[l]
            if (arr[l] + arr[r] <= 300){
                cur_ans++;
                l++, r--;
            }
            else{
                cur_ans++;
                r--;
            }
        }
        // cerr << three << ' ' << cur_ans << '\n';
        ans = min(ans, cur_ans);
    }
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}