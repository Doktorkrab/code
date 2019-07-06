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
#include <bitset>

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
void deb(const ts &... b) {

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

map<char, string> gg = {{'0', "0000"},
                        {'1', "0001"},
                        {'2', "0010"},
                        {'3', "0011"},
                        {'4', "0100"},
                        {'5', "0101"},
                        {'6', "0110"},
                        {'7', "0111"},
                        {'8', "1000"},
                        {'9', "1001"},
                        {'A', "1010"},
                        {'B', "1011"},
                        {'C', "1100"},
                        {'D', "1101"},
                        {'E', "1110"},
                        {'F', "1111"}};
vector<string> arr;
string encode24(const string &str) {
    string res;
    for (int i = 0; i < (int) str.size(); i += 6) {
        int tmp = 0;
        for (int j = 0; j < 6; j++) {
            tmp = tmp * 2 + (str[i + j] - '0');
        }
        char tmp1 = (char) (32 + tmp);
        res += tmp1;
    }
    return res;
}

string to_bin(const string& dec){
    string res;
    for (char c : dec) res += gg[c];
    return res;
}
void encodeString(int start, int finish) {
    string res;
    int cnt = 0;
    for (int i = start; i < finish; i += 3) {
        string tmp;
        for (int j = 0; j < 3 && i + j < finish; j++) {
            tmp += to_bin(arr[i + j]);
            cnt++;
        }
        while (tmp.size() != 24) tmp += '0';
        res += encode24(tmp);
//        cout << tmp;
    }
//    cout << '\n';
    cout << (char)(32 + cnt) << res << '\n';
}

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
//    cin.setf(ios::hex);
    arr.resize(n);
    rep(i, n){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i += 45) {
        encodeString(i, min(i + 45, n));
    }
    cout << (char) 96 << '\n';
}
