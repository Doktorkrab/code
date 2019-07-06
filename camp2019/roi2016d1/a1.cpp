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
#define int int64_t
const int MAXN = 1e5 + 7;
int n, s;
pair<int, int> arr[MAXN];
inline void init(){
 
}
 
inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n, [&](const pair<int, int> & a, const pair<int, int> &b){return tie(a.second, a.first) < tie(b.second, b.first);});
    reverse(arr, arr + n);
    int64_t ans = 0;
    for (int i = 0; i < n; i++){
        if (s > 0){
            int need = (arr[i].first + arr[i].second - 1) / arr[i].second;
            need = min(need, s);
            s -= need;
            arr[i].first = max((int) 0, arr[i].first - need * arr[i].second);
        }
        ans += arr[i].first;
    }
    cout << ans << '\n';
}
 
 
int32_t main(){
    #ifdef LOCAL
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> s)
        solve();
 
}
