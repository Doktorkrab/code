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

int64_t n, a, b;

inline void init(){

}

inline void solve(){
    int ab = min(a, b);
    b -= ab, a -= ab;
    // cerr << a << ' ' << b << ' ' << ab << '\n';
    // cerr << (a + b > 0) << '\n';
    cout << (n + ab) * 2 + (a + b > 0) << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> b >> n)
        solve();

}