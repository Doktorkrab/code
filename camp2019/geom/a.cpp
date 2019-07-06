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
using ld = long double;
ld r, l;

inline void init(){

}

inline void solve(){
    if (2 * r <= l){
        cout << -r << ' ' << 0 << '\n' << r << " 0\n";
        return;
    }
    cout << -r << ' ' << 0 << '\n';
    ld x = (l * l - 2 * r * r) / (2 * r);
    ld y = sqrtl(r * r - x * x);
    cout << x << ' ' << y << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#else
                freopen("vikings.in", "r", stdin);
                freopen("vikings.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout.precision(20);
    cout.setf(ios::fixed);
    while (cin >> r >> l)
        solve();

}
