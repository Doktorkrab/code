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
const int MAXN = 2e5;
int arr[MAXN];
int odd = 0;
inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
	odd = 0;
}

inline void solve(){
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (x & 1)
			odd++;
	}
	if (odd & 1)
		cout << "No\n";
	else
		cout << "Yes\n";
}


int main(){
	#ifdef LOCAL
		freopen("G.in", "r", stdin);
		freopen("G.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}