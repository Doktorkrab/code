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
const int MAXN = 3e6;
int n, m;
vector<int> arr;
vector<int> arr1;
vector<int> ans;
inline void init(){
	arr.resize(n);
	arr1.resize(m);
	ans.clear();
}
inline int intersect(int l, int r, int l1, int r1){
	return max((int) 0, min(r, r1) - max(l, l1));
}
inline void solve(){
	init();
	int sum = 0, sum1 = 0;
	// cout << n << ' ' << m << '\n';
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < m; i++){
		cin >> arr1[i];
		sum1 += arr1[i];
	}
	if (sum - sum1 < 0){
		swap(arr, arr1);
		swap(n, m);
		swap(sum, sum1);
	}
	reverse(arr1.begin(), arr1.end());
	arr1.push_back(sum - sum1);
	arr1.push_back(0);
	reverse(arr1.begin(), arr1.end());
	m = n;
	// for (int i = 0; i < n; i++)
	// 	cerr << arr[i] << " \n"[i == n - 1];
	// for (int j = 0; j < arr1.size(); j++)
	// 	cerr << arr1[j] << " \n"[j == arr1.size() - 1];
	int pos = sum;
	int pos1 = sum;
	int i = 0;
	int j = 0;
	while (pos > 0 && pos1 > 0){
		while (i < n && pos - arr[i] >= pos1 - arr1[j]){
			int tmp = intersect(pos - arr[i], pos, pos1 - arr1[j], pos1);
			int xr = (i % 2 == 0) ^ (j % 2 == 0);
			// cerr << i << ' ' << j << ' ' << pos << ' ' << pos1 << ' ' << tmp << ' ' << xr << ' ' << ans.size() << '\n';
			if (xr == 1)
				if (ans.size() % 2 == 1)
					ans.back() += tmp;
				else
					ans.push_back(tmp);
			else
				if (!ans.empty() && ans.size() % 2 == 0)
					ans.back() += tmp;
				else if (ans.size() > 0)
					ans.push_back(tmp);
			pos -= arr[i++];
		}
		if (i < n && intersect(pos - arr[i], pos, pos1 - arr1[j], pos1) != 0){
			int tmp = intersect(pos - arr[i], pos, pos1 - arr1[j], pos1);
			int xr = (i % 2 == 0) ^ (j % 2 == 0);
			if (xr == 1)
				if (ans.size() % 2 == 1)
					ans.back() += tmp;
				else
					ans.push_back(tmp);
			else
				if (!ans.empty() && ans.size() % 2 == 0)
					ans.back() += tmp;
				else if (ans.size() > 0)
					ans.push_back(tmp);
		}
		pos1 -= arr1[j++];
		// break;
	}
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	#endif

    while (cin >> n >> m)
        solve();

}