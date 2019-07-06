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

const int MAXN = 2e5;
int n, m, k;
int mark[MAXN];

pair<int, int> srt[MAXN];

inline void init(){
	memset(mark, 0, sizeof(int) * MAXN);
	fill(srt, srt + MAXN, pair<int, int>());
}

inline void solve(){
	init();
	for (int i = 0 ; i < n; i++){
		cin >> srt[i].first;
		srt[i].second = i;
	}
	sort(srt, srt + n);
	reverse(srt, srt + n);
	int64_t sum = 0;
	for (int i = 0; i < m * k; i++)
		mark[srt[i].second] = 1, sum += srt[i].first;
	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++){
		cnt += mark[i];
		if (cnt == m)
			ans.push_back(i + 1), cnt = 0;
	}
	cout << sum << '\n';
	ans.pop_back();
	for (int i : ans)
		cout << i << ' ';
	cout << '\n'; 	
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> k)
        solve();

}