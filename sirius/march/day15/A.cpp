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

int64_t n;
inline void init(){

}

inline void solve(){
    int64_t a = 0, b = 0, c = 0;
    int gg = 59;
    for (; gg >= 0; gg--){
        if (3 * (1LL << gg) > n)
            continue;
        // cerr << gg << ' ' << n << '\n';
        // cerr << (1 << gg) << '\n';
        if (n - 3 * (1LL << gg) <= 3 * ((1LL << gg) - 1)){
            a += (1LL << gg);
            b += (1LL << gg);
            c += (1LL << gg);
            n -= 3 * (1LL << gg);
        }
        else{
            a += 2 * (1LL << gg);
            n -= 2 * (1LL << gg);
            ++gg;
        }
    }
    if (n == 1)
        a++;
    else if (n == 2){
        a++;
        b++;
    }
    cout << a << ' ' << b << ' ' << c << '\n';
    // cerr << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
        freopen("grants.in", "r", stdin);
        freopen("grants.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (cin >> n)
        solve();

}