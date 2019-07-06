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
#define int int64_t
using namespace std;
struct Vector{
    int x, y;
    
    int vector_product(const Vector& oth) const {
        return x * oth.y - oth.x * y;
    }

    int scalar_product(const Vector& oth) const {
        return x * oth.x + y * oth.y;
    }

    bool operator<(const Vector& oth) const {
        return tie(x, y) < tie(oth.x, oth.y);
    }

    int len() const {
        return x * x + y * y;
    }
    
    friend istream& operator>>(istream& is, Vector& x){
        is >> x.x >> x.y;
        return is;
    }
    
    friend ostream& operator<<(ostream& os, const Vector& x){
        os << x.x << ' ' << x.y;
        return os;
    }

    Vector operator-(const Vector& oth) const {
        return {x - oth.x, y - oth.y};
    }
};
struct Line{
    int a, b, c;
    friend istream& operator>>(istream& is, Line& a){
        is >> a.a >> a.b >> a.c;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Line& a){
        os << a.a << ' ' << a.b << ' ' << a.c;
        return os;
    }
    int f(const Vector& o) const {
        return a * o.x + b * o.y;
    }
    int dist(const Vector& o) const {
        return f(o) + c;
    }
};
vector<Vector> build_convex(vector<Vector> points);
bool line_intersection(const vector<Vector> &convex, const Line& ln);
int n, m;
vector<Vector> pnts;
inline void init(){
    pnts.resize(n);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> pnts[i];

    auto convex = build_convex(pnts);
    for (int i = 0; i < m; i++){
        int type;
        cin >> type;
        if (type == 1){
            Vector tmp;
            cin >> tmp;
            convex.push_back(tmp);
            convex = build_convex(convex);
        }

        if (type == 2){
            Line ln;
            cin >> ln;
            ln.c *= -1;
            if (!line_intersection(convex, ln))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}


int32_t main(){
	#ifdef LOCAL
		freopen("238.in", "r", stdin);
		freopen("238.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();
}

vector<Vector> build_convex(vector<Vector> points){
    int n = points.size();
    if (n < 3)
        return points;
    
    
    int ind = 0;
    for (int i = 0; i < n; i++){
        if (points[i] < points[ind])
            ind = i;
    }
    swap(points[ind], points[0]);

    sort(points.begin() + 1, points.end(), 
        [&](const Vector& a, const Vector& b){
            if ((a - points[0]).vector_product(b - points[0]) == 0)
                return (a - points[0]).len() < (b - points[0]).len();
            return (a - points[0]).vector_product(b - points[0]) > 0;
        }
    );

    vector<Vector> stack = {points[0], points[1]};
    for (int i = 2; i < n; i++){
        while (stack.size() >= 2 && (stack[stack.size() - 2] - stack[stack.size() - 1]).vector_product(points[i] - stack[stack.size() - 1]) >= 0)
            stack.pop_back();
        stack.push_back(points[i]);
    }
    stack.push_back(points[0]);
    return stack;
}
int bin_search(const vector<Vector> &convex, const Line &ln, int coef = 1){
    int l = 0, r = convex.size() - 1;
    int f0 = ln.f(convex[0]) * coef;
    while (r - l > 1){
        int m = (l + r) / 2;
        int nxt = ln.f(convex[m + 1]) * coef;
        if (ln.f(convex[m]) * coef > f0)
            l = m;
        else if (ln.f(convex[m]) * coef > nxt)
            l = m;
        else
            r = m;
    }
    return ln.f(convex[r]);
}
bool line_intersection(const vector<Vector> &convex, const Line &ln){
    int a = bin_search(convex, ln, 1);
    int b = bin_search(convex, ln, -1);
    if (a > b)
        swap(a, b);
    return a <= -ln.c && -ln.c <= b;
}


