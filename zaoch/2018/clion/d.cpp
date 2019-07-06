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

struct Node {
    int L, R;
    int value = 0, non_zero_cnt = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int L, int R) : L(L), R(R) {}
};

using nd = Node *;


int safe_cnt(nd a) {
    return a ? a->non_zero_cnt : 0;
}

nd recalc(nd a) {
    a->non_zero_cnt = safe_cnt(a->left) + safe_cnt(a->right) + (a->value != 0);
    return a;
}

nd build(int l, int r) {
    nd now = new Node(l, r);
    if (r - l == 1) {
        now->value = 0;
        now->non_zero_cnt = 0;
        return now;
    }
    int m = (l + r) / 2;
    now->left = build(l, m);
    now->right = build(m, r);
    return recalc(now);
}

nd update(nd a, int pos) {
    assert(a->L <= pos && pos < a->R);
    nd new_a = new Node(a->L, a->R);
    if (a->R - a->L == 1) {
        new_a->value = a->value + 1;
        new_a->non_zero_cnt = 1;
        return new_a;
    }
    if (pos < (a->L + a->R) / 2) {
        new_a->right = a->right;
        new_a->left = update(a->left, pos);
        return recalc(new_a);
    } else {
        new_a->left = a->left;
        new_a->right = update(a->right, pos);
        return recalc(new_a);
    }
}

int get(nd l, nd r){
    assert(l && r);
    if (r->R - r->L == 1) return r->L;
    int len = (l->left->R - l->left->L);
    int non_zeroes =
    if (right_zeroes - left_zeroes > 0) return get(l->left, r->left);
    return get(l->right, r->right);
}

void solve(int n, int q) {
    vector<int> arr(n);
    vec_in(arr);
    vector<nd> versions(n + 1ULL);
    versions[0] = build(0, n + 2);
    for (int i = 0; i < n; i++) {
        versions[i + 1] = update(versions[i], arr[i]);
    }
    for (int i = 0; i < q; i++){
        char type;
        int l, r;
        cin >> type >> l >> r;
        if (type == '!') assert(0);
        if (type == '?'){
            prn(get(versions[l - 1], versions[r]));
        }
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("array.in", "r", stdin);
#else
//    ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
#endif
    int n, q;
    int t = 1;
    while (cin >> n >> q) {
        deb("test", t++, "\nN Q:", n, q);
        solve(n, q);
    }
}
