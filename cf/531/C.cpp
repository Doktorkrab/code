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

const int MAXN = 105;
int n, x, y;
int arr[MAXN];

inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	if (x > y){
		cout << n << '\n';
		return;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] <= x)
			cnt++;
	cout << (cnt + 1) / 2 << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> x >> y)
        solve();

}