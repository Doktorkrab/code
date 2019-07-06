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

namespace SegmentTree{
    struct Node{
        Node *left = nullptr;
        Node *right = nullptr;
        int count = 0;
        int qnique = 0;
        int different = 0;
        Node() {}
    };
    using nd = Node*;
    nd recalc(nd a){
        a->count = a->qnique = a->different = 0;
        if (a->left){
            a->count += a->left->count;
            a->qnique += a->left->qnique;
            a->different += a->left->different;
        }
        if (a->right){
            a->count += a->right->count;
            a->qnique += a->right->qnique;
            a->different += a->right->different;
        }
        return a;
    }
    nd build(int l, int r){
        nd nxt = new Node();
        if (r - l == 1)
            return nxt;
        int m = (l + r) / 2;
        nxt->left = build(l, m);
        nxt->right = build(m, r);
        return recalc(nxt);
    }
    
    nd set(nd root, int l, int r, int pos, int x){
        if (pos < l || r <= pos)
            return root;
        nd nxt = new Node();
        if (r - l == 1){
            nxt->count = root->count;
            nxt->qnique = root->qnique;
            nxt->different = root->different;
            if (nxt->count == 0 && x < 0)
                return nxt;
            nxt->count += x;
            nxt->qnique = 0;
            if (nxt->count == 0){
                nxt->qnique = 0;
                nxt->different = 0;
            }
            else
                nxt->different = 1;
            if (nxt->count == 1)
                nxt->qnique = 1;
            return nxt;
        }
        int m = (l + r) / 2;
        nxt->left = set(root->left, l, m, pos, x);
        nxt->right = set(root->right, m, r, pos, x);
        return recalc(nxt);
    }

    int get(nd root, int l, int r, int pos){
        if (pos < l || r <= pos)
            return -1;
        if (r - l == 1)
            return root->count;
        int m = (l + r) / 2;
        return max(get(root->left, l, m, pos), get(root->right, m, r, pos));
    }
}


int n, m;
vector<SegmentTree::nd> versions;
inline void init(){
    versions.clear();
    versions.push_back(SegmentTree::build(0, m + 1));
}

inline void solve(){
    init();
    int64_t sum = 0;
    for (int i = 0; i < n; i++){
        string query;
        int x, v;
        cin >> query;
        if (query == "add"){
            cin >> x;
            versions.push_back(SegmentTree::set(versions.back(), 0, m + 1, x, 1));
        }
        if (query == "remove"){
            cin >> x;
            versions.push_back(SegmentTree::set(versions.back(), 0, m + 1, x, -1));
        }
        if (query == "different"){
            cin >> v;
            v = (v + sum) % (i + 1);
            int tmp = versions[v]->different;
            sum += tmp;
            cout << tmp << '\n';
            versions.push_back(versions.back());
        }
        if (query == "unique"){
            cin >> v;
            v = (v + sum) % (i + 1);
            int tmp = versions[v]->qnique;
            cout << tmp << '\n';
            sum += tmp;
            versions.push_back(versions.back());
        }
        if (query == "count"){
            cin >> x >> v;
            v = (v + sum) % (i + 1);
            int tmp = SegmentTree::get(versions[v], 0, m + 1, x);
            cout << tmp << '\n';
            sum += tmp;
            versions.push_back(versions.back());
        }
    }

}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
