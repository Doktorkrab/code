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
const short INF = 1.5e4 + 1;
short n;
vector<vector<short>> dp;
vector<vector<short>> enters;
inline void init(){
	dp.assign(n, vector<short>(n, INF));
	for (short i = 0; i < n; i++)
		dp[i][i] = 0;
	enters.assign(26, {});
}

inline void solve(){
	init();
	char c;
	for (int i = 0; cin >> c; i++)
		enters[c - 'a'].push_back(i);
	for (int i = 0; i < 26; i++){
		cerr << (char)(i + 'a') << ": ";
		for (int j : enters[i])
			cerr << j << ' ';
		cerr << '\n';
	}
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();

}