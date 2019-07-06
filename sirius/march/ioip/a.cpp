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
using namespace __gnu_pbds;
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;
int n;
const int MAXN = 1e5;
int arr[MAXN];
inline void init(){

}

inline void solve(){
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        s.insert({arr[i], i});
    }
    while (!s.empty()){
        cout << (*(s.find_by_order((s.size() - 1) / 2))).first << ' ';
        s.erase(s.find_by_order((s.size() - 1)  / 2));
    }
    cout << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
