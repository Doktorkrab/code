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
using ull = uint64_t;
//------------------------------------------------------------------------------

const ull BASE = 1e6 + 3;
const ull MOD = 150000001;

vector<vector<ull>> hashes;
vector<vector<int>> arr;
int bin_search(int i){
    int l = 0, r = min(arr[i].size(), arr[i + 1].size()) + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (hashes[i][m] == hashes[i + 1][m]) l = m;
        else r = m;
    }
    return l;
}
int32_t main(){
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n, c;
    cin >> n >> c;
    hashes.resize(n);
    arr.resize(n);
    rep(i, n){
        int cnt;
        cin >> cnt;
        arr[i].resize(cnt);
        hashes[i].resize(cnt + 1);

        rep(j, cnt){
            cin >> arr[i][j];
            hashes[i][j + 1] = (hashes[i][j] * BASE + arr[i][j]) % MOD;
        }
    }
    vector<int> jopa(c + 1);
    int sum = 0;
    rep(i, n - 1){
        int lcp = bin_search(i);
        if (lcp == arr[i].size()) continue;
        if (lcp == arr[i + 1].size()){
            cout << "-1\n";
            return 0;
        }
        int a = c - arr[i][lcp] + 1;
        int b = c - arr[i + 1][lcp] + 1;
        if (arr[i][lcp] < arr[i + 1][lcp]){
            jopa[b]++;
            jopa[a]--;
            continue;
        }
        jopa[0]++;
        jopa[a]--;
        jopa[b]++;
    }
//    vec_out(jopa);
    for (int i = 0; i < c; i++){
        sum += jopa[i];
        if (!sum){
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
