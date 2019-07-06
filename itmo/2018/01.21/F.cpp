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
string s = "UDLR";
inline void init(){

}

inline void solve(){
	for (int i = 0; i < 5e4; i++)
		cout << s[rand() % 4];
	cout << '\n';
}


int main(){
	srand(time(0));
	#ifdef LOCAL
		freopen("F.in", "r", stdin);
		freopen("F.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // while (cin >> n)
        solve();

}