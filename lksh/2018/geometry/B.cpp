#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif
struct Point{
    ll x, y;
    ll vector_product(const Point& a) const {
        return x * a.y - a.x * y;
    }
    bool operator< (const Point& a){
        return vector_product(a) > 0;
    }
};
// -*-*-* All variables *-*-*-
vector<Point> points;
int n, m, k, cnt = 0;
// -*-*-* All functions *-*-*-
void init(){
    points.clear();
    cnt = 0;
}

void solve(){
    for (int i = 0;i < n; i++){
        cin >> points[i].x >> point[i].y;
    }
    
}
int main(){
    #ifdef LOCAL
    string taskName = "";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n >> m >> k){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}