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
uint64_t a;
const int MAXN = 2e5 + 7;
pair<uint64_t, int> arr[MAXN];
inline void init(){
	for (int i = 0; i < n; i++)
		cin >> arr[i].first, arr[i].second = i;
	sort(arr, arr + n);
}

inline void solve(){
	init();
	uint64_t ans = 0;
	uint64_t lans = 0, rans = 0;
	for (int i = 0; i < n; i++){
		int l = 0, r = i;
		uint64_t tmp = (a + arr[i].first - 1) / arr[i].first;
		while (l + 1 < r){
			// cerr << l << ' ' << r << '\n';
			int64_t m = (l + r) / 2;
			if (arr[m].first > tmp)
				r = m;
			else
				l = m;
		}
		// cerr << l << ' ' << r << '\n';
		if (arr[l].first <= tmp && l != i){
			tmp = arr[i].first * arr[l].first;
			if (tmp > ans && tmp <= a){
				ans = tmp;
				lans = arr[l].second + 1;
				rans = arr[i].second + 1;
			}
 		}
	}
	cout << ans << '\n';
	if (ans != 0)
		cout << lans << ' ' << rans << '\n';


}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> a)
        solve();

}