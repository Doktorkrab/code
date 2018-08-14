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
int x, y, xt, yt;
// -*-*-* All functions *-*-*-
void init(){

}

void solve(){
    x = abs(x - xt);
    y = abs(y - yt);
    int ans = min(x, y);
    ans += max(x, y) - ans;
    cout << ans << '\n';
}
int main(){
    #ifdef LOCAL
    clock_t start = clock();
    #endif
    while(cin >> x >> y >> xt >> yt){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}
