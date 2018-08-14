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
int cnt[2][2];
int n;
// -*-*-* All functions *-*-*-
void init(){
    cnt[0][0] = 0;
    cnt[0][1] = 0;
    cnt[1][0] = 0;
    cnt[1][1] = 0;
}

void solve(){
    init();
    string s;
    cin >> s;
    string t;
    cin >> t;
    int64_t ans = 0;
    for (int i = 0; i < n; i++){
        int x = s[i] - '0';
        int y = t[i] - '0';
        if (x && y) ans += cnt[0][0];
        if (x && !y) ans += cnt[0][0] + cnt[0][1];
        if (!x && y) ans += cnt[1][0];
        if (!x && !y) ans += cnt[1][1] + cnt[1][0];
        cnt[x][y]++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
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
    while(cin >> n){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}