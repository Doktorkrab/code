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
using ld = double;
struct Vector{
	int64_t x, y;
	Vector(int64_t x, int64_t y) : x(x), y(y) {}
	Vector () {}
	friend istream& operator>>(istream& is, Vector& x){
		is >> x.x >> x.y;
		return is;
	}	
	friend ostream& operator<<(ostream& os, const Vector& x){
		os << "(" << x.x << ", " << x.y << ")";
		return os;
	}
	const Vector operator-(const Vector& oth) const {
		Vector ret = {x - oth.x, y - oth.y};
		return ret;
	}

	int64_t dist() const { 
		return x * x + y * y;
	}
	int64_t cross_product(const Vector& oth) const {
		return oth.x * x + oth.y * y;
	}
};
struct Line{
	int64_t a, b, c;
	Vector normal;
	Line(Vector p1, Vector p2){
		Vector napr = p2 - p1;
		normal = Vector(-napr.y, napr.x);
		a = normal.x;
		b = normal.y;
		c = -(normal.x * p1.x + normal.y * p1.y);
	}
	ld distFromPoint(const Vector& oth){
		return (abs(oth.x * a + oth.y * b + c) / sqrt(normal.dist()));
	}
};
struct Segment{
	Vector end1, end2;
	Segment(Vector p1, Vector p2) : end1(p1), end2(p2) {}
	friend ostream& operator<< (ostream& os, const Segment& s){
		os << "["<< s.end1 << ", " << s.end2 << "]";
		return os;
	}
	ld distFromPoint(const Vector& oth) const {
		if ((oth - end1).cross_product(end2 - end1) <= 0 || (oth - end2).cross_product(end1 - end2) <= 0){
			// cerr << oth << ' ' << end1 << ' ' << end2 << '\n';
			// cerr << (oth - end1) << ' ' << (oth - end2) << '\n';
			return sqrt(min((oth - end1).dist(),(oth - end2).dist()));
		}
		return Line(end1, end2).distFromPoint(oth);
	}
	ld distBetweenSegments(const Segment& oth) const {
		ld ret = min(oth.distFromPoint(end1), oth.distFromPoint(end2));
		return min(ret, min(distFromPoint(oth.end1), distFromPoint(oth.end2)));
	}
};
struct ConvexPolygon{
	int n = 0;
	vector<Vector> points;
	ConvexPolygon() {}
	friend istream& operator>> (istream& is, ConvexPolygon& cp){
		is >> cp.n;
		cp.points.resize(cp.n);

		for (int i = 0; i < cp.n; i++)
			is >> cp.points[i];
		return is;
	}
	friend ostream& operator<< (ostream& os, const ConvexPolygon& cp){
		for (int i = 0; i < cp.n; i++){
			os << cp.points[i] << '\n';
		}
		return os;
	}
	ld distBetweenPolygon(const ConvexPolygon& oth) const {
		vector<Segment> segments1;
		for (int i = 0; i + 1 < n; i++)
			segments1.push_back(Segment(points[i], points[i + 1]));
		segments1.push_back(Segment(points.back(), points[0]));
		// cerr << n << ' ' << oth.n << '\n';
		// for (int i = 0; i < n; i++){
		// 	cerr << segments1[i] << '\n';
		// }
		vector<Segment> segments2;
		for (int i = 0; i + 1 < oth.n; i++)
			segments2.push_back(Segment(oth.points[i], oth.points[i + 1]));
		segments2.push_back(Segment(oth.points.back(), oth.points[0]));
		// cerr << '\n';
		// for (int i = 0; i < segments2.size(); i++){
		// 	cerr << segments2[i] << '\n';
		// }
		ld maxans = 9e18;
		for (int i = 0; i < segments1.size(); i++){
			for (int j = 0; j < segments2.size(); j++){
				// cerr << i << ' ' << j << ' ' <<segments1[i].distBetweenSegments(segments2[j]) << '\n';
				maxans = min(segments1[i].distBetweenSegments(segments2[j]), maxans);
			}
		}
		return maxans;
	}
};
int n, a, b;
const int MAXN = 70;
ConvexPolygon polygons[MAXN];
ld dist[MAXN];
bool used[MAXN];
inline void init(){
	fill(polygons, polygons + MAXN, ConvexPolygon());
	fill(dist, dist + MAXN, LDBL_MAX);
	memset(used, 0, sizeof(bool) * MAXN);
}

inline void solve(){
	init();
	--a, --b;
	for (int i = 0; i < n; i++){
		cin >> polygons[i];
	}
	dist[a] = 0;
	// cerr << Segment({0, 0}, {0, 1}).distFromPoint({2, 3}) << '\n';
	// cerr << polygons[0].distBetweenPolygon(polygons[2]) << '\n';
	for (int gg = 0; gg < n; gg++){
		int v = -1;
		for (int i = 0; i < n; i++){
			if (!used[i] && (v == -1 || dist[v] > dist[i]))
				v = i;
		}
		used[v] = 1;
		for (int i = 0; i < n; i++){
			// cerr << dist[i] << ' ' << i << ' ' << v << ' ';
			// cerr << dist[v] + polygons[i].distBetweenPolygon(polygons[v]) << '\n';
			if (dist[i] > dist[v] + polygons[i].distBetweenPolygon(polygons[v])){
				dist[i] = dist[v] + polygons[i].distBetweenPolygon(polygons[v]);
				// cerr << i << ' ' << v << ' ' << dist[i] << '\n';
			}
		}
	}
	cout << fixed << setprecision(20) << dist[b] << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> a >> b)
        solve();

}