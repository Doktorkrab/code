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

void to_string(const string& s){
    cout << s;
}
template<typename T>
void to_string(const vector<T>& vec){
    cout << '{';
    bool is_first = 1;
    for (const T& i : vec){
        if (!is_first)
            cout << ", ";
        cout << to_string(i);
    }
    cout << '}';
}
void prn(){
    cout << '\n';
}
template<typename T, typename... Ts>
void prn(const T& t, const Ts&... ts){
    cout << to_string(t) << ' ';
    prn(ts...);

}
#define int int64_t
int n, m;
const int MAXN = 1e5 + 7;
int arr[MAXN], arr1[MAXN];
inline void init(){

}

inline void solve(){
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    sort(arr, arr + n);
    sort(arr1, arr1 + n);
    for (int i = 0; i < n; i++)
        ans = max(ans, abs(arr[i] - arr1[i]));
    cout << ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A_kek.in", "r", stdin);
		freopen("A_kek.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}