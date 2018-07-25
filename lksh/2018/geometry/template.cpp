#include <bits/stdc++.h>

using namespace std;

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
    
    friend istream& operator>>(istream& is, Point& a){
        in >> a.x >> a.y;
        return in;
    }
    friend ostream& operator<<(ostream& ot, const Point& a){
        ot << a.x << ' ' << a.y;
        return ot;
    }

    bool operator< (const Point& a){
        return vector_product(a) > 0;
    }
};
// -*-*-* All variables *-*-*-


// -*-*-* All functions *-*-*-
void init(){
}

void solve(){

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
    while(cin){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}