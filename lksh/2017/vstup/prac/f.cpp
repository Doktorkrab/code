// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE
 
#define int long long
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define double ld
// #define ALLOC 
#define MAX INT_MAX
#define MIN INT_MIN
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0;i < n;i++)
#define ft first
#define st second
#define pb push_back
   
   
#ifdef ALLOC
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { }
#endif
   
// TEMPLATE END
   
// CODE HERE
struct Point{
    int x, y;
    friend istream& operator>>(istream& st, Point& x){
        st >> x.x >> x.y;
        return st; 
    }
    friend ostream& operator<<(ostream& st, Point& x){
        st << x.x << ' ' << x.y;
        return st; 
    }
    bool operator<(const Point& x1) const{
        return tie(x, y) < tie(x1.x, x1.y);
    }
    int vector_product(Point z){
        return x * z.y - y * z.x; 
    }

    int dot_product(Point z){
        return x * z.x + y * z.y;
    }
    Point operator- (const Point& o) const{
        return {x - o.x, y - o.y};
    }
    double len(){
        return sqrt(x * x * 1.L + y * y * 1.L);
    }
    double angle(Point z){
        return atan2(1.L * vector_product(z), 1.L * dot_product(z));
    }
};
vector<Point> points;
Point ox = {(int)1e9, 0};
int rotate(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
bool cmp(const Point& x, const Point& y){
    return rotate(points[0], x, y) > 0;
}
struct Solver{
    int n, ind = -1;
    vector<Point> stack;
    set<Point> st;
    Solver(){
        // Point kek = {(int)-1e9 - 1, (int)-1e9 + 1}, lul = {(int)1e9, (int)1e9};
        points.clear();
        cout.precision(5);
        cin >> n;
        forn(i, n){
            Point tmp;
            cin >> tmp;
            st.insert(tmp);
        }
        if (st.size() <= 2){
            cout << 0. << '\n';
            return;
        }
        for (Point i : st){
            points.pb(i);
        }
        n = points.size();
        forn(i, n){
            if (ind == -1 || points[ind].x > points[i].x){
                ind = i;
            }
        }
        swap(points[ind], points[0]);
        sort(points.begin() + 1, points.end(), cmp);
        cout << '\n';
        for (Point i : points) cout << i << '\n';
        stack.pb(points[0]);
        stack.pb(points[1]);
        for (int p = 2; p < n;p++){
            while (stack.size() >= 2 && rotate(stack[stack.size() - 2], stack[stack.size() - 1], points[p]) <= 0){
                stack.pop_back();
            }
            stack.pb(points[p]);
        }
        n = stack.size();
        vector<Point> stack1 = {stack[n - 1]};
        for (auto i : stack) stack1.pb(i);
        stack1.pb(stack[0]);
        double ans = DBL_MAX;
        // for (auto i : stack) cout << i << '\n';
        for (unsigned int i = 1;i + 1 < stack1.size();i++){
            ans = min(ans, fabs(1.L * (stack1[i - 1] - stack1[i]).angle(stack1[i + 1] - stack1[i]) * 180.L / M_PI));
        }
        assert(ans <= 360.);
        cout << ans << '\n';
    }   
};
   
// CODE END
   
signed main(){
    int t  = 1;
#ifdef LOCAL
    // assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    // string FN = "cut";
    // freopen((FN + ".in").c_str(), "r", stdin);
    // freopen((FN + ".out").c_str(), "w", stdout);
#endif
    while(t--){
#ifdef LOCAL
        clock_t t_elapsed = clock();
#endif
        Solver a;
#ifdef LOCAL
        cout << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }
   
}