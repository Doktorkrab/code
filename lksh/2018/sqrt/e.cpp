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
const int INF = 101;
const int MAXN = 2e5 + 1;
#else
const int MAXN = 2e5 + 1;
#define err() ;

const int INF = 1e9; 
#endif
const uint64_t MOD = 1500000001;
const uint64_t BASE = 239;
const uint64_t MOD_SQR = MOD * MOD;
// -*-*-* All variables *-*-*-
uint64_t bases[MAXN + 1];
unordered_map<int64_t, vector<int>> ans;
string str[MAXN];
int n, q;

// -*-*-* All functions *-*-*-
void init(){
    bases[0] = 1;
    for (int i = 1; i < MAXN; i++) bases[i] = bases[i - 1] * BASE % MOD;
    ans.clear();
}
int calc_ans(const string& s, uint64_t hsh, int m){
    const int n = s.size();
    uint64_t hashes[n + 1];
    hashes[0] = 0;
    for (int i = 0; i < n; i++) hashes[i + 1] = (hashes[i] * BASE) % MOD + s[i];
    auto get_hash = [&](int l, int r){ return ((hashes[r] + MOD_SQR - (hashes[l] * bases[r - l]) % MOD) % MOD); }; // [l;r)
    for (int i = 0; i + m <= n; i++){
        if (get_hash(i, i + m) == hsh) return 1;
    }
    return 0;
}
void solve(){
    init();
    for (int i = 0; i < n; i++){
        cin >> str[i];
    }
    for (int i = 0; i < q; i++){
        int l, r;
        string t;
        cin >> l >> r >> t;
        uint64_t hsh = 0;
        int m = t.size();
        for (int i = 0; i < m; i++) hsh = (hsh * BASE) % MOD + t[i];
        if (!ans.count(hsh)){
            for (int i = 0; i < n; i++) if (calc_ans(str[i], hsh, m)) ans[hsh].push_back(i);
            sort(ans[hsh].begin(), ans[hsh].end());
        }
        print(cout, upper_bound(ans[hsh].begin(), ans[hsh].end(), r - 1) - lower_bound(ans[hsh].begin(), ans[hsh].end(), l - 1));
    }
}
int main(){
    #ifdef LOCAL
    string taskName = "e";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n >> q){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}