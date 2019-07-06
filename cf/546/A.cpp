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
int n;
pair<int, int> arr[MAXN];
inline void init(){

}

inline void solve(){
    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    int k;
    cin >> k;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (arr[i].second < k)
            continue;
        ans++;
    }
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}