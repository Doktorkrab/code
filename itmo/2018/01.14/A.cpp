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

const int MAXN = 1e4;
int n, l, y;
int arr[MAXN];

inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	double time = 1e25;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (i == j || arr[i] <= arr[j])
				continue;
			double tmp = 1. * l / (arr[i] - arr[j]);
			if (tmp < time)
				time = tmp;
		}
	// cerr << time << '\n';
	double time1 = 0;
	for (int i = 0; i < n; i++){
		// cerr << arr[i] * time << ' ' << (int)(arr[i] * time) / l * l << '\n';
		double mod = (arr[i] * time) - (int)(arr[i]  * time) / l * l;
		if (mod == 0)
			continue;
		// cerr << mod << ' ' << l - mod << '\n';
		time1 = max(1. * (l - mod) / y, time1);
	}
	// cerr << '\n';
	// cerr << time << ' ' << time1 << '\n';
	cout << fixed << setprecision(20) << time + time1 << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> l >> y)
        solve();

}