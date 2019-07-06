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



int32_t main(){
#ifdef LOCAL
#else
#endif
//    ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
    freopen("chronicle.in", "r", stdin);
    freopen("chronicle.out", "w", stdout);
    vi arr(3);
    scanf("%d/%d/%d", &arr[0], &arr[1], &arr[2]);
    sort(all(arr));
//    int ans = 0;
    set<string> kek;
    do{
        vector<int> month = {0, 31, 28 + (arr[2] % 4 == 0 && arr[2] % 100 != 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sum = 0;
//        for (int i : month) sum+=i;
//        cout << sum << '\n';
//        vec_out(arr);
        if (arr[1] > 12 || arr[1] == 0) continue;
        if (arr[0] > month[arr[1]] || arr[0] == 0) continue;
//        ans = 1;
        string s;
        if (arr[0] < 10) s += "0" + to_string(arr[0]) + "/";
        else s += to_string(arr[0]) + "/";
        if (arr[1] < 10) s += "0" + to_string(arr[1]) + "/";
        else s += to_string(arr[1]) + "/";
        if (arr[2] < 10) s += "0" + to_string(arr[2]);
        else s += to_string(arr[2]);
        kek.insert(s);

    } while (next_permutation(all(arr)));
    if (kek.empty()){
        cout << "No such date\n";
    }
    else for (const string& i : kek) cout << i << '\n';
}