#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif
#define int ll
struct Point{
    ll x, y;
    ll vector_product(const Point& a){
        return  x * a.y - y * a.x; 
    }
    Point operator- (const Point& b) const{
        return {x - b.x, y - b.y};
    }
    ll len(){
        return (x * x + y * y);
    }
    bool operator< (const Point& a) const {
        return tie(x, y) < tie(a.x, a.y);
    }
};
// -*-*-* All variables *-*-*-
vector<Point> points;
int n;
set<Point> st;
// -*-*-* All functions *-*-*-

int cmp(Point a, Point b, Point c){
    if ((b - a).vector_product(c - b) < 0) return -1;
    if ((b - a).vector_product(c - b) == 0) return 0;
    return 1;
}

bool cmp1(Point a, Point b){
    return cmp(points[0], a, b) == 1 ||
        (cmp(points[0], a, b) == 0 && (a - points[0]).len() < (b - points[0]).len());
}
void init(){
    points.clear();
    st.clear();

}
ll trap_square(Point a, Point b){
    return (a.x - b.x) * (a.y + b.y);
}
ll get_area(vector<Point>& points){
    vector<Point> new_pnt = points;
    new_pnt.push_back(points[0]);
    ll ans = 0;
    for (int i = 0; i < points.size(); i++){
        ans += trap_square(new_pnt[i], new_pnt[i + 1]);
    }
    return ans;

}
void solve(){
    init();
    for (int i = 0; i < n; i++){
        Point tmp;
        cin >> tmp.x >> tmp.y;
        st.insert(tmp); 
    }
    for (Point x : st){
        points.push_back(x);
    }
    assert(points.size() > 2);
    int mx = 0;
    n = points.size();
    for (int i = 0; i < n; i++){
        if (points[mx].x > points[i].x) mx = i;
    }
    swap(points[0], points[mx]);
    sort(points.begin() + 1, points.end(), cmp1);
    points.push_back(points[0]);
    vector<Point> stack = {points[0], points[1]};
    for (int p = 2; p <= n; p++){
        while (stack.size() >= 2 && cmp(stack[stack.size() - 2], stack.back(), points[p]) <= 0)
            stack.pop_back();
        stack.push_back(points[p]);
    }
    int n = stack.size() - 1;
    vector<Point> convex = {stack[0]};
    for (int i = 1; i < n; i++){
        // if ((stack[i - 1] - stack[i]).vector_product(stack[i + 1] - stack[i]) == 0){
            // continue;
        // }
        convex.push_back(stack[i]);
    }
    cout << convex.size() << '\n';
    for (Point x : convex){
        cout << x.x << ' ' << x.y << '\n';
    }
    ll ans = get_area(convex);
    if (ans % 2){
        cout << ans / 2 << ".5\n";
    }
    else cout << ans / 2 << '\n';
}
int32_t main(){
    #ifdef LOCAL
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
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