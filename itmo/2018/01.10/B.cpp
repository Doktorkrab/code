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
const int MAXN = 2e5 + 7;
int n;
string s;
int prefix[2][MAXN + 1];
inline void init(){
	n = (int) s.size();
	for (int i = 0; i < 2; i++)
			memset(prefix[i], 0, sizeof(int) * (MAXN + 1));
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2; j++)
				prefix[j][i + 1] = prefix[j][i];
		if (s[i] == '1')
			prefix[i & 1][i + 1]++;
	}
	cerr << prefix[1][n] << ' ' << prefix[0][n] << '\n'; 
	for (int i = 0; i < n; i++){
		int tmp[2] = {prefix[0][i], prefix[1][i]};
		// cerr << i + 1 << ' ' << tmp[0] << ' ' << tmp[1] << ' ' << prefix[1][n] - prefix[1][i + 1] << ' ' << prefix[0][n] - prefix[0][i + 1] << '\n';
		tmp[0] += prefix[1][n] - prefix[1][i + 1];
		tmp[1] += prefix[0][n] - prefix[0][i + 1];
		if (tmp[0] == tmp[1]){
			cout << i + 1 << '\n';
			return;
		}
	}
	cout << 0 << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#else
		freopen("fair.in", "r", stdin);
		freopen("fair.out", "w", stdout);
	#endif
		
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}