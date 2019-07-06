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

int n, k;
map<int, int> arr;
inline void init(){
	arr.clear();
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		arr[x]++;
	}

	vector<int> ans1;
	for (auto x : arr){
		while (x.second >= k){
			ans1.push_back(x.first);
			x.second -= k;
		}
	}
	cout << ans1.size() << '\n';
	for (int i : ans1)
		cout << i << ' ';
	cout << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k)
        solve();

}