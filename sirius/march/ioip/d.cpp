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

const int MAXN = 3007;
int n, m, p;
int prefix[MAXN][MAXN];
int arr[MAXN][MAXN];
inline void init(){

}
int get(int x, int y, int x1, int y1){
    if (x == 0 && y == 0)
        return prefix[x1][y1];
    if (x == 0)
        return prefix[x1][y1] - prefix[x1][y - 1];
    if (y == 0)
        return prefix[x1][y1] - prefix[x - 1][y1];
    return prefix[x1][y1] - prefix[x - 1][y1] - prefix[x1][y - 1] + prefix[x - 1][y - 1]; 
}
inline void solve(){
    cout << 0;
}


int main(){
	#ifdef LOCAL
		freopen("d.in", "r", stdin);
		freopen("d.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
        solve();

}
