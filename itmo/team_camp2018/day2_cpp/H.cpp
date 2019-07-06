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
#define int ll
int counterer = 0;

vector<int> merge(vector<int> a) {
    if (a.size() <= 1) {
        return a;
    }
    vector<int> a1;
    for (int i = 0; i < (a.size() / 2); ++i) {
        a1.push_back(a[i]);
    }
    a1 = merge(a1);
    vector<int> a2;
    for (int i = a.size() / 2; i < a.size(); ++i) {
        a2.push_back(a[i]);
    }
    a2 = merge(a2);
    int ind1 = 0;
    int ind2 = 0;
    a.clear();
    while (ind1 != a1.size() && ind2 != a2.size()) {
        if (a1[ind1] < a2[ind2]) {
            a.push_back(a1[ind1]);
            ind1++;
        } else {
            counterer += a1.size() - ind1;
            a.push_back(a2[ind2]);
            ind2++;
        }
    }
    if (ind1 == a1.size()) {
        a.insert(a.end(), a2.begin() + ind2, a2.end());
    } else {
        a.insert(a.end(), a1.begin() + ind1, a1.end());
    }
    return a;
}



int32_t main(){
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    vector<int> arr_even, arr_odd;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if ((a % 2) != (i % 2)) {
            cout << -1;
            return 0;
        }
        if (i % 2 == 0) {
            arr_even.push_back(a);
        } else {
            arr_odd.push_back(a);
        }
    }
    merge(arr_even);
    merge(arr_odd);
    cout << counterer;
    return 0;

}
