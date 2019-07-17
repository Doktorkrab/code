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
vector<int> arr;
inline void init(){
    arr.resize(n);
}
 
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int ans = 0;
    do{
        int sum = 0;
        for (int i = 1; i < n; i++)
            sum += abs(arr[i] - arr[i - 1]);
        // cerr << sum << ' ' << m << '\n';
        if (sum <= m){
            for (int i = 0; i < n; i++)
                cerr << arr[i] << ' ';
                cerr << '\n';
                ans++;
        }
    } while (next_permutation(arr.begin(), arr.end()));
     
    cout << ans << '\n';
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