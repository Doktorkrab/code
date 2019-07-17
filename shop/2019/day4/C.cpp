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
const int MAXN = 1e2 + 5;
int fld[MAXN][MAXN];
inline void init(){

}

inline void solve(){
    if (n == 2){
        cout << "-1\n";
        return;
    }
    int kek = (n + 1) / 2;
    cout << kek;
    cout << '\n';
    for (int i = 0; i < kek; i++){
        fld[i][0] = 1;
        fld[kek - 1][i] = 1;
    }
    if (n % 2 == 0)
        fld[kek - 2][1] = 1;
    for (int i = 0; i < kek; i++){
        for (int j = 0; j < kek; j++)
            if (fld[i][j])
                cout << 'o';
            else
                cout << '.';
        cout << '\n';
    }

}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}