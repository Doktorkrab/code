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

#define FAST_ALLOCATOR_MEMORY 5e6
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
char allocator_memory[(int) FAST_ALLOCATOR_MEMORY];

inline void *operator new(size_t n) {
    char *res = allocator_memory + allocator_pos;
    allocator_pos += n;
    assert(allocator_pos <= (int) FAST_ALLOCATOR_MEMORY);
    return (void *) res;
}

inline void operator delete(void *) noexcept {}
//inline void * operator new [] ( size_t ) { assert(0); }
//inline void operator delete [] ( void * ) { assert(0); }
#endif
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
using ll = uint64_t;
//------------------------------------------------------------------------------

const ll MOD = 1e9 + 7;
const ll BASE = 101;

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    vector<string> strs_(n);
    map<string, int> strs;
    rep(i, n) {
        cin >> strs_[i];
        strs[strs_[i]] = i;
    }
    rep(i, n) {
        int m = strs_[i].size() / 2;
        for (int j = 0; j < m; j++) {
            int k = j, good = 1;
            while (k >= 0) {
                good &= strs_[i][k] == strs_[i][(int) strs_[i].size() - k - 1];
                --k;
            }
            if (!good) continue;
            string to_find;
            for (k = m; k < strs_[i].size() - j - 1; k++) to_find += strs_[i][k];
            if (strs.count(to_find)) {
                cout << "YES\n";
                cout << strs[to_find] + 1 << " " << i + 1 << '\n';
                return 0;
            }
        }
        for (int j = m; j < strs_[i].size(); j++) {
            int k = 0, good = 1;
            while (j + k < strs_[i].size()) {
                good &= strs_[i][k] == strs_[i][j + k];
                ++k;
            }
            if (!good) continue;
            string to_find;
            for (int k = strs_[i].size() - j; k < j; k++) to_find += strs_[i][k];
            if (strs.count(to_find)) {
                cout << "YES\n";
                cout << i + 1 << " " << strs[to_find] + 1 << '\n';
                return 0;
            }
        }
    }
    prn("NO\n");
}
