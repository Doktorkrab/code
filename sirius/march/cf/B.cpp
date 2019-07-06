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
const int MAXN = 2e5;
int arr[MAXN];
inline void init(){

}

inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverse(arr, arr + n);
    int64_t ans = arr[0];
    for (int i = 1; i < n; i++){
        arr[i] = min(arr[i], arr[i - 1] - 1);
        arr[i] = max(arr[i], 0);
        ans += arr[i];
    }
    cout << ans << '\n';
}


int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
