#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;
int n, m;

struct Node {
    int val = 0, push = 0;

    bool operator<(const Node &oth) const {
        return val < oth.val;
    }
};

const int MAXN = 4e6;
set<int> enters[MAXN];
Node st[MAXN];

inline void push(int v) {

    st[v].val += st[v].push;
//    st[v].lft += st[v].push;
    if (v * 2 + 1 < MAXN) {
        st[2 * v].push += st[v].push;
        st[2 * v + 1].push += st[v].push;
    }
    st[v].push = 0;
}

void insert(int v, int L, int R, int pos, int how) {
    push(v);
    if (pos < L || R <= pos) {
        return;
    }
    if (R - L == 1) {
        st[v].val += how;
        return;
    }
    int M = (L + R) / 2;
    insert(v * 2, L, M, pos, how);
    insert(v * 2 + 1, M, R, pos, how);

    auto tmp = max(st[2 * v], st[2 * v + 1]);
    st[v] = {tmp.val, st[v].push};
}

int get(int v, int L, int R, int l, int r) {
    push(v);
    if (r <= L || R <= l) {
        return -100000;
    }
    if (l <= L && R <= r)
        return st[v].val;
    int M = (L + R) / 2;
    int ans = max(get(v * 2, L, M, l, r), get(v * 2, M, R, l, r));

    auto tmp = max(st[2 * v], st[2 * v + 1]);
    st[v] = {tmp.val, st[v].push};
//    st[v] = max(st[2 * v], st[2 * v + 1]);
    return ans;
}

void insert_push(int v, int L, int R, int l, int r, int e) {
    // cerr << v << ' ' << L << ' ' << R << ' ' << l << ' ' << r << ' ' << e << '\n';
    push(v);
    if (r <= L || R <= l) {
        return;
    }
    if (l <= L && R <= r) {
        st[v].push += e;
        push(v);
        return;
    }
    int M = (L + R) / 2;
    insert_push(v * 2, L, M, l, r, e);
    insert_push(v * 2 + 1, M, R, l, r, e);
    auto tmp = max(st[2 * v], st[2 * v + 1]);
    st[v] = {tmp.val, st[v].push};

}

vector<int> arr;
vector<int> to_compress;
vector<pair<int, int>> query;

inline void init() {
    arr.resize(n);
    to_compress.resize(n + m);
    query.resize(m);
}

inline void solve() {
    init();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        to_compress[i] = arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> query[i].first >> query[i].second;
        to_compress[i + n] = query[i].second;
    }
    sort(to_compress.begin(), to_compress.end());
    to_compress.erase(unique(to_compress.begin(), to_compress.end()), to_compress.end());
    for (int i = 0; i < n; i++)
        arr[i] = lower_bound(to_compress.begin(), to_compress.end(), arr[i]) - to_compress.begin();

    for (int i = 0; i < m; i++)
        query[i].second = lower_bound(to_compress.begin(), to_compress.end(), query[i].second) - to_compress.begin();

    int N = 1;
    while (N < to_compress.size()) N *= 2;
    for (int i = 0; i < n; i++) {
        int gg = 0;
        if (!enters[arr[i]].empty())
            gg = *(enters[arr[i]].rbegin());
        enters[arr[i]].insert(i);
        insert(1, 0, N, arr[i], i - gg);
        insert_push(1, 0, N, arr[i], N, -1);
    }
    for (int i = 0; i < m; i++) {
        int gg = -(*(enters[arr[query[i].first]].rbegin()));
        enters[arr[query[i].first]].erase(query[i].first);
        if (!enters[arr[query[i].first]].empty())
            gg += *(enters[arr[query[i].first]].rbegin());

        insert(1, 0, N, arr[query[i].first], gg);
        insert_push(1, 0, N, arr[query[i].first], N, 1);
        arr[query[i].first] = query[i].second;

        int tmp = 0;
        if (!enters[query[i].second].empty())
            tmp = *(enters[query[i].second].rbegin());
        enters[query[i].second].insert(query[i].first);
        insert(1, 0, N, query[i].second, *(enters[query[i].second].rbegin()) - tmp);
        insert_push(1, 0, N, query[i].second, N, -1);
        cout << get(1, 0, N, 0, N) + 1 << '\n';
    }
}


int main() {
#ifdef LOCAL
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}