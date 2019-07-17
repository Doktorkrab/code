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
    bool operator<(const Point& oth) const{
        return tie(x, y) < tie(oth.x, oth.y);
    }
    bool operator==(const Point& oth) const {
        return tie(x, y) == tie(oth.x, oth.y);
    }
};

int f(const Point& a, const Point& b, const Point& c){
    Point ab = b - a, ac = c - a;
    return ab.x * ac.y == ab.y * ac.x;
}
vector<Point> pt;
int n;

inline void init(){
    pt.resize(n);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> pt[i].x >> pt[i].y;
    int minx = 100, miny = 100;
    int maxx = -100, maxy = -100;
    for (int i = 0; i < n; i++){
        minx = min(minx, pt[i].x);
        miny = min(miny, pt[i].y);
        maxx = max(maxx, pt[i].x);
        maxy = max(maxy, pt[i].y);
    }
    if (minx >= 0 && miny >= 0){
        cout << "0\n";
        return;
    }
    int kek = -1;
    for (int i = 2; i < n; i++){
        if (!f(pt[0], pt[1], pt[i])){
            kek = i;
            break;
        }
    }
    if (kek == -1){
        cout << "-1\n";
        return;
    }
    map<vector<Point>, pair<vector<Point>, vector<int>>> p;
    map<vector<Point>, bool> used;
    p[{pt[0], pt[1], pt[kek]}] = {{}, {-1, -1, -1}};
    // cerr << p.count({pt[0], pt[1], pt[kek]}) << '\n';
    // return;
    deque<vector<Point>> q = {{pt[0], pt[1], pt[kek]}};
    vector<vector<int>> ans;
    while (!q.empty()){
        auto pts = q.front();
        q.pop_front();
        // cerr << pts[0].x << ' ' << pts[0].y << '\n';
        // cerr << pts[1].x << ' ' << pts[1].y << '\n';
        // cerr << pts[2].x << ' ' << pts[2].y << '\n';
        // cerr << q.size() << '\n';
        // cerr << '\n';
        int minx = 100, miny = 100;
        int maxx = -100, maxy = -100;
        for (int i = 0; i < 3; i++){
            minx = min(minx, pts[i].x);
            miny = min(miny, pts[i].y);
            maxx = max(maxx, pts[i].x);
            maxy = max(maxy, pts[i].y);
        }
        if (maxx < -40 && maxy < -40)
            continue;
        if (maxx >= 40 || maxy >= 40)
            continue;
        if (minx >= 5 && miny >= 5){
            // cerr << "\n\n";
            // int cnt = 0;
            // vector<Point> tmp = {pts[0], pts[1], pts[2]};
            vector<Point> tmp1 =  {pt[0], pt[1], pt[kek]};
            pt[0] = pts[0];
            pt[1] = pts[1];
            pt[kek] = pts[2];
            cerr << "!\n";
            while (pts != tmp1){
                // for (int i = 0; i < 3; i++)
                //     cerr << pts[i].x << ' ' << pts[i].y << '\n';
                // cerr << '\n';
                ans.push_back(p[pts].second);
                auto tmp = p[pts].first;
                pts = tmp;
            }
            reverse(ans.begin(), ans.end());

            break;
        }
        auto tmp = pts[0] + pts[1] - pts[2];
        if (!used[{pts[0], pts[1], tmp}]){
            used[{pts[0], pts[1], tmp}] = 1;
            p[{pts[0], pts[1], tmp}] = {{pts[0], pts[1], pts[2]}, {0,1,kek}};
            q.push_back({pts[0], pts[1], tmp});
        }
        tmp = pts[0] + pts[2] - pts[1];
        if (!used[{pts[0], tmp, pts[2]}]){
            used[{pts[0], tmp, pts[2]}] = 1;
            p[{pts[0], tmp, pts[2]}] = {{pts[0], pts[1], pts[2]}, {0,kek,1}};
            q.push_back({pts[0], tmp, pts[2]});
        }
        tmp = pts[2] + pts[1] - pts[0];
        if (!used[{tmp, pts[1], pts[2]}]){
            used[{tmp, pts[1], pts[2]}] = 1;
            p[{tmp, pts[1], pts[2]}] = {{pts[0], pts[1], pts[2]}, {kek,1,0}};
            q.push_back({tmp, pts[1], pts[2]});
        }
    }
    // swap(pt[2], pt[kek]);
    vector<int> gg = {0,1,kek};
    for (int i = 2; i < n; i++){
        // if (pt[i])
        if (pt[i].x >= 0 && pt[i].y >= 0)
            continue;
        sort(gg.begin(), gg.end());
        int ok = 0;
        do {
            if (f(pt[gg[0]], pt[gg[1]], pt[i]))
                continue;
            Point tmp = pt[gg[0]] + pt[gg[1]] - pt[i];
            if (tmp.x >= 0 && tmp.y >= 0){
                ok = 1;
                ans.push_back({gg[0], gg[1], i});
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

    assert(ans.size() <= 2500);
    cout << ans.size() << '\n';
    for (auto i : ans){
        for (int j : i)
            cout << j + 1 << ' ';
        cout << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}