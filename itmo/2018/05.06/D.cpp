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

int n, m;
const int MAXN = 10;
bool fld[MAXN][MAXN];
bool can[MAXN][MAXN];
inline void init(){
    memset(fld, 0, sizeof(bool) * MAXN * MAXN);
    memset(can, 0, sizeof(bool) * MAXN * MAXN);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m;j++){
            char x;
            cin >> x;
            fld[i][j] = x == '#';
        }
    can[0][0] = 1;
    for (int i = 0; i < n; i++){
        int was = 0;
        for (int j = 0; j < m; j++){
            // cerr << can[i][j] << " \n"[j == m - 1];
            if (can[i][j] && i != n - 1)
                can[i + 1][j] = fld[i + 1][j];
            if (can[i][j] && j != m - 1)
                can[i][j + 1] = fld[i][j + 1];
            if (fld[i][j]){
                if (!can[i][j] || was){
                    cout << "Impossible\n";
                    return;
                }
                was = (i != n - 1 && can[i + 1][j]);
            }
        }
    }
    cout << "Possible\n";
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}