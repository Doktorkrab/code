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
#include <cfloat>
using namespace std;

int n;
const int MAXN = 105;
using ld = long double;
struct Point{
	ld x, y, z;
};
Point arr[MAXN];

inline void init(){
	for (int i = 0; i < MAXN; i++)
		arr[i] = {0, 0, 0};
}
inline ld dist(Point x, Point y){
	return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y) + (x.z - y.z) * (x.z - y.z);
}
inline ld check(ld x, ld y, ld z){
	Point kek = {x, y, z};
	ld len = -DBL_MAX;
	// cerr << x << ' ' << y << ' ' << z << '\n';
	for (int i = 0; i < n; i++)
		len = max(len, dist(kek, arr[i]));
	// cerr << fixed << setprecision(20) << len << '\n';
	return len;
}
inline ld tern(ld x, ld y){
	ld l = -1e6, r = 1e6;
	ld lastl = DBL_MAX, lastr = DBL_MAX;
	for (int i = 0; i < 60; i++){
		ld a = (l + l + r) / 3;
		ld b = (l + r + r) / 3;
		ld lasta = check(x, y, a);
		ld lastb = check(x, y, b);
		if (lasta < lastb)
			r = b, lastr = lastb;
		else
			l = a, lastl = lasta;
	}
	return min(lastl, lastr);
}
inline ld tern2(ld x){
	ld l = -1e6, r = 1e6;
	ld lastl = DBL_MAX, lastr = DBL_MAX;
	for (int i = 0; i < 60; i++){
		ld a = (l + l + r) / 3;
		ld b = (l + r + r) / 3;
		ld aa = tern(x, a);
		ld bb = tern(x, b);
		if (aa < bb){
			r = b, lastr = bb;
		}
		else l = a, lastl = aa;
	}
	return min(lastl, lastr);
}
inline ld tern3(){
	ld l = -1e6, r = 1e6;
	ld lastl = DBL_MAX, lastr = DBL_MAX;
	for (int i = 0; i < 60; i++){
		ld a = (l + l + r) / 3;
		ld b = (l + r + r) / 3;
		ld aa = tern2(a);
		ld bb = tern2(b);
		if (aa < bb)
			r = b, lastr = bb;
		else
			l = a, lastl = aa;
		// cerr << aa << ' ' << bb << ' ' << lastl << ' ' << lastr << '\n';
	}
	return sqrt(min(lastl, lastr));
}
inline void solve(){
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
	cout << fixed << setprecision(20) << tern3() << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}