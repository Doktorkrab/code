#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

struct Node {
    int key, prior, sz;
    Node *left = nullptr, *right = nullptr;
    Node(int key) : key(key), prior((rand() << 15) | rand()), sz(1) {}
};

using node = Node *;

// -*-*-* All variables *-*-*-
node t;
int n;

// -*-*-* All functions *-*-*-

int safe_sz(node a) { return (a ? a->sz : 0); }
node pull(node a) {
    a->sz = safe_sz(a->left) + 1 + safe_sz(a->right);
    return a;
}

node merge(node a, node b) {
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->prior < b->prior) {
        a->right = merge(a->right, b);
        return pull(a);
    }
    b->left = merge(a, b->left);
    return pull(b);
}

using ptt = pair<node, node>;
ptt split(node t, int key) { // (-inf; x] [x; +inf)
    if (!t)
        return {nullptr, nullptr};
    if (t->key <= key) {
        auto tmp = split(t->right, key);
        t->right = tmp.first;
        return make_pair(pull(t), tmp.second);
    }
    auto tmp = split(t->left, key);
    t->left = tmp.second;
    return make_pair(tmp.first, pull(t));
}

void print(node t) {
    if (!t)
        return;
    print(t->left);
    cerr << t->key << ' ';
    print(t->right);
}

void insert(node &t, int key) { // t not nullptr
    assert(t);
    auto tmp = split(t, key);
    auto tmp1 = split(tmp.first, key - 1);
    tmp1.second = new Node(key);
    t = merge(merge(tmp1.first, tmp1.second), tmp.second);
}

void erase(node &t, int key) {
    assert(t);
    auto tmp = split(t, key);
    auto tmp1 = split(tmp.first, key - 1);
    tmp1.second = nullptr;
    t = merge(merge(tmp1.first, tmp1.second), tmp.second);
}
int get_by_order(node t, int k) {
    if (!t)
        return INF;
    if (safe_sz(t->left) == k)
        return t->key;
    if (safe_sz(t->left) > k)
        return get_by_order(t->left, k);
    return get_by_order(t->right, k - safe_sz(t->left) - 1);
}
void init() { t = nullptr; }

void solve() {
    cin >> n;
    while (n--) {
        int query, x;
        cin >> query >> x;
        if (query == 1) {
            if (!t)
                t = new Node(x);
            else
                insert(t, x);
        }
        if (query == -1) {
            erase(t, x);
        }
        if (query == 0) {
            cout << get_by_order(t, t->sz - x) << '\n';
        }
        // cerr << "!!!!";
        // print(t);
        // cerr << '\n';
    }
}
int main() {
#ifdef LOCAL
    string taskName = "E";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
#endif
    while (t--) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}