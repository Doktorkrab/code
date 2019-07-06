#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
mt19937 rnd((uint64_t) new char);
int64_t rand(int64_t x, int64_t y){ return rnd() % (y - x + 1) + x; }
template<typename t>
t min(t a){
    return a;
}
template<typename t, typename... ts>
t min(const t& a, const ts&... as){
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}
template<typename t>
t max(t a){
    return a;
}
template<typename t, typename... ts>
t max(const t& a, const ts&... as){
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}
void prn(ostream& os){
    os << '\n';
}
void prn(){
    cout << '\n';
}
template<typename t, typename... ts>
void prn(ostream& os, const t& a, const ts&... b){
    os << a << ' ';
    prn(os, b...);
}
template<typename t, typename... ts>
void prn(const t& a, const ts&... b){
    cout << a << ' ';
    prn(cout, b...);
}
#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------



struct Point{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    Point() {}
};

ll get_area(Point a, Point b, Point c){
    return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) - (c.x - a.x)); 
}
bool arr[101][101];
int32_t main(){
    #ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif
    int n, d;
    cin >> n >> d;
    for (int i = 0;i <= n - d; i++){
        for (int j = 0; j < i; j++) arr[j][i + d] = arr[n - j][n - d - i] = 1;
    }
    for (int i = 0; i <= d; i++){
        for (int j = 0; j < i; j++) arr[j][d - i] = arr[n - j][n - d + i] = 1;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if (arr[x][y]) cout << "NO\n";
        else cout << "YES\n";
    }

}
