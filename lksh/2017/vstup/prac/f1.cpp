#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Point{
    ll x, y;
    bool operator< (const Point& o) const {
        return tie(x, y) < tie(o.x, o.y);
    }
    ll vector_product(const Point& o){
        return x * o.y - y * o.x;
    }
    ll dot_product(const Point& o){
        return x * o.x + y * o.y;
    }
    Point operator- (const Point& o){
        return {x - o.x, y - o.y};
    }
    double angle(const Point& o){
        return atan2(1.L * vector_product(o), 1.L * dot_product(o));
    }

    double len(){
        return sqrt(1. * x * x + 1. * y * y);
    }
};
vector<Point> points;

int cmp(Point a, Point b, Point c){
    if ((b - a).vector_product(c - b) < 0) return -1;
    else if ((b - a).vector_product(c - b) == 0) return 0;
    return 1;
}

bool cmp1(Point a, Point b){
    return cmp(points[0], a, b) == 1 ||
           (cmp(points[0], a, b) == 0 && (a - points[0]).len() < (b - points[0]).len());
}
int main(){
    cout.precision(20);
    int n;
    cin >> n;
    set<Point> st;
    for (int i = 0;i < n;i++){
        Point tmp;
        cin >> tmp.x >> tmp.y;
        st.insert(tmp);
    }
    for (Point x : st){
        points.push_back(x);
    }
    if (points.size() == 1){
        cout << 0.0 << '\n';
        return 0;
    }
    int ind = 0;
    n = points.size();
    for (int i = 0;i < n;i++){
        // if (points[ind].y > points[i].y || (points[ind].y == points[i].y && points[ind].x > points[i].x)) ind = i;
        if (points[ind].x > points[i].x) ind = i;
    }
    cout << '\n';
    swap(points[0], points[ind]);
    sort(points.begin() + 1, points.end(), cmp1);
    vector<Point> stack = {points[0], points[1]};
    for (int p = 2; p < n; p++){
        while(stack.size() >= 2 && cmp(stack[stack.size() - 2], stack[stack.size() - 1], points[p]) <= 0) 
            stack.pop_back();
        stack.push_back(points[p]);
    }
    vector<Point> stack1 = {stack.back()};
    for (Point x : stack) stack1.push_back(x);
    stack1.push_back(stack[0]);
    n = stack1.size();
    double ans = DBL_MAX;
    for (int i = 1; i + 1 < n;i++){
        ans = min(ans, fabs((stack1[i - 1] - stack1[i]).angle(stack1[i + 1] - stack1[i])) * 180. / M_PI);
    }
    cout << ans << '\n';
}