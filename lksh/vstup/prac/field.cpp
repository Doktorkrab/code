#include <bits/stdc++.h>

using namespace std;

using ll = long long;


struct Event{
    int l, r;
    bool operator< (const Event& o) const{
        return tie(l, r) < tie(o.l, o.r);
    }
};

struct Point{
    long long x, y;
};

void prep(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}
long long trap_square(Point x, Point y){
    return (x.x - y.x) * (y.y + x.y);
}

long long tri_square(Point x, Point y){
    // return fabs((x.x * y.y - x.y * y.x) / 2.);
    return (x.x * y.y - x.y * y.x);
}
long long get_area(vector<Point>& points){
    vector<Point> new_pnt;/* = {points.back()};*/
    for (auto i : points) new_pnt.push_back(i);
    new_pnt.push_back(points[0]);
    int n = new_pnt.size();
    long long ans = 0;
    for (int i = 0; i + 1 < n;i++){
        ans += trap_square(new_pnt[i], new_pnt[i + 1]);
        // cout << "trap: "<<trap_square(new_pnt[i], new_pnt[i + 1]) << '\n';
    }
    return fabs(ans);
}
void run(){
    int n;

    cin >> n;
    vector<Point> points(n);
    for (int i = 0;i < n;i++){
        cin >> points[i].x >> points[i].y;
    }
    long long s1 = get_area(points), s2 = 0;
    long long mn = s1;
    int ind = 0, ind1 = 0, j = 1;
    for (int i = 0;i < n;i++){
        int nxt;
        while (s1 > s2){
            nxt = (j + 1) % n;
            long long tmp = tri_square(points[i], points[nxt]) - tri_square(points[i], points[j]) - tri_square(points[j], points[nxt]);
            s1 -= fabs(tmp);
            s2 += fabs(tmp);
            if (max(s1, s2) < mn){
                mn = max(s1, s2);
                ind = i;
                ind1 = nxt;
            }
            j = nxt;
        }
        nxt = (i + 1) % n;
        long long tmp = tri_square(points[i], points[nxt]) - tri_square(points[i], points[j]) - tri_square(points[j], points[nxt]);
        s1 += fabs(tmp);
        s2 -= fabs(tmp);
    }
    // cout << get_area(points) << '\n';
    // cout << mn << '\n';
    cout << ind + 1 << ' ' << ind1 + 1 << '\n';
}

int main() {
    string FN = "z-function";
//    assert(freopen((FN + ".in").c_str(), "r", stdin));
//    freopen((FN + ".out").c_str(), "w", stdout);


    int t = 1;
    prep();

// #ifdef LOCAL
//     cin >> t;
// #endif
    while (t--) run();
#ifdef LOCAL
    cerr << "Elapsed: " << (clock() * 1.) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}