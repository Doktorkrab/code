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
string s, t;
inline void init(){

}

inline void solve(){
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	for (int i = 0; i < min(s.size(), t.size()); i++){
		if (s[i] != t[i]){
			cout << i << '\n';
			return;
		}
	}
	cout << min(s.size(), t.size()) << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s >> t)
        solve();

}