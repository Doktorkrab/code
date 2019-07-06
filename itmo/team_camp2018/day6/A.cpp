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
vector<int> arr;
vector<int> arr1, arr2;

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    arr1.resize(m);
    arr2.resize(m);
    vec_in(arr);
    rep(i, m) {
        cin >> arr1[i];
        arr2[i] = -arr1[i];
    }

    sort(all(arr1));
    sort(all(arr2));
    vector<int> blocks;
    vector<int> current_block(n, -1);
    int block = 0;
    int left = -1;
    int zero_cnt = 0;
    rep(i, n) zero_cnt += arr[i] == 0;
    if (zero_cnt == n) {
        cout << "0\n";
        rep(i, n) cout << arr1[0] << " \n"[i == n - 1];
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (arr[i] == 0) {
                current_block[i] = block;
            }
            continue;
        }

        if (arr[i] != 0) {
            if (arr[i - 1] == 0) {
                int right = arr[i];
                if (left > right) swap(left, right);
                int ind = lower_bound(all(arr1), left) - arr1.begin();
                int left_choose = (ind == m ? arr1.back() : arr1[ind]);
                int ind1 = lower_bound(all(arr2), -right) - arr2.begin();
                int right_choose = -(ind1 == m ? arr2.back() : arr2[ind1]);
//                cout << left_choose << " ! " << right_choose << '\n';
                if (abs(left_choose - left) + abs(left_choose - right) <
                    abs(right_choose - left) + abs(right_choose - right)) {
                    blocks.push_back(left_choose);
                } else {
                    blocks.push_back(right_choose);
                }
                block++;
            }
            left = -1;
            continue;
        }
        current_block[i] = block;
        if (arr[i - 1] != 0) left = arr[i - 1];
    }
    if (left != -1) {
        int right = left;
        if (left > right) swap(left, right);
        int ind = lower_bound(all(arr1), left) - arr1.begin();
        int left_choose = (ind == m ? arr1.back() : arr1[ind]);
        int ind1 = lower_bound(all(arr2), -right) - arr2.begin();
        int right_choose = -(ind1 == m ? arr2.back(                            ]q]q]q]q]q]q]q]q]q]q]q]q]q]q]q]q]q]q]qq]q]q]q]q]q]q]q]q]q]q]]q]q]q]q]q]q]q]q]q]abs(abs(abs(abs(abs(a
        a
        a
        zero_cnta
        a

        sd;d;'dse'''wsytu'us'tys'fsf'ghf
        qag
        a
        a
        )))))) : arr2[ind1]);
//        cout << left_choose << " ! " << right_choose << '\n';
        if (abs(left_choose - left) + abs(left_choose - right) < abs(right_choose - left) + abs(right_choose - right)) {
            blocks.push_back(left_choose);
        } else {
            blocks.push_back(right_choose);
        }
        block++;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (current_block[i] == -1) ans[i] = arr[i];
        else ans[i] = blocks[current_block[i]];
    }
    ll ans1 = 0;
    for (int i = 1; i < n; i++) ans1 += abs(ans[i] - ans[i - 1]);
    cout << ans1 << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}
