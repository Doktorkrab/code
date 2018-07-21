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

const double EPS = 1e-8;
#ifdef LOCAL
const int INF = 100;
#else
#define err() ;
const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
vector<pair<double, double>> arr;
int n, k;

// -*-*-* All functions *-*-*-
void init(){
    arr.resize(n);
}

bool check(double m){
    vector<double> tmp(n);
    for (int i = 0; i < n; i++){
        tmp[i] = 1. * arr[i].first - 1. * arr[i].second * m;
    }
    nth_element(tmp.begin(), tmp.begin() + n - k, tmp.end());
    double ans = 0;
    for (int i = 1; i <= k; i++) ans += tmp[n - i];
    return ans >= 0;
}

double bin_search(){
    double l = -1, r = 1e11;
    for (int i = 0; i < 100; i++){
        double m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    // print(cerr, l);
    return l;
}
void solve(){
    init();
    for (int i = 0;i < n; i++) cin >> arr[i].first >> arr[i].second;
    // print(cout, fixed, bin_search());
    auto an = bin_search();
    vector<pair<double, int>> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = {1. * arr[i].first - 1. * arr[i].second * an, i};
    }
    nth_element(ans.begin(), ans.begin() + n - k, ans.end());
    for (int i = 1; i <= k; i++) cout << ans[n - i].second + 1 << ' ';
    cout << '\n';
    // print(cout, fixed, check(2. / 3));
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
    while(cin >> n >> k){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}