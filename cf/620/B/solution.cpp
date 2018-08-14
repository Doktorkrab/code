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
int a, b;
vector<int> gg = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
// -*-*-* All functions *-*-*-
void init(){
}
int get_ans(int x){
    int ans = 0;
    while (x > 0){
        ans += gg[x % 10];
        x /= 10;
    }
    return ans;
}
void solve(){
    int64_t ans = 0;
    for (int i = a; i <= b; i++){
        ans += get_ans(i);
    }
    cout << ans << '\n';
}
int main(){
    #ifdef LOCAL
    clock_t start = clock();
    #endif
    while(cin >> a >> b){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}
