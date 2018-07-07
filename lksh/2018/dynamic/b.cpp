#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
vector<vector<int>> dp;
int x, a, y, b, l;

// -*-*-* All functions *-*-*-
int bin_search(){
    int l = 0, 
}
void init(){
}

void solve(){
    cin >> x >> a >> y >> b >> l;
}
int main(){
    #ifdef LOCAL
    string taskName = "";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
    #else
    string taskName = "";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
    #endif
    while(t--){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}