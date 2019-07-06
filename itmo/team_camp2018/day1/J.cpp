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
pair<int, pair<int, int>> gcd(int a, int b){
    if (!b)
        return {a, {1, 0}};
    auto ret = gcd(b, a % b);
    return {ret.first, {ret.second.second, ret.second.first - ret.second.second * (a / b)}};
}

int32_t main(){
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    if (n == 1){
        prn(1);
        return 0;
    }
    int g = gcd(n, 9).first;
    if (g != 1){
        prn(0);
        return 0;
    }
    auto ret = gcd(9 / g, n / g);
    int x0 = ret.second.first, y0 = ret.second.second;
    x0 *= 1 / g;
    x0 = x0 % (n / g);
    y0 = (1 - n * x0) / 9;
    int cnt9 = x0;
    prn(cnt9);
    int kek = n - 1;
    int is_9 = 0;
    vector<char> ans;
    while (kek > 0){
        if (kek <= 8 || (is_9 && kek == 9)){
            ans.push_back(kek + '0');
            kek = 0;
            continue;
        }
        if (!is_9){
            kek -= 8;
            ans.push_back('8');
            is_9 = 1;
        }
        else{
            kek -= 9;
            ans.push_back('9');
        }
    }
    reverse(all(ans));
    for (char i : ans) cout << i;
    for (int i = 0; i < cnt9; i++) cout << 9;
    prn();
}
