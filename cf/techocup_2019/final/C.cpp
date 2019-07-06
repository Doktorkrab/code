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

const int MAXN = 5e5 + 6;
int n, k, m, s;
int seq[MAXN];
int cnt[MAXN];
int have[MAXN];
inline void init(){
	memset(seq, 0, sizeof(int) * MAXN);
	memset(cnt, 0, sizeof(int) * MAXN);
	memset(have, 0, sizeof(int) * MAXN);
}

inline void solve(){
	init();
	int len = m - n * k;
	for (int i = 0; i < m; i++){
		cin >> seq[i];
	}
	int ee = 0;
	for (int i = 0; i < s; i++){
		int x;
		cin >> x;
		// cerr << x << '\n';
		if (have[x] == 0)
			ee++;
		have[x]++;
	}
	int ok = 0;
	for (int ind = 0; ind * k <= m; ind++){
		ok = 0;
		int gg = 0;
		int i = ind * k;
		for (int j = 0; j < k + len && i + j < m; j++)
			cnt[seq[i + j]] = 0;
		for (int j = 0; j < k + len && i + j < m; j++){
			gg++;
			if (have[seq[i + j]] == 0)
				continue;
			cnt[seq[i + j]]++;
			if (cnt[seq[i + j]] == have[seq[i + j]])
				ok++;
		}
		// cerr << i << ' ' << ok << ' ' << gg << '\n';
		// for (int j = 0; j < MAXN; j++){
		// 	if (have[j] == 0)
		// 		continue;
		// 	cerr << "\t" << j << ' ' << have[j] << ' ' << cnt[j] << '\n';
		// }
		if (ok != ee)
			continue;
		vector<int> ans;

		for (int j = 0; j < k + len && i + j < m; j++){
			if (have[seq[i + j]] > 0){
				have[seq[i + j]]--;
				continue;
			}
			if (gg == k)
				continue;
			ans.push_back(i + j + 1);
			--gg;
		}
		cout << ans.size() << '\n';
		for (int j : ans)
			cout << j << ' ';
		cout << '\n';
		return;
	}
	cout << "-1\n";
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> m >> k >> n >> s)
        solve();

}