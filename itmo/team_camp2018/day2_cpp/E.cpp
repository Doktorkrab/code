#include <bits/stdc++.h>


using namespace std;

struct Node {
    int l, r, max = 0;
    Node *leftNode = nullptr, *rightNode = nullptr;

    Node(int l, int r) : l(l), r(r) {}
};

Node *build(int l, int r) {
    Node *res = new Node(l, r);
    if (l == r) {
        return res;
    } else {
        int m = (l + r) / 2;
        res->leftNode = build(l, m);
        res->rightNode = build(m + 1, r);;
        return res;
    }
}

void st(Node *root, int ind, int val) {
    if (ind < root->l || ind > root->r)
        return;
    if (root->l == root->r) {
        root->max = max(root->max, val);
        return;
    }
    st(root->leftNode, ind, val);
    st(root->rightNode, ind, val);
    root->max = max(root->leftNode->max, root->rightNode->max);
}

int query(Node *root, int l, int r) {
    if (r < root->l || l > root->r)
        return -1;
    if (l <= root->l && root->r <= r) {
        return root->max;
    }
    return max(query(root->leftNode, l, r), query(root->rightNode, l, r));
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);

    int n, M;
    cin >> n >> M;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    auto aCopy = a;
    sort(begin(a), end(a));
    int posByInd[n];
    unordered_map<int, int> l;
    for (int i = 0; i < n; ++i) {
        posByInd[a[i].second] = i + 1;
        if (l.count(a[i].first) == 0) {
            l[a[i].first] = i + 1;
        }
    }
    Node *dp[2];
    for (int i = 0; i < 2; i++) {
        dp[i] = build(0, n + 3);
    }
    int ans = 0;
    for (int m = 0; m <= M; m++) {
        for (int i = 0; i < n; i++) {
            int val = posByInd[i];
            int realVal = aCopy[i].first;
            st(dp[1], val, query(dp[1], 0, l[realVal] - 1) + 1);
            if (m != 0) {
                int mx = query(dp[0], l[realVal], val - 1);
                mx = max(mx, query(dp[0], val + 1, n + 3));
                st(dp[m], val, mx + 1);
            }
        }
        ans = max(ans, dp[1]->max);
        swap(dp[1], dp[0]);

    }
    for (int i = 0; i < M + 1; i++) {
        ans = max(ans, dp[i]->max);
    }
    cout << ans;
}