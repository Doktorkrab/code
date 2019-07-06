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
const int MAXN = 1e5 + 7;
int k[MAXN];
int a[MAXN];
int b[MAXN];
int x;
inline void init(){
	memset(a, 0, sizeof(int) * MAXN);
	memset(a, 0, sizeof(int) * MAXN);
	memset(b, 0, sizeof(int) * MAXN);
}

inline void solve(){
	init();
	int64_t sumk = 0;
	int64_t suma = 0;
	int64_t sumb = 0;
	for (int i = 0; i < n; i++){
		int gg;
		cin >> gg;
		sumk += gg;
	}
	for (int i = 0; i < n; i++){
		cin >> a[i];
		suma += a[i];
	}
	for (int i = 0; i < n; i++){
		int gg;
		cin >> gg;
		sumb += gg;
	}
	cin >> x;
	set<pair<int, int>> aset;
	for (int i = 0; i < n; i++){
		aset.insert({a[i], i});
	}
	// cerr << sumk << ' ' << suma << ' ' << sumb << '\n';
	int64_t ans = 0;
	int64_t need = (sumk + 1) / 2;
	int64_t have = 0;
	int iter = 1;
	while (!aset.empty() && iter * iter - (iter - 1) * (iter - 1) <= x && have < need){
		while (!aset.empty() && aset.begin()->first < iter)
			aset.erase(aset.begin());
		if (aset.empty())
			break;
		// cerr << iter << ' ' << aset.size() << ' ' << x << ' ' << have << '\n';
		ans += (iter * iter - (iter - 1) * (iter - 1)) * min((int64_t)aset.size(), need - have);
		have += min((int64_t)aset.size(), need - have);
		iter++;
	}
	// cerr << aset.size() << ' ' << need << ' ' << have << ' ' << ans << '\n';
	ans += min(sumb, need - have) * x;
	have += min(sumb, need - have);
	if (have > need)
		assert(0);
	if (have == need)
		cout << ans << '\n';
	if (have < need)
		cout << "-1\n";
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}