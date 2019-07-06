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

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    vector<int> ans;
    vector<bool> type = {1};
    string s;
    getline(cin, s);
    int n;
    int cnt_pl = 0, cnt_mn = 0;
    rep(i, s.size()) {
        if (s[i] == '=') {
            n = stoi(s.substr(i + 1));
            break;
        }
        if (s[i] == '+') type.push_back(1), cnt_pl++;
        if (s[i] == '-') type.push_back(0), cnt_mn++;
    }
    if (cnt_pl && !cnt_mn > n){
        prn("Impossible\n");
        return 0;
    }
    if (n - cnt_pl <= 0){
        ans.push_back(1);
        cnt_mn += cnt_pl - n + 1;
    }
    else ans.push_back(n - cnt_pl);
    repab(i, 1, type.size()) {
        if (type[i] == 0) ans.push_back(1);
        else {
            ans.push_back(min(1 + cnt_mn, n));
            if (1 + cnt_mn < n) cnt_mn = 0;
            else cnt_mn -= n - 1;
        }
    }
    if (cnt_mn != 0){
        prn("Impossible");
    }
    else{
        prn("Possible");
        rep(i, type.size()){
            if (i != 0) cout << "-+"[type[i]] << " ";
            cout << ans[i] << " ";
        }
        cout << "= " << n << '\n';
    }
}
