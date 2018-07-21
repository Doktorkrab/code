#include <bits/stdc++.h>

using namespace std;
void print(ostream& ot){
    ot << '\n';
}
template<typename Arg, typename... Args>
void print(ostream& ot, const Arg& arg, const Args&... arg1){
    ot << arg << ' ';
    print(ot, arg1...);
}


#define err(x) print(cerr, #x, x)

#ifdef LOCAL
const int INF = 100;
#else
#define err() ;

const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
int n;
#define int int64_t
vector<pair<int, int>> arr;
// -*-*-* All functions *-*-*-
void init(){
    arr.resize(n);
}
void solve(){
    init();
    int64_t min_x = LONG_LONG_MAX, max_x = LONG_LONG_MIN;
    int64_t min_y = LONG_LONG_MAX, max_y = LONG_LONG_MIN;
    for (int i = 0; i < n; i++){
        int64_t x, y;
        cin >> x >> y;
        min_x = min(min_x, x - y);
        max_x = max(max_x, x - y);
        min_y = min(min_y, x + y);
        max_y = max(max_y, x + y);
        arr[i] = {x, y};
    }
    int64_t x = (min_x + max_x);
    int64_t y = (min_y + max_y);
    // print(cerr, min_x, max_x, min_y, max_y);
    // print(cerr, x, y);
    int64_t x1 = (x + y) / 4;
    int64_t y1 = (y - x) / 4;
    int64_t ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, abs(x1 - arr[i].first) + abs(y1 - arr[i].second));
    }
    for (int nx = x1 - 5; nx <= x1 + 5; nx++){
        for (int ny = y1 - 5; ny <= y1 + 5; ny++){
            int64_t cur = 0;
            for (int i = 0; i < n; i++){
                cur = max(cur, abs(nx - arr[i].first) + abs(ny - arr[i].second));
            }
            if (cur < ans){
                ans = cur;
                x1 = nx;
                y1 = ny; 
            }
        }
    }
    print(cout, x1, y1);
}
int32_t main(){
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