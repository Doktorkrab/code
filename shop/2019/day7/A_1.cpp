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
struct Point{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator+(const Point& oth) {
        return Point(x + oth.x, y + oth.y);
    }
    Point operator-(const Point& oth) const {
        return Point(x - oth.x, y - oth.y);
    } 
};

vector<Point> points;
inline void init(){
    points.resize(n);
}
inline bool check(){
    for (int i = 0; i < n; i++)
        if (points[i].x < 0 || points[i].y < 0)
            return 0;
    return 1;
}
int f(const Point& a, const Point& b, const Point& c){
    Point ab = b - a, ac = c - a;
    // cerr << ab.x  * ac.y << ' ' << ab.y * ac.x << '\n';
    return ab.x * ac.y == ab.y * ac.x;
}
inline void solve(){
    init();
    for (int i  = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    if (f(points[0], points[1], points[2])){
        cout << "-1\n";
        return;
    }
    vector<vector<int>> ans;
    while (!check()){
        // cerr << points[0].x << ' ' << points[0].y << '\n';
        // cerr << points[1].x << ' ' << points[1].y << '\n';
        // cerr << points[2].x << ' ' << points[2].y << '\n';
        auto tmp = (points[0] + points[1] - points[2]) - points[2];
        if (tmp.x > 0 || tmp.y > 0){
            points[2] = tmp + points[2];
            ans.push_back({1, 2, 3});
            continue;
        }

        tmp = (points[0] + points[2] - points[1]) - points[1];
        if (tmp.x > 0 || tmp.y > 0){
            points[1] = tmp + points[1];
            ans.push_back({1, 3, 2});
            continue;
        }

        tmp = (points[1] + points[2] - points[1]) - points[0];
        if (tmp.x > 0 || tmp.y > 0){
            points[0] = tmp + points[0];
            ans.push_back({2, 3, 1});
            continue;
        }
        assert(0);
        cout << "-1\n";
        return;
    }
    cout << ans.size() << '\n';
    for (auto i : ans){
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("A_1.in", "r", stdin);
		freopen("A_1.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}