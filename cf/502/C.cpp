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

// -*-*-* All functions *-*-*-
void init(){

}

void stupid(){
    // if (n > 5) exit(1);
    int half = n / 2;
    for (int i = half + 1; i <= n; i++) cout << i << ' ';
    for (int i = 1; i <= half; i++) cout << i << ' ';
    cout << '\n';
}
void solve(){
    // if (n > 50) exit(1);
    // stupid();
    int ans_block = (int) sqrt(n + 0.5);
    // for (int block = 2; block * block <= n; block++){
    //     if (n % block == 0) ans_block = block;
    // }
    // if (!ans_block) {
    //     stupid();
    //     return;
    // }
    vector<int> ans(n);
    int sz = n / ans_block, cur = 1;
    for (int i = sz - 1; i < n; i+=sz){
        // cerr << i << '\n';
        for (int j = i; j > i - sz; j--) ans[j] = cur++;
    }
    --n;
    while (!ans[n]) ans[n--] = cur++;
    for (int i : ans) cout << i << ' ';
    cout << '\n' << '\n';
}

int main(){
    #ifdef LOCAL
    string taskName = "C";
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