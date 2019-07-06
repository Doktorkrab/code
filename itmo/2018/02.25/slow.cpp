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
const int MAXN = 1e5 + 7;
vector<int> arr(MAXN), arr1(MAXN), arr_is(MAXN);
vector<int> kek(MAXN);
inline void init(){
	for (int i = 0; i < n; i++)
		kek[i] = i;
	for (int i = 0; i < n; i++){
		cin >> arr[i], arr[i]--;
		arr_is[i] = arr[i];
		arr1[i] = -1;
	}

}
inline void solve(){
	init();
	if (k == 0){
		for (int i = 0; i < n; i++)
			cout << kek[i] + 1 << ' ';
		cout << '\n';
		return;
	}
	for (int j = 1; j < k; j++){
		// cerr << "\t" << j << '\n';
		for (int i = 0; i < n; i++){
			// cerr << i + 1 << ' ' << arr_is[arr[i]] + 1 << ' ' << arr[i] + 1 << '\n';
			arr1[i] = arr_is[arr[i]];
		}
		swap(arr, arr1);
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] + 1 << ' ';
	// for (int i : arr1)
	// 	cerr << i + 1 << ' ';
	// cerr << '\n'; 
	cout << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k)
        solve();

} 