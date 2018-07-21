#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;
void print(ostream& ot){
    ot << '\n';
}
template<typename Arg, typename... Args>
void print(ostream& ot, const Arg& arg, const Args&... args){
    ot << arg << ' ';
    print(ot, args...);
}
#define int int64_t


#ifdef LOCAL
#define err(x) print(cerr, #x, '=', x)
const size_t MAXN = 3e5;
#else
#define err(x) ;
const size_t MAXN = 3e5;
#endif
struct Point{
    int64_t x, y;

    bool operator<(const Point& o) const {
        return tie(y, x) < tie(o.y, o.x);
    }

    friend ostream& operator<<(ostream& ot, const Point& o){
        ot << o.x << ' ' << o.y;
        return ot;
    }
};


// -*-*-* All variables *-*-*-

Point points[MAXN];
int n;
int64_t ans_len = LONG_LONG_MAX;
Point first, second;
// -*-*-* All functions *-*-*-

int64_t len(Point& a, Point& b) { return ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)); }

void init(){
    ans_len = LONG_LONG_MAX;
}
vector<Point> split(int tl, int tr){
    if (tr - tl == 1){
        return {points[tl]};
    }

    int tm = (tl + tr) / 2;
    auto ret = split(tl, tm);
    auto ret1 = split(tm, tr);
    
    vector<Point> ans(tr - tl);
    merge(ret.begin(), ret.end(), ret1.begin(), ret1.end(), ans.begin());
    vector<Point> ans1;

    for (Point x : ans){
        if (abs(x.x - points[tm - 1].x) * abs(x.x - points[tm - 1].x) > ans_len) continue;
        ans1.push_back(x);
    }

    int sz = ans1.size();
    auto recalc = [&](int side, int start) {
        for (int l1 = 1; l1 < 11 && start + side * l1 < sz && start + side * l1 >= 0; l1++){
            // print(cerr, start + side * l1);
            if (len(ans1[start], ans1[start + side * l1]) < ans_len){
                ans_len = len(ans1[start], ans1[start + side * l1]);
                first = ans1[start];
                second = ans1[start + side * l1];
            }
        }
    };
    for (int l = 0; l < sz; l++){
        recalc(1, l);
        recalc(-1, l);    
    }
    return ans;
}

void solve(){
    init();
    for (Point& i : points) cin >> i.x >> i.y;
    sort(points, points + n, [](Point a, Point b){
        return tie(a.x, a.y) < tie(b.x, b.y); 
    });
    split(0, n);
    cout << first << '\n' << second << '\n';
}
int32_t main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    #ifdef LOCAL
    string taskName = "A";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}