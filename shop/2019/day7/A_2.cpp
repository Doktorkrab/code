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

// #define x first
// #define y second
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
using namespace std;
int n;
vector<Point> points;
inline void init(){
    points.resize(n);
}
int f(const Point& a, const Point& b, const Point& c){
    Point ab = b - a, ac = c - a;
    // cerr << ab.x  * ac.y << ' ' << ab.y * ac.x << '\n';
    return ab.x * ac.y == ab.y * ac.x;
}
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    vector<vector<int>> ans;
    vector<int> gg = {0,1,2};
    for (int i = 3; i < n; i++){
        if (points[i].x >= 0 && points[i].y >= 0)
            continue;
        sort(gg.begin(), gg.end());
        int ok = 0;
        do {
            if (f(points[gg[0]], points[gg[1]], points[i]))
                continue;
            Point tmp = points[gg[0]] + points[gg[1]] - points[i];
            if (tmp.x >= 0 && tmp.y >= 0){
                ok = 1;
                ans.push_back({gg[0] + 1, gg[1] + 1, i + 1});
                break;
            }
        } while (next_permutation(gg.begin(), gg.end()));
        // gg.push_back(i);
        if (!ok){
            // assert(0);
            cout << "-1\n";
            return;
        }
    }
    // if (ans.size() == 0)
    //     assert(0);
    cout << ans.size() << '\n';
    for (auto i : ans){
        for (int j : i)
            cout << j << ' ';
        cout << '\n';
    }

}


int main(){
	#ifdef LOCAL
		freopen("A_2.in", "r", stdin);
		freopen("A_2.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}