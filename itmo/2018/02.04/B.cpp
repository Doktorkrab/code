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

const int MAXN = 1e5;
int n, m;
vector<int> arr[(int)1e4 + 1];
pair<int, int> have[MAXN];
inline void init(){
	for (int i = 0; i <= 10000; i++)
		arr[i].clear();
	memset(have, 0, sizeof(pair<int, int>) * MAXN);
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		arr[x].push_back(i);
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		have[i] = {y, x};
	}
	sort(have, have + m);
	int cnt = 0;
	int ans = 0;
	for (int j = 0; j < m && cnt < n; j++){
		for (int i = have[j].second; i >= 0; --i){
			ans += have[j].first * (arr[i].size());
			arr[i].clear();
		}
	}
	cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#else
		freopen("cond.in", "r", stdin);
		freopen("cond.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}