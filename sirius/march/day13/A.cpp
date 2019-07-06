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

const int MAXN = 1e3 + 7;
int n, m;
int matrix[2 * MAXN][2 * MAXN];
int good[2  * MAXN][2 * MAXN];
inline void init(){

}
inline int safe(int i, int j){
    if (i < 0 || j < 0)
        return 0;
    return good[i][j];
}
inline void solve(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x;
            cin >> x;
            matrix[i][j] = x - '0';
            matrix[i + n][j] = matrix[i][j];
            matrix[i][j + m] = matrix[i][j];
            matrix[i + n][j + m] = matrix[i][j];
            good[i][j] = 0;
        }
    }

    for (int i = 1; i < 2 * n; i++){
        for (int j = 1; j < 2 * m; j++){
            good[i][j] = good[i - 1][j] + good[i][j - 1] - good[i - 1][j - 1];
            if (matrix[i][j] == matrix[i - 1][j] && matrix[i][j - 1] == matrix[i - 1][j - 1] && matrix[i - 1][j - 1] == matrix[i][j]){
                good[i][j]++;
            } 
        }
    }
    // for (int i = 0; i < 2 * n; i++){
    //     for (int j = 0; j < 2 * m; j++){
    //         cerr << good[i][j] << " \n"[j == 2 * m - 1];
    //     }
    // }
    // for (int i = 0; i < 2 * n; i++){
    //     for (int j = 0; j < 2 * m; j++){
    //         cerr << matrix[i][j] << " \n"[j == 2 * m - 1];
    //     }
    // }

    int ans = 0;
    for (int i = 0; i + n < 2 * n; i++){
        for (int j = 0; j + m < 2 * m; j++){
            // cerr << i << ' ' << j << ' ' << safe(i + n - 1, j + m - 1) << ' ' << safe(i + n - 1, j) << ' ' <<  safe(i, j + m - 1) << ' ' <<  safe(i, j) << '\n';
            ans = max(ans, safe(i + n - 1, j + m - 1) - safe(i + n - 1, j) - safe(i, j + m - 1) + safe(i, j));
        }
    }
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
        freopen("video.in", "r", stdin);
        freopen("video.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
