#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXM = 3;
#else
const int INF = 1e9;
const int MAXM = 5;
#endif

// -*-*-* All variables *-*-*-

vector<vector<int>> can;
vector<int> dp;
int64_t m, k;
// string n;

// -*-*-* All functions *-*-*-
vector<char> choose = {'b', 'w'};
string to_binary(int x) {
    string res;
    do {
        res += choose[x % 2];
        x >>= 1;
    } while (x);
    while ((int)res.size() < m)
        res += 'w';
    return res;
}
bool test(int mask, int bit) { return mask & (1 << bit); }

void init() {
    can.assign(1 << m, vector<int>(1 << m, 1));
    for (int mask = 0; mask < (1 << m); mask++) {
        for (int mask1 = 0; mask1 < (1 << m); mask1++) {
            for (int i = 1; i < m; i++) {
                can[mask][mask1] &= (test(mask, i) + test(mask1, i) + test(mask, i - 1) + test(mask1, i - 1)) % 4 != 0;
                if (!can[mask][mask1]) break;
            }
            if (!can[mask][mask1]) continue;
        }
    }

    dp.assign((1 << m), 1);
}

void solve() {
    int n;
    cin >> n;
    cin >> m;
    cin >> k;
    init();
    vector<vector<int>> dp(n, vector<int>((1 << m)));
    for (int i = 0; i < (1 << m); i++) dp[0][i] = 1;
    for (int i = 0; i + 1 < n; i++){
        for (int mask = 0; mask < (1 << m); mask++){
            for (int mask1 = 0; mask1 < (1 << m); mask1++){
                if (can[mask][mask1]) dp[i + 1][mask1] += dp[i][mask];
            }
            cerr << dp[i][mask] << ' ';
        }
        cerr << '\n';
    }
    cerr << '\n';
    int pos = 0;
    vector<string> ans;
    while(k && pos < n){
        cerr << k << ' ' << pos << ' ';
        if (ans.empty()) cerr << '\n';
        else cerr << ans.back() << '\n';
        for (int mask = 0; mask < (1 << m); mask++){
            if (k < dp[pos][mask]){
                pos++;
                ans.push_back(to_binary(mask));
                break;
            }
            k -= dp[pos][mask];
        }
    }
    if (k){
        cout << "Impossible\n";
    }
    else{
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cout << ans[j][i] << ' ';
            }
            cout << '\n';
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    string taskName = "B";
    freopen((taskName + ".in").c_str(), "r", stdin);
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
    while (t--) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}