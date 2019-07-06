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

const int MAXN = 5e3 + 7;
int n, q;
int arr[MAXN];
int prefix[MAXN];
bool good[MAXN][MAXN];
inline void init(){

}

int ans(){
    int ret = 0;
    for (int i = 0; i < n; i++)
        cerr << arr[i] << " \n"[i == n - 1];
    for (int i = 0; i <= n; i++)
        cerr << prefix[i] << " \n"[i == n];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++){
            good[i][j] |= (prefix[j + 1] - prefix[i]) == (j - i + 1);
            ret += good[i][j];
            //cerr << i << ' ' << j << ' ' << good[i][j] << '\n';
        }
   // cerr << '\n';
    return ret;
}
inline void solve(){
    for (int i = 0; i < n; i++){
        char x;
        cin >> x;
        arr[i] = x - '0';
        prefix[i + 1] = prefix[i] + arr[i];
    }
    cout << ans() << '\n';
    for (int i = 0; i < q; i++){
        int l, r, c;
        cin >> l >> r >> c;
        for (int j = l - 1; j < r; j++)
            arr[j] = c;
        for (int j = 0; j < n; j++)
            prefix[j + 1] = prefix[j] + arr[j];
        cout << ans() << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
                freopen("lamps.in", "r", stdin);
                freopen("lamps.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> q)
        solve();

}
