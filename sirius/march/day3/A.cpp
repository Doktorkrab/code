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
const int MAXN = 1e5 + 3;
int arr[MAXN];

inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int prev = -1;
	multiset<int> gg;
	int ans = 0;
	int seq = 1;
	for (int i = 0; i < n; i++){
		if (prev != -1 && arr[i] != prev + 1){
			seq++;
			gg.insert(arr[i] - prev - 1);
		}
		ans++;
		prev = arr[i];
	}
	// cerr << seq << ' ' << k << ' ' << ans << '\n';
	while (seq > k){
		int top = *(gg.begin());
		gg.erase(gg.find(top));
		ans += top;
		seq--;
	}
	cout << ans << '\n';

}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k)
        solve();

}