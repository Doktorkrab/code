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

#define int int64_t
const int MAXN = 1e5 + 7;
const int MAXC = 5e6 + 7;
int n;
pair<int, int> arr[MAXN];
vector<int> events[MAXC];
int64_t rgt = 0, rgt_b = 0, lft = 0, lft_b = 0;
inline void init(){

}

inline void solve(){
	for (int i = 0; i < n; i++){
		cin >> arr[i].first;
		events[arr[i].first].push_back(i);
	}
	int64_t rgt = 0;
	for (int i = 0; i < n; i++){
		cin >> arr[i].second;
		rgt += arr[i].second;
		rgt_b += arr[i].first * arr[i].second;
	}
	int64_t ans = LONG_LONG_MAX;
	int64_t ans_pos = -1;
	for (int i = 0; i < MAXC; i++){
		for (int e : events[i])
			rgt -= 2 * arr[e].second;
		if (ans > rgt_b){
			ans = rgt_b;
			ans_pos = i;
		}
		rgt_b -= rgt;
	}
	cout << ans_pos << ' ' << ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
		freopen("fly.in", "r", stdin);
		freopen("fly.out", "w", stdout);
	#endif	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
