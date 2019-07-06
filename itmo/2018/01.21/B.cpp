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

const int MAXN = 1e5 + 7;
int n;
int arr[MAXN];
bool used[MAXN];
inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
	memset(used, 0, sizeof(bool) * MAXN);
}

inline void solve(){
	init();
	int between = 0;
	for (int i = 0; i < n - 1; i++){
		cin >> arr[i];
		between += arr[i];
	}
	int sum = between;
	int cnt = n - 2;
	int r = n - 2;
	int l = 1;
	int lft = arr[0];
	int rgt = arr[n - 2];
	cout << "0 " << sum << ' ';
	while (cnt != 0){
		int ch_left = -1;
		if (!used[l])
			ch_left = lft + rgt - arr[r] * (n - r - 1)+ (between - arr[l - 1]) * (n - r - 1);
		int ch_right = -1;
		if (!used[r])
			ch_right = rgt + lft - arr[l - 1] * l + (between - arr[r]) * l;
		// cerr << between << ' ' << lft << ' ' << rgt << ' ' << l << ' ' << r  << ' ' <<ch_left << ' ' << ch_right << '\n';
		if (ch_left > ch_right){
			used[l] = 1;
			cnt--;
			lft += arr[l] * (l + 1);
			between -= (l > 0 ? arr[l - 1] : 0);
			sum += ch_left;
			l++;
		}
		else{
			used[r] = 1;
			cnt--;
			rgt += arr[r - 1] * (n - r);
			between -= arr[r];
			sum += ch_right; 
			r--;
		}
		cout << sum << ' ';
	}
	cout << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}