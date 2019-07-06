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

int n, x;
vector<vector<string>> can = {{}, {},{"NO\n", "YES\n2 1\n"}, {"YES\n2 3\n1 1\n", "NO\n", "YES\n1 2\n3 1\n"}, {"YES\n1 2\n3 4\n1 1\n", "NO\n", "YES\n3 4\n1 1\n2 0\n", "NO\n", "YES\n3 1\n2 2\n 4 0\n"}};
inline void init(){

}

inline void solve(){
	cerr << can[n].size() << ' ' << n << ' ' << x << '\n';
	if (can[n].size() <= x)
		cout << "NO\n";
	else
		cout << can[n][x];
}


int main(){
	#ifdef LOCAL
		freopen("A_12.in", "r", stdin);
		freopen("A_12.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (cin >> n >> x)
        solve();

}