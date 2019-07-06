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
int n;
int cnt;
struct triple{
    int a, b, c;
    bool operator<(const triple& oth) const {
        return tie(a, b, c) < tie(oth.a, oth.b, oth.c);
    }
};
triple arr[MAXN];
const int MAXC = 105;
int a[MAXC][MAXC][MAXC], b[MAXC][MAXC][MAXC], c[MAXC][MAXC][MAXC];
int aa[MAXC], bb[MAXC], cc[MAXC];
int ab[MAXC][MAXC], ac[MAXC][MAXC], bc[MAXC][MAXC];
// unordered_map<int, map<pair<int, int>, int>> a, b, c;
// unordered_map<int, int> aa, bb, cc;
// map<pair<int, int>, int> ab, ac, bc;
// map<pair<int, int>, int> ab, ac, bc;
// map<triple, int> abc;
inline void init(){
    // a.clear();
    // b.clear();
    // c.clear();
    // aa.clear();
    // bb.clear();
    // cc.clear();
    // ab.clear();
    // ac.clear();
    // bc.clear();
    // abc.clear();
    cnt = n;
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x = arr[i].a, y = arr[i].b, z = arr[i].c;
        // cerr << aa[x] - ab[{x, y}] - ac[{x, z}] + a[x][{y, z}] << ' '; 
        ans += aa[x] - ab[x][y] - ac[x][z] + a[x][y][z];
        // cerr << bb[y] - ab[x][y] - bc[y][z] + b[y][x][z] << ' '; 
        ans += bb[y] - ab[x][y] - bc[y][z] + b[y][x][z];
        // cerr << cc[z] - ac[x][z] - bc[y][z] + c[z][x][y] << '\n'; 
        ans += cc[z] - ac[x][z] - bc[y][z] + c[z][x][y];
        aa[x]++;
        bb[y]++;
        cc[z]++;
        ab[x][y]++;
        ac[x][z]++;
        bc[y][z]++;
        a[x][y][z]++;
        b[y][x][z]++;
        c[z][x][y]++;
    }
    cout << ans << '\n';
    cerr << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
        freopen("onlyone.in", "r", stdin);
        freopen("onlyone.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}