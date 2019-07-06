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
#include <string>
#include <cassert>

using namespace std;

mt19937 rnd((uint64_t) new char);

int64_t rand(int64_t x, int64_t y) { return rnd() % (y - x + 1) + x; }

template<typename t>
t min(t a) {
    return a;
}

template<typename t, typename... ts>
t min(const t &a, const ts &... as) {
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}

template<typename t>
t max(t a) {
    return a;
}

template<typename t, typename... ts>
t max(const t &a, const ts &... as) {
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}

void prn(ostream &os) {
    os << '\n';
}

void prn() {
    cout << '\n';
}

template<typename t, typename... ts>
void prn(ostream &os, const t &a, const ts &... b) {
    os << a << ' ';
    prn(os, b...);
}

template<typename t, typename... ts>
void prn(const t &a, const ts &... b) {
    cout << a << ' ';
    prn(cout, b...);
}

#ifdef LOCAL

template<typename... ts>
void deb(const ts &... b) {
    prn(cerr, "DEBUG", b...);
}

#else
template<typename... ts>
void deb(const ts&... b){
 
}
#endif

#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------

//#define int ll

int32_t main(){
#ifdef LOCAL
    freopen("kek.in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    int cnt[(int)(9e5 + 5)];
    int mx = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
        mx = max(x, mx);
    }
    int prefix[(int)(9e5 + 6)];
    for (int i = 1; i < (int)(9e5 + 5); i++){
        prefix[i + 1] = prefix[i] + cnt[i];
    }
    ll ans1 = 0;
    for (int i = 1; i <= mx; i++){
        if (cnt[i] == 0) continue;
        ll ans = 0;
        int j = 1;
        for (j = 1; i * (j - 1) <= mx; j++){
            ans += 1LL * (1LL * prefix[i * j] - prefix[i * (j - 1)]) * (j - 1LL) * i;
            if (ans < 0) assert(0);
        }
//        prn(ans1, ans, i);
        ans1 = max(ans1, ans);
    }
    cout << ans1 << '\n';
}