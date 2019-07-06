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

inline void init(){

}

inline void solve(){
	int blocks = (n + 1) / 2;
	if ((blocks & 1) ^ (x & 1))
		cout << "NO\n";
	else{
		cout << "YES\n";
		int ones = n & 1;
		for (int i = n; i >= 2; i -= 2){
			cout << i << ' ' << i - 1 << '\n';
			ones++;
		}
		int zero = 0;
		while (ones > 1){
			cout << "1 1\n";
			ones -= 2;
			zero++;
		}
		while (zero + ones > 1){
			cout << (ones == 1 ? "1 " : "0 ") << 0 << '\n';
			zero--;
		}
	}

}


int main(){
	#ifdef LOCAL
		freopen("A_23.in", "r", stdin);
		freopen("A_23.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (cin >> n >> x)
        solve();

}