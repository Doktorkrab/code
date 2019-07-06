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
#include <climits>
using namespace std;
using ld = long double;
int n, t;
struct pt{
    ld x, y;
};
struct line{
    ld a, b, c;
    pt intersect(const line& oth){
        if (a * oth.b - oth.a * b == 0)
            return {-INT_MAX, -INT_MAX};
        ld y = 1.L * (oth.c * a - c * oth.a) / (oth.a * b - a * oth.b);
        ld x = 1.L * (oth.c * b - c * oth.b) / (a * oth.b - oth.a * b);
        return {x, y};
    }
    ld len(const pt& oth){
        return 1.L * fabs(oth.x * a + oth.y * b + c) / sqrt(1.L * a * a + b * b);
    }
};
inline void init(){

}

inline void solve(){
    vector<line> gg(n);
    cerr << n << '\n';
    cout.precision(20);
    cout.setf(ios::fixed);
    cerr.precision(20);
    cerr.setf(ios::fixed);
    //assert(t != -1);
    for (int i = 0; i < n; i++){
        cin >> gg[i].a >> gg[i].b >> gg[i].c;
    }
    for (int i = 0; i < t; i++){
        line a;
        cin >> a.a >> a.b >> a.c;
        ld ans = INT_MAX;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                ans = min(ans, a.len(gg[i].intersect(gg[j])));
            }
        }
        cout << ans << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> t)
        solve();

}
