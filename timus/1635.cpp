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
const int MAXN = 25;
#else
#define err() ;

const int INF = 1e9;
const int MAXN = 4005; 
#endif

const int64_t MOD = 150000001;
const int64_t MOD_SQR = MOD * MOD;
const int64_t BASE = 239;
// -*-*-* All variables *-*-*-
int64_t hsh[MAXN + 1], bases[MAXN + 1];
int64_t reverse_hsh[MAXN + 1];
string s;
int dp[MAXN], ans[MAXN], n;
// -*-*-* All functions *-*-*-
void init(){
    n = (int) s.size();
    hsh[0] = 0, bases[0] = 1;
    for (int i = 0; i < n; i++){
        hsh[i + 1] = ((hsh[i] * BASE) % MOD + s[i]) % MOD;
        bases[i + 1] = (bases[i] * BASE) % MOD;
    }
    reverse(s.begin(), s.end());
    reverse_hsh[0] = 0;
    for (int i = 0; i < n; i++){
        reverse_hsh[i + 1] = ((reverse_hsh[i] * BASE) % MOD + s[i]) % MOD;
    }
    reverse(s.begin(), s.end());
    fill(dp, dp + n, INF);
    fill(ans, ans + n, -1);
}

int get_hash(int l, int r){
    return (hsh[r] + MOD_SQR - (hsh[l] * bases[r - l]) % MOD) % MOD;
}

int get_reversed_hash(int l, int r){
    return (reverse_hsh[r] + MOD_SQR - (reverse_hsh[l] * bases[r - l]) % MOD) % MOD;
}

bool is_pal(int l, int r){ // [l, r]
    return get_hash(l, r + 1) == get_reversed_hash(n - r - 1, n - l);
}

void solve(){
    init();
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            if (is_pal(j, i)){
                int ans1 = (j ? dp[j - 1] : 0) + 1;
                if (ans1 >= dp[i]) continue;
                dp[i] = ans1;
                ans[i] = j - 1;
            }
        }
        // cerr << i << ' ' << dp[i] << ' ' << ans[i] << '\n';
    }
    cout << dp[n - 1] << '\n';
    vector<int> ans1;
    int v = n - 1;
    while (ans[v] != -1){
        // cerr << "!!!" << ans[v] << '\n';
        ans1.push_back(ans[v]);
        v = ans[v];
    }
    int j = 0;
    reverse(ans1.begin(), ans1.end());
    for (int i = 0; i < n; i++){
        cout << s[i];
        if (j < (int)ans1.size() && ans1[j] == i){
            cout << ' ';
            j++;
        }
    }
    cout << '\n';
}

int main(){
    #ifdef LOCAL
    string taskName = "1635";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> s){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}