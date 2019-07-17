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
    int64_t sum = 0;
    int64_t t, ii;
    for (int64_t i = 1; i * i <= n; i++){
        sum += n / i;
        t = ii = i;
    }
    // cerr << sum << '\n';
    ++t;
    int64_t lst = n / ii;
    while (n / t == n / ii){
        sum += n / t++;
        // lst = t;
    }
    // cerr << sum << ' ' << lst << '\n';
    for (int64_t i = 1; i < lst; i++){
        // cerr <<(n / i) - (n / (i + 1)) << ' ' << i << '\n'; 
        sum += i * ((n / i) - (n / (i + 1)));
    }
    cout << sum << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("H.in", "r", stdin);
		freopen("H.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}