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
int64_t a, b;
inline void init(){

}

inline void solve(){
    if (a % b == 0){
        cout << "0\n";
        return;
    }
    int64_t jopa = 1e18;
    int64_t gg = (a + jopa) % (b + jopa);
    if (gg == 0){
        cout << gg << '\n';
        return;
    }
    int64_t l = 0, r = 1e18 + 1;
    while (r - l > 1){
        int64_t m = (l + r) / 2;
        if ((a + m) % (b + m) == gg)
            r = m;
        else
            l = m;
    }
    if (l == 0)
        cout << "-1\n";
    else
        cout << l << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> b)
        solve();

}
