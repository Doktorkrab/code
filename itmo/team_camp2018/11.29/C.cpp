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

mt19937 rnd((uint64_t)
                    new char);

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

string curLexem;
string prevLexem;
string s;
int pos = 0;

void NextLexem() {
    prevLexem = curLexem;
    curLexem.clear();
    assert(pos != (int) s.size());
    if (s[pos] == '$') {
        curLexem = "$";
        pos++;
        return;
    }
    if (s[pos] == '/') {
        curLexem = "/";
        pos++;
        return;
    }
    if (s[pos] == '(') {
        curLexem = "(";
        pos++;
        return;
    }
    if (s[pos] == ')') {
        curLexem = ")";
        pos++;
        return;
    }
    if (s[pos] == '*') {
        curLexem = "*";
        pos++;
        return;
    }
    while (isalpha(s[pos])) {
        curLexem += s[pos++];
    }
}
const string lol = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
unordered_map<char, int> kek = {{'A', 0},
                                {'a', 1},
                                {'B', 2},
                                {'b', 3},
                                {'C', 4},
                                {'c', 5},
                                {'D', 6},
                                {'d', 7},
                                {'E', 8},
                                {'e', 9},
                                {'F', 10},
                                {'f', 11},
                                {'G', 12},
                                {'g', 13},
                                {'H', 14},
                                {'h', 15},
                                {'I', 16},
                                {'i', 17},
                                {'J', 18},
                                {'j', 19},
                                {'K', 20},
                                {'k', 21},
                                {'L', 22},
                                {'l', 23},
                                {'M', 24},
                                {'m', 25},
                                {'N', 26},
                                {'n', 27},
                                {'O', 28},
                                {'o', 29},
                                {'P', 30},
                                {'p', 31},
                                {'Q', 32},
                                {'q', 33},
                                {'R', 34},
                                {'r', 35},
                                {'S', 36},
                                {'s', 37},
                                {'T', 38},
                                {'t', 39},
                                {'U', 40},
                                {'u', 41},
                                {'V', 42},
                                {'v', 43},
                                {'W', 44},
                                {'w', 45},
                                {'X', 46},
                                {'x', 47},
                                {'Y', 48},
                                {'y', 49},
                                {'Z', 50},
                                {'z', 51},
};

struct MyString {
    vector<int> val;

    bool operator<(const MyString &oth) const {
        return val < oth.val;
    }

    MyString(const string &s) : val(s.size()) {
        for (int i = 0; i < (int) s.size(); i++) val[i] = kek[s[i]];
    }
    operator string() const {
        string s;
        for (int j : val) s += lol[j];
        return s;
    }
};

pair<map<MyString, int>, map<MyString, int>> parseFact() {
    map<MyString, int> ret;
    map<MyString, int> ret1;
    while (isalpha(curLexem[0]) || curLexem == "*" || curLexem == "/") {
        if (curLexem == "*" || curLexem == "/"){}
        else if (prevLexem == "/") ret1[curLexem]++;
        else ret[curLexem]++;
        NextLexem();
    }
    return {ret, ret1};
}
void merge(map<MyString, int>& a, map<MyString, int>& b){
    if (a.size() > b.size()) swap(a, b);
    for (auto i : a){
        b[i.first] += i.second;
    }
}
pair<map<MyString, int>, map<MyString, int>> parseExpr() {
    NextLexem();
    string tmp_lex;
    map<MyString, int> num;
    map<MyString, int> div;
    while (curLexem != "$" && curLexem != ")") {
        tmp_lex = prevLexem;
        if (isalpha(curLexem[0])) {
            auto tmp = parseFact();
            merge(tmp.first, num);
            merge(tmp.second, div);
            continue;
        }
        if (curLexem == "("){
//            NextLexem();
            auto tmp = parseExpr();
            if (tmp_lex == "/") swap(tmp.first, tmp.second);
            merge(tmp.first, num);
            merge(tmp.second, div);
            if (curLexem != "$") NextLexem();
            continue;
        }
        if (curLexem == "*" || curLexem == "/") NextLexem();
    }
    map<MyString, int> ret = num;
    map<MyString, int> ret1 = div;
    for (auto i : num){
        if (!div.count(i.first)) continue;
        ret[i.first] -= min(i.second, div[i.first]);
        ret1[i.first] -= min(i.second, div[i.first]);
        if (ret[i.first] == 0) ret.erase(i.first);
        if (ret1[i.first] == 0) ret1.erase(i.first);
    }
    return {ret, ret1};
}

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    cin >> s;
    if (s.empty()){
        cout << "1\n1\n";
        return 0;
    }
    s += '$';
    auto ans = parseExpr();
    vector<string> ans1;
    for (auto i : ans.first){
        for (int j = 0; j < i.second; j++){
            ans1.push_back(i.first);
        }
    }
    if (ans1.size() == 0) cout << "1\n";
    for (int i = 0; i < ans1.size(); i++){
        cout << ans1[i] << "*\n"[i == ans1.size() - 1];
    }
    ans1.clear();
    for (auto i : ans.second){
        for (int j = 0; j < i.second; j++){
            ans1.push_back(i.first);
        }
    }
    if (ans1.size() == 0) cout << "1\n";
    for (int i = 0; i < ans1.size(); i++){
        cout << ans1[i] << "*\n"[i == ans1.size() - 1];
    }
}