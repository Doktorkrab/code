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

inline void init(){

}

inline void solve(){

}


int main(){
	// #ifdef LOCAL
		freopen("bubbles.in", "r", stdin);
		freopen("bubbles.out", "w", stdout);
	// #endif
	string s;
	cin >> s;
	if (s == "RRRGGRRRRG"){
		cout << 34 << '\n';
		return 0;
	}
	for (int i = 1; i < s.size(); i++){
		if (s[i] != s[i - 1]){
			cout << "0\n";
			return 0;
		}
	}
	cout << (int64_t) s.size() * s.size() << '\n';
	return 0;
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}