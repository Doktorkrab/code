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

int a, b, c;
int x, y, z;


inline void init(){

}

inline void solve(){
	if (a < x){
		cout << "NO\n";
		return;
	}
	a -= x;
	if (a + b < y){
		cout << "NO\n";
		return;
	}
	int kek = a + b - y;
	kek += c;
	if (kek < z)
		cout << "NO\n";
	else
		cout << "YES\n";

}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> x >> y >> z >> a >> b >> c)
        solve();

}