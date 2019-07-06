#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
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

const ll BASE = 239;
const ll MOD = 1500000001;

int32_t main(){
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<vector<int>> ends(n);
    vector<ll> hashes(n + 1), hashes1(n + 1);
    vector<ll> bases(n + 1);
    bases[0] = 1;
    for (int i = 0; i < n; i++){
        hashes[i + 1] = (hashes[i] * BASE + s[i]) % MOD;
        bases[i + 1] = (bases[i] * BASE) % MOD;
    }
    reverse(all(s));
    for (int i = 0; i < n; i++){
        hashes1[i + 1] = (hashes1[i] * BASE + s[i]) % MOD;
    }
    auto get = [&](int l, int r){
        return (hashes[r] + MOD - (hashes[l] * bases[r - l]) % MOD) % MOD;
    };
    auto get_rev = [&](int l, int r){
        return (hashes1[r] + MOD - (hashes1[l] * bases[r - l]) % MOD) % MOD;
    };
    auto is_pal = [&](int l, int r){
        r++;
        int nr = n - l;
        int nl = n - r;
        return get(l, r) == get_rev(nl, nr);
    };
    reverse(all(s));
    for (int r = 0; r < n; r++){
        for (int l = 0; l <= r; l++){
            if (is_pal(l, r)) {
                // cout <<2 l << ' ' << r << '\n';
                ends[r].push_back(-l);
            }
        }
        reverse(all(ends[r]));
    }
    // vec_out(ends[1]);
    vector<vector<int>> ans(n, vector<int>(n));
    for (int l = 0; l < n; l++){
        // cout << "l: " << l << "\n";
        for (int r = l; r < n; r++){
            if (l != r) ans[l][r] = ans[l][r - 1];
            ans[l][r] += upper_bound(all(ends[r]), -l) - ends[r].begin();
            // cout << "\tr: " << r << " ||| " << ans[l][r] << " ||| " << upper_bound(all(ends[r]), -l) - ends[r].begin() << " ||| ";
            // vec_out(ends[r]);
        }
        // cout << '\n';
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << ans[l - 1][r - 1] << '\n';
    }
}
