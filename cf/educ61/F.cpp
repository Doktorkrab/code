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
const int MAXN = 500;
int n;
int dp[MAXN][MAXN];
string s;

inline void init(){

}

inline void solve(){
	string t;
	for (char c : s){
		if (t.size() == 0 || t.back() != c)
			t += c;
	}
	n = t.size();
	// cerr << t << '\n';
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;
	for (int i = 0; i + 1 < n; i++){
		dp[i][i + 1] = 2;
	}
	for (int len = 3; len <= n; len++){
		for (int i = 0; i + len <= n; i++){
			int j = i + len - 1;
			// cerr << i << ' ' << j << ' ' << dp[i + 1][j] << ' ' << dp[i][j - 1] << '\n';
			dp[i][j] = dp[i][j - 1] + 1;
			for  (int k = j - 1; k >= i; k--){
				// cerr << i << ' ' << j << ' ' << k << ' ' << dp[i][k] << ' ' << dp[k + 1][j - 1] << '\n';
				if (t[j] == t[k])
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
				else
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1] + 1);
			}
		}
	}
	// for (int i = 0; i < n; i++)
	// 	cerr << t[i] << " \n"[i == n - 1]; 
	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < n; j++)
	// 		cerr << dp[i][j] << " \n"[j == n - 1];
	cout << dp[0][n - 1] << '\n';
}



int main(){
	#ifdef LOCAL
		freopen("F.in", "r", stdin);
		freopen("F.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> s)
        solve();

}