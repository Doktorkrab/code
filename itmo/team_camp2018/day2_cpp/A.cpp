#include <bits/stdc++.h>
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

using namespace std;
#define FAST_ALLOCATOR_MEMORY 9e7
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
    map<int, int> l;
    for (int i = 0; i < n; ++i) {
        posByInd[a[i].second] = i + 1;
        if (l.count(a[i].first) == 0) {
            l[a[i].first] = i + 1;
        }
    }
    Node *dp[M + 1];
    for (int i = 0; i < M + 1; i++) {
        dp[i] = build(0, n + 3);
    }
    for (int i = 0; i < n; i++) {
        for (int m = 0; m <= M; m++) {
            int val = posByInd[i];
            int realVal = aCopy[i].first;
            st(dp[m], val, query(dp[m], 0, l[realVal] - 1) + 1);
            if (m != 0) {
                int mx = query(dp[m - 1], l[realVal], val - 1);
                mx = max(mx, query(dp[m - 1], val + 1, n + 3));
                st(dp[m], val, mx + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < M + 1; i++) {
        ans = max(ans, dp[i]->max);
    }
    cout << ans;
}