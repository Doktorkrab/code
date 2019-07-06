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

int n, m, ta, tb, k;
vector<int> fir, sec;


inline void init(){
    fir.resize(n);
    sec.resize(m);
    for (int& i : fir)
        cin >> i;
    for (int& i : sec)
        cin >> i;    
}

inline void solve(){
    init();
    int pnt = 0;
    int ans = -1;
    // cerr << k << '\n';
    for (int i = 0; i <= k; ++i) {
        if (i >= n){
            cout << "-1\n";
            return;
        }
        while (pnt < m && sec[pnt] < fir[i] + ta)
            pnt++;
        // cerr << i << ' ' << pnt << ' ' << k - i << '\n';
        if (pnt + k - i >= m){
            cout << "-1\n";
            return;
        }
        // cerr << '\t' << sec[pnt + k - i] + tb << ' ' << pnt << '\n';
        ans = max(ans, sec[pnt + k - i] + tb);
    }
    cout << ans << '\n';
    // cerr << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> ta >> tb >> k)
        solve();

}