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
#include <climits>
using namespace std;

int n, m, k;
const int MAXN = 5000;
const int MAXK = 100;
int matrix[MAXN][MAXN];
int letters[MAXK];
int bestUp[MAXN][MAXN];
int bestDown[MAXN][MAXN];
int bestRight[MAXN][MAXN];
int bestTail[MAXN][MAXN];
int bestLeft[MAXN][MAXN];
inline void init(){
    for (int i = 0; i < k; i++)
        cin >> letters[i];
}

inline void solve(){
    init();
    cin >> n >> m;
    for (int i = 0;  i < n; i++)
        for (int j = 0; j < m; j++){
            char x;
            cin >> x;
            matrix[i][j] = letters[x - 'a'];
        }


    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cerr << setw(2) << matrix[i][j];
    //         cerr << " ";
    //     }
    //     cerr << '\n';
    // }
    // cerr << '\n';
    for (int i = 0; i < m; i++){
        int prefix_sum = 0;
        int mn = 0;
        for (int j = 0; j < n; j++){
            prefix_sum += matrix[j][i];
            bestUp[j][i] = matrix[j][i];
            bestUp[j][i] = max(prefix_sum - mn, bestUp[j][i]);
            if (mn > prefix_sum)
                mn = prefix_sum;
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cerr << setw(2) << bestUp[i][j];
    //         cerr << " ";
    //     }
    //     cerr << '\n';
    // }
    // cerr << '\n';

    for (int i = 0; i < m; i++){
        int prefix_sum = 0;
        int mn = 0;
        for (int j = n - 1; j >= 0; --j){
            prefix_sum += matrix[j][i];
            bestDown[j][i] = matrix[j][i];
            bestDown[j][i] = max(prefix_sum - mn, bestDown[j][i]);
            if (mn > prefix_sum)
                mn = prefix_sum;
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cerr << setw(2) << bestDown[i][j];
    //         cerr << " ";
    //     }
    //     cerr << '\n';
    // }
    // cerr << '\n';

    int ans = INT_MIN;
    for (int i = 0; i < n; i++){
        int mn = 0;
        int prefix_sum = 0;
        for (int j = m - 1; j >= 0; --j){
            prefix_sum += matrix[i][j];
            bestRight[i][j] = matrix[i][j];
            // cerr << i << ' ' << j << ' ' << mn << ' ' << prefix_sum << '\n';
            bestRight[i][j] = max(prefix_sum - mn, bestRight[i][j]);
            if (mn > prefix_sum)
                mn = prefix_sum;
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cerr << setw(2) << bestRight[i][j];
    //         cerr << " ";
    //     }
    //     cerr << '\n';
    // }
    // cerr << '\n';

    for (int i = 0; i < n; i++){
        for (int j = m - 1; j >= 0; --j){
            bestTail[i][j] = bestUp[i][j] + bestDown[i][j] + (bestRight[i][j]) - 2 * matrix[i][j];
            if (j != m - 1)
                bestTail[i][j] = max(bestTail[i][j], bestTail[i][j + 1] + matrix[i][j]);
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cerr << setw(2) << bestTail[i][j];
    //         cerr << " ";
    //     }
    //     cerr << '\n';
    // }
    // cerr << '\n';

    for (int i = 0; i < n; i++){
        int prefix_sum = 0;
        int mn = 0;
        for (int j = 0; j < m; j++){
            prefix_sum += matrix[i][j];
            bestLeft[i][j] = matrix[i][j];
            bestLeft[i][j] = max(bestLeft[i][j], prefix_sum - mn);
            if (mn > prefix_sum)
                mn = prefix_sum;
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cerr << setw(2) << bestLeft[i][j];
    //         cerr << " ";
    //     }
    //     cerr << '\n';
    // }
    // cerr << '\n';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++){
            ans = max(ans, bestLeft[i][j] + bestUp[i][j] + bestTail[i][j + 1] - matrix[i][j]);
        }
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> k)
        solve();

}
