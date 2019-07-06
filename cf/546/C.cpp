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
const int MAXN = 505;
multiset<int> diagonals[MAXN], diagonals1[MAXN];

int arr[MAXN][MAXN], arr1[MAXN][MAXN];
inline void init(){
    for (int i = 0; i < MAXN; i++){
        memset(arr[i], 0, sizeof(int) * MAXN);
        diagonals[i].clear();
    }
}

inline void solve(){
    init();
    for (int  i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < m; i++){
        int now_x = 0, now_y = i;
        while (now_x < n && now_y >= 0){
            diagonals[i].insert(arr[now_x++][now_y--]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < m; i++){
            int now_x = 0, now_y = i;
            while (now_x < n && now_y >= 0)
                diagonals1[i].insert(arr1[now_x++][now_y--]);
            if (diagonals1[i] != diagonals[i]){
                cout << "NO\n";
                return;
            }
            diagonals1[i].clear();
            diagonals[i].clear();
    }
    for (int i = 0; i < n; i++){
        int now_x = i, now_y = m - 1;
        while (now_x < n && now_y >= 0)
            diagonals[i].insert(arr[now_x++][now_y--]);
    }
    for (int i = 0; i < n; i++){
        int now_x = i, now_y = m - 1;
        while (now_x < n && now_y >= 0)
            diagonals1[i].insert(arr1[now_x++][now_y--]);
        if (diagonals1[i] != diagonals[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}