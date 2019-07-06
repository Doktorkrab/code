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
#define vec_out(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " \n"[i == v.size() - 1];
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

struct Query {
    int x, mn, mx;
};

struct Queue {
    vector<Query> stack, stack1;

    Queue() {}

    void push(int x) {
        if (stack.empty()) stack.push_back({x, x, x});
        else stack.push_back({x, min(stack.back().mn, x), max(stack.back().mx, x)});
    }

    void balance() {
        if (stack1.empty()) {
            while (!stack.empty()) {
                auto x = stack.back().x;
                stack.pop_back();
                if (stack1.empty()) stack1.push_back({x, x, x});
                else stack1.push_back({x, min(stack1.back().mn, x), max(stack1.back().mx, x)});
            }
        }
    }

    void pop() {
        balance();;
        stack1.pop_back();
    }

    int get_min() {
        int ret = INT_MAX;
        if (!stack.empty()) {
            ret = min(ret, stack.back().mn);
        }
        if (!stack1.empty()) {
            ret = min(ret, stack1.back().mn);
        }
        return ret;
    }

    int get_max() {
        int ret = INT_MIN;
        if (!stack.empty()) {
            ret = max(ret, stack.back().mx);
        }
        if (!stack1.empty()) {
            ret = max(ret, stack1.back().mx);
        }
        return ret;
    }
};

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    vec_in(arr);
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        int r = 0;
        Queue q;
        q.push(arr[0]);
        int lans = 0, rans = 0;
        for (int l = 0; l < n; l++) {
            int tmp = max(q.get_max(), arr[r + 1]);
            int tmp1 = min(q.get_min(), arr[r + 1]);
            while (r + 1 < n && tmp - tmp1 <= x) {
                q.push(arr[++r]);
                tmp = max(q.get_max(), arr[r + 1]);
                tmp1 = min(q.get_min(), arr[r + 1]);
            }
            if (rans - lans + 1 < r - l + 1) {
                lans = l;
                rans = r;
            }
            q.pop();
        }
        cout << lans + 1 << ' ' << rans + 1 << '\n';
    }
}
