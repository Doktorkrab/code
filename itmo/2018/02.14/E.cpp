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
const long double EPS = 1e-9;
struct Point{
	long double x, y;
};
struct Line{
	long double a, b, c;
};
int n, q;
vector<Point> points;
long double vector_product(Point a, Point b){
	return a.x * b.y - a.y * b.x;
}

long double sign(Line a, Point x){
	Point aa;
	if (a.a == 0){
		aa.x = 0;
		aa.y = -a.c / a.b;
	}
	else if (a.b == 0){
		aa.x = -a.c / a.a;
		aa.y = 0;
	}
	else{
		aa.x = 0;
		aa.y = -a.c / a.a;
	}
	cerr << aa.x << ' ' << aa.y << '\n';
	Point napr = {-a.b, a.a};
	cerr << napr.x << ' ' << napr.y << '\n';
	Point vc = {x.x - aa.x, x.y - aa.y};
	cerr << vc.x << ' ' << vc.y << '\n';
	cerr << '\n';
 	if (fabs(vector_product(napr, vc)) < EPS)
		return 0;
	if (vector_product(napr, vc) < 0)
		return -1;
	return 1;
}

inline void init(){
	points.clear();
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}
	for (int i = 0; i < q; i++){
		int ch;
		cin >> ch;
		if (ch == 1){
			int x, y;
			cin >> x >> y;
			points.push_back({x, y});
		}
		else{
			int a, b, c;
			cin >> a >> b >> c;
			Line gg = {a, b, c};
			int sg = sign(gg, points[0]);
			if (sg == 0){
				cout << "NO\n";
				continue;
			}
			int good = 1;
			for (int j = 1; j < points.size(); j++){
				if (sg != sign(gg, points[j])){
					cout << "NO\n";
					good = 0;
					break;
				}
			}
			if (good == 1)
				cout << "YES\n";
		}
	}
}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // while (cin >> n >> q)
    cin >> n >> q;
        solve();

}