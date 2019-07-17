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
int n, k;
vector<int> arr;
inline void init(){
    arr.resize(n);
}

inline void solve(){
    init();
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k)
        solve();

}