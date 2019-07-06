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

int n, s;
const int MAXN = 1e5 + 7;
set<pair<int, int>> setik;
pair<int, int> arr[MAXN];
inline void init(){

}

inline void solve(){
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        ans += arr[i].first;
        setik.insert({min(arr[i].first, arr[i].second), i});
    }
    while (s > 0 && setik.size()){
        auto top = *setik.rbegin();
        setik.erase(top);
        cerr << arr[top.second].first << ' ' << arr[top.second].second << '\n';
        arr[top.second].first -= top.first;
        ans -= top.first;
        --s;
        if (arr[top.second].first == 0)
            continue;
        setik.insert({min(arr[top.second].first, arr[top.second].second), top.second});
    }
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A2.in", "r", stdin);
		freopen("A2.out", "w", stdout);
	#else
                //freopen("castle.in", "r", stdin);
                //freopen("castle.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> s)
        solve();

}
