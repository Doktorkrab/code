#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXS = 50;
#else
const int MAXS = 4000000;
const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
int n;
bitset<MAXS> bs;
vector<int> arr;

// -*-*-* All functions *-*-*-

void init(){
    bs.reset();
    bs[0] = 1;
    arr.assign(n, 0);
}
void solve(){
    cin >> n;
    init();
    int sum = 0;
    for (int& i : arr) {
        cin >> i;
        sum += i;
    }
    for (int i : arr){
        bs |= bs << i;
    }
    for (int i = (sum + 1) / 2; i <= MAXS; i++){
        if (bs.test(i)){
            cout << i << '\n';
            return;
        }
    }
    assert(0);
}
int main(){
    #ifdef LOCAL
    string taskName = "C";
    assert(freopen((taskName + ".in").c_str(), "r", stdin));
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
    #endif
    while(t--){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}