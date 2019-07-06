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
	if (n == 1){
		int x, y;
		cin >> x >> y;
		cout <<  y << "\n1\n";
		cout << x << '\n';
		return;
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans1 = 1e9;
	int ans2 = 1e9;
	if (b != -1){
		ans1 = b;
		if (a <= c)
			ans1 += (c - a) / 2 + 1;
	}
	if (d != -1){
		ans2 = d;
		if (a >= c)
			ans2 += (a - c) / 2 + 1;
	}
	if (ans1 < ans2){
		cout << ans1 << '\n' << 1 << '\n';
		if (a <= c){
			int tmp = (c - a) / 2 + 1;
			a += tmp;
			c -= tmp;
		}
		cout << a << ' ' << c << '\n';
	}
	else{
		cout << ans2 << '\n' << 2 << '\n';
		if (a >= c){
			int tmp = (a - c) / 2 + 1;
			a -= tmp;
			c += tmp;
		}
		cout << a << ' ' << c << '\n'; 
	}
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#else
		freopen("elect.in", "r", stdin);
		freopen("elect.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}