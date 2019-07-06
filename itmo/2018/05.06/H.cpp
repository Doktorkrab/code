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
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int MAXN = 2e5 + 7;
int n;
pair<int, int> arr[MAXN];
int ans[MAXN];
int ind[MAXN];
inline void init(){

}
// 2 3 4 4
// 0 1 2 3
inline void solve(){
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        ind[arr[i].second] = i < n / 2;
    for (int i = 0; i < n; i++){
        if (!ind[i])
            cout << arr[n / 2 - 1].first << ' ';
        else
            cout << arr[n / 2].first << ' ';
    }
    cout << '\n';
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