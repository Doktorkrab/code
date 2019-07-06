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
unordered_map<int, int> xes, yes;
map<pair<int, int>, int> points;

inline void init(){
    xes.clear();
    yes.clear();
    points.clear();
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        xes[x]++;
        yes[y]++;
        points[{x, y}]++;
    }
    int64_t ans = 0;
    for (auto [x, c] : xes){
        ans += 1LL * c * (c - 1) / 2;
    }
    for (auto [y, c] : yes)
        ans += 1LL * c * (c - 1) / 2;
    for (auto [xy, c] : points)
        ans -= 1LL * (c - 1) * c / 2;
    cout << ans << '\n';
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
