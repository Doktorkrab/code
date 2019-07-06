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
#define FAST_ALLOCATOR_MEMORY (int)5e6
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
	char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
	inline void * operator new ( size_t n ) {
		char *res = allocator_memory + allocator_pos;
		allocator_pos += n;
		assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
		return (void *)res;
	}
	inline void operator delete ( void * ) noexcept { }
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
using ll = int64_t;
//------------------------------------------------------------------------------
#define int ll


int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, (int) 1e9)), matrix1(n, vector<int>(n, (int) 1e9));
    rep(i, n) matrix1[i][i] = 0;
    for (auto &i : matrix) vec_in(i);
    vector<int> arr(n);
    vec_in(arr);
    reverse(all(arr));
    vector<bool> can_use(n);
    vector<int> ans;
    for (int &add : arr) {
        add--;
        rep(i, n) {
            matrix1[add][i] = min(matrix[add][i], matrix1[add][i]);
            matrix1[i][add] = min(matrix[i][add], matrix1[i][add]);
        }
        rep(i, n) {
            rep(j, n) {
                if (can_use[i] && can_use[j] && matrix1[add][j] + matrix1[j][i] < matrix1[add][i]) {
                    matrix1[add][i] = matrix1[add][j] + matrix1[j][i];
                }
            }
        }
        can_use[add] = 1;
        rep(i, n) {
            rep(j, n) {
                if (can_use[i] && can_use[j] && matrix1[i][j] + matrix1[j][add] < matrix1[i][add]) {
                    matrix1[i][add] = matrix1[i][j] + matrix1[j][add];
                }
            }
        }
        rep(i, n) {
            rep(j, n) {
                if (can_use[i] && can_use[j] && matrix1[i][add] + matrix1[add][j] < matrix1[i][j]) {
                    matrix1[i][j] = matrix1[i][add] + matrix1[add][j];
                }
            }
        }
        int sum = 0;
        rep(i, n) {
            rep(j, n) {
                if (can_use[i] && can_use[j] && matrix1[i][j] != (int) 1e9) sum += matrix1[i][j];
            }
        }
        ans.push_back(sum);
    }
    reverse(all(ans));
    vec_out(ans);

}
