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


const int MAXN = 5e3;
int n;
int arr[MAXN][MAXN];
inline void init(){

}

inline void solve(){
	int ans = -1;
	for (int i = 0; i < n; i++){
		int tmp = 101;
		for (int j = 0; j < n; j++){
			int x;
			cin >> x;
			tmp = min(tmp, x);
		}
		ans = max(tmp, ans);
	}
	cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("F.in", "r", stdin);
		freopen("F.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}