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
	for (int i = 0; i < n; i++){
		// cerr << arr[i].x << ' ' << arr[i].y << ' ' << arr[i].z << '\n';
		len = max(len, dist(kek, arr[i]));
	}
	// cerr << fixed << setprecision(20) << len << '\n';
	return len;
}
inline void solve(){
	ld x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++){
		ld a, b, c;
		cin >> a >> b >> c;
		arr[i] = {a, b, c};
		x += a, y += b, z += c;
		// cerr << i << '\n';
	}
	x /= 1. * n, y /= 1. * n, z /= 1. * n;
	cout << fixed << setprecision(20) << sqrt(check(x, y, z)) << '\n';
	// cerr << '\n';
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