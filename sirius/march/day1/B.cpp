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

string s;
const int MAXN = 1e6 + 7;
int sum[MAXN];
int n;
int arr[MAXN];
void init(){
	n = (int) s.size();
	sum[0] = 0;
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + (s[i] - '0');
}
int get_sum(int l, int r){
	return sum[r] - sum[l];
}
bool check(int m){
	// cerr << "enter" << '\n';
	// cerr << m << '\n';
	memset(arr, 0, sizeof(int) * MAXN);
	for (int i = m; i <= n; i++){
		int tmp = get_sum(i - m, i);
		// cerr << i << ' ' << tmp << '\n';
		arr[tmp]++;
		if (arr[tmp] == 2){
			// cerr << m << ' ' << tmp << '\n';
			return 1;
		}
	}
	// for (int i = 0; i <= n; i++){
	// 	cerr << arr[i] << ' ';
	// }
	// cerr << '\n';
	return 0;

}
inline void solve(){
	init();
	int l = 0, r = n + 1;
	while (r - l > 1){
		int m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
		// break;
	}
	// cerr << l < '\n';
	if (l == 0){
		cout << "-1\n";
		return;
	}
	// cerr << "HERE\n";
	pair<int, int> ans[n + 1];
	pair<int, int> neutral = {-1, -1};
	fill(ans, ans + n + 1, neutral);
	for (int i = l; i <= n; i++){
		int tmp = get_sum(i - l, i); 
		if (ans[tmp] != neutral){
			// cerr << ans[tmp].second
			cout << ans[tmp].first + 1 << ' ' << ans[tmp].second << ' ' << i - l + 1 << ' ' << i << '\n';
			return;
		}
		ans[tmp] = {i - l, i};
	}
	assert(n < n);
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}