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
using ll = int64_t;
//------------------------------------------------------------------------------



int32_t main(){
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    vector<vector<int>> arr(20, vector<int>(n));
    vector<int> kek(n);
    vec_in(kek);
    int l;
    cin >> l;
    rep(i, n){
        // cout << upper_bound(all(arr[0]), arr[0][i] + l) - arr[0].begin() << '\n';
        arr[0][i] = upper_bound(all(kek), kek[i] + l) - kek.begin() - 1;
    }
    repab(i, 1, 20){
        rep(j, n){
            arr[i][j] = arr[i - 1][arr[i - 1][j]];
        }
        // prn();
    }
    int m;
    cin >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        int ans = 0;
        for (int i = 19; i >= 0; --i){
            // prn(a, b, arr[i][a], i);
            if (arr[i][a] < b){
                ans += (1 << i);
                a = arr[i][a];
            }
        }
        cout << ans + 1 << '\n';
    }
}
