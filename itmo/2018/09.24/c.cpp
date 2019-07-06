#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
mt19937 rnd((uint64_t) new char);
int64_t rand(int64_t x, int64_t y){ return rnd() % (y - x + 1) + x; }
template<typename t>
t min(t a){
    return a;
}
template<typename t, typename... ts>
t min(const t& a, const ts&... as){
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}
template<typename t>
t max(t a){
    return a;
}
template<typename t, typename... ts>
t max(const t& a, const ts&... as){
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}
void prn(ostream& os){
    os << '\n';
}
void prn(){
    cout << '\n';
}
template<typename t, typename... ts>
void prn(ostream& os, const t& a, const ts&... b){
    os << a << ' ';
    prn(os, b...);
}
template<typename t, typename... ts>
void prn(const t& a, const ts&... b){
    cout << a << ' ';
    prn(cout, b...);
}
#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = uint64_t;
//------------------------------------------------------------------------------

const ll BASE = 11027;
const ll MOD = 1500000001;
const ll BASE1 = 239;
const ll MOD11 = 150000001;
pair<ll, ll> get_hash(vector<int>& a){
    ll hash = 0;
    ll hash1 = 0;
    // prn("now:");
    sort(all(a));
    for (auto i : a){
        // cout << i << ' ';
        hash = (((hash) * BASE) % MOD + i) % MOD;
        hash1 = (((hash1) * BASE1) % MOD11 + i) % MOD11;
    }
    // prn();
    return {hash, hash1};
}

int32_t main(){
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // int t;
    // cin >> t;
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // int t = 1;
#endif
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    // rep(i, n) g[i].insert(i + 1);
    rep (i, m){
        int v, u;
        cin >> v >> u;
        --v, --u;
        // prn("!", v, u);
        g[v].push_back(u + 1);
        g[u].push_back(v + 1);
    }
    map<pair<ll, ll>, unsigned long long> cnt;
    rep(i, n){
        // auto gg = get_hash(g[i]);
        // prn(cerr, gg.first, gg.second);
        // cerr << get_hash(g[i]) << ' ' << i + 1 << '\n';
        cnt[get_hash(g[i])]++;
        g[i].push_back(i + 1);
        cnt[get_hash(g[i])]++;
    }
    unsigned long long ans = 0;
    for (const auto& i : cnt){
        ans += (i.second - 1) * i.second / 2;
    }
    cout << ans << '\n';
}
