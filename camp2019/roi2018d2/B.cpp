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

const int MAXN = 3e3 + 7;
int n;
int arr[MAXN];
int pos[MAXN];
int arr1[MAXN];
vector<pair<int, int>> ans;
inline void init(){
    ans.clear();
}
void shift(int l, int r){
    ans.push_back({l + 1, r});
    int m = r - l;
    int cnt = 0;
    for (int i = 1; i < m; i += 2)
        arr1[cnt++] = arr[i + l];
    for (int i = 0; i < m; i += 2)
        arr1[cnt++] = arr[i + l];
    for (int i = 0; i < m; i++){
        arr[i + l] = arr1[i];
        pos[arr[i + l]] = i + l;
    }
}
inline void solve(){
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        pos[--arr[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--){
        while (pos[i] != i){
            shift(pos[i], i + 1);
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i.first << ' ' << i.second << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}