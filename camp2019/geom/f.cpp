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
    bool operator==(const Point& a) const {
        return tie(x, y) == tie(a.x, a.y);
    }
};
struct Line{
    ll a, b, c;
};
// -*-*-* All variables *-*-*-
vector<Point> points;
vector<Line> lines;
int n, m;
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
ll f(const Point& p, const Line& a){
    return a.a * p.x + a.b * p.y;
}
int binSearch(const vector<Point>& polygon, const Line& a, int find_max){
    int l = 0, r = polygon.size();
    int f0 = f(polygon[0], a);
    while (r - l > 1){
        int m = (l + r) / 2;
        if (find_max){
            if (f(polygon[m], a) <= f0)
                r = m;
            else if (f(polygon[(m + 1) % polygon.size()], a) < f(polygon[m], a))
                r = m;
            else
                l = m;
        }
        else{
            if (f(polygon[m], a) >= f0)
                l = m;
            else if (f(polygon[(m + 1) % polygon.size()], a) < f(polygon[m], a))
                l = m;
            else
                r = m;
        }
    }
    return l;
}
bool check(const vector<Point>& polygon, Line a){
    int flag = 0;
    if (f(polygon[0], a) > f(polygon[1], a)){
        flag = 1;
        a.a *= -1;
        a.b *= -1;
    }
    int mn = -1, mx = -1;
    int res = binSearch(polygon, a, 1);
    if (flag)
        mn = res;
    else
        mx = res;
    flag ^= 1;
    a.a *= -1;
    a.b *= -1;
    res = binSearch(polygon, a, 0);
    if (flag)
        mn = res;
    else
        mx = res;
    cerr << f(polygon[mn], a) << ' ' << f(polygon[mx], a) << '\n';
    cerr << '\t' << mn << ' ' << mx << '\n';
    return f(polygon[mn], a) <= -a.c && -a.c <= f(polygon[mx], a);
}
void solve(){
    init();
    lines.resize(m);
    for (int i = 0; i < m; i++)
        cin >> lines[i].a >> lines[i].b >> lines[i].c;
    for (int i = 0; i < n; i++){
        Point tmp;
        cin >> tmp.x >> tmp.y;
        st.insert(tmp); 
    }
    for (Point x : st){
        cerr << '\t' << x.x << ' ' << x.y << '\n';
        points.push_back(x);
    }
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
    int n = stack.size() - (stack.back() == stack[0] && stack.size() > 1);
    if (points.size() <= 3){
        n = points.size();
        stack = points;
    }
    cerr << n << '\n';
    vector<Point> convex = {stack[0]};
    for (int i = 1; i < n; i++)
        convex.push_back(stack[i]);
    convex.push_back(stack[0]);
    n = convex.size();
    vector<int> ans;
    for (int i = 0; i < m; i++){
        if (check(convex, lines[i]))
            ans.push_back(i + 1);
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}
int32_t main(){
    #ifdef LOCAL
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> m >> n){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}
