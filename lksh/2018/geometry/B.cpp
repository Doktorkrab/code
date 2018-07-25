#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <ctime>
#include <iomanip>

using namespace std;
using ll = long long;
#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif
struct Vector{
    ll x, y;
    ll vector_product(const Vector& a) const {
        return x * a.y - a.x * y;
    }
    ll len() const {
        return x * x + y * y;
    }
    friend istream& operator>>(istream& is, Vector& a){
        is >> a.x >> a.y;
        return is;
    }
    friend ostream& operator<<(ostream& ot, const Vector& a){
        ot << a.x << ' ' << a.y;
        return ot;
    }
    Vector operator-(const Vector& o) const { return {x - o.x, y - o.y}; }
    Vector& operator -=(const Vector& o) { return *(this) = *(this) - o; }
    bool operator< (const Vector& a) const {
        return vector_product(a) < 0;
    }
    bool operator <=(const Vector& a) const {
        return !(a < *(this));
    }
};
// -*-*-* All variables *-*-*-
vector<Vector> points;
int n, m, k, cnt = 0;
// -*-*-* All functions *-*-*-
void init(){
    points.resize(n);
    cnt = 0;
}
Vector tmp;

bool cmp1(const Vector& a, const Vector& b){
    return tie(a.y, a.x) < tie(b.y, b.x);
}
int bin_search(Vector a, const vector<Vector>& polygon){
    int l = 0, r = n;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (polygon[m] <= a) l = m;
        else r = m;
    }
    return r; 
}
bool is_inside(const Vector& a, const vector<Vector>& polygon){
    int ans = bin_search(a, polygon);
    // cerr << ans << '\n';
    if (ans == (int) polygon.size()){
        return polygon.back().vector_product(a) == 0 && a.len() <= polygon.back().len();
    }
    if (ans <= 1) return 0;
    int prev = (ans - 1 + (int) polygon.size()) % ((int) polygon.size());
    Vector for_check = (polygon[prev] - polygon[ans]);
    return for_check.vector_product(a - polygon[ans]) >= 0;
}
void solve(){
    init();
    if (k == 0){
        cout << "YES\n";
        return;
    } 
    for (int i = 0;i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    reverse(points.begin(), points.end());
    rotate(points.begin(), min_element(points.begin(), points.end(), cmp1), points.end());
    for (int i = 1; i < n; i++){
        points[i] -= points[0];
    }
    string ans = "NO\n";
    for (int i = 0; i < m; i++){
        Vector a;
        cin >> a;
        int kek = is_inside(a - points[0], points);
        cnt += kek;
        // cerr << kek << '\n';
        if (cnt >= k){
            ans = "YES\n";
        }
    }
    cout << ans;
    
}
int main(){
    #ifdef LOCAL
    string taskName = "B";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    // while(cin >> n >> m >> k){
    cin >> n >> m >> k;
    solve();
    #ifdef LOCAL
    cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
    #endif
    // }
}