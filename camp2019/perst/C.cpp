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
        int val;
        Node* left = nullptr;
        Node* right = nullptr;
        Node (int val) : val(val) {}
    };
    using nd = Node*;
    

    nd recalc(nd a){
        return a;
    }

    nd build(int l, int r, int *a){
        nd nxt = new Node(0);
        if (r - l == 1){
            nxt->val = a[l];
            return nxt;
        }
        int m = (l + r) / 2;
        nxt->left = build(l, m, a);
        nxt->right = build(m, r, a);
        return recalc(nxt);
    }
    
    nd set(nd root, int l, int r, int pos, int x){
        if (pos < l || r <= pos)
            return root;
        if (r - l == 1){
            return new Node(x);
        }
        nd nxt = new Node(0);
        int m = (l + r) / 2;
        nxt->left = set(root->left, l, m, pos, x);
        nxt->right = set(root->right, m, r, pos, x);
        return recalc(nxt);
    }

    int get(nd root, int l, int r, int pos){
        if (pos < l || r <= pos)
            return -1;
        if (r - l == 1)
            return root->val;
        int m = (l + r) / 2;
        return max(get(root->left, l, m, pos), get(root->right, m, r, pos));
    }
}
int n;
const int MAXN = 1e5 + 7;
int arr[MAXN];
vector<SegmentTree::nd> versions;
inline void init(){
    versions.clear();
    versions.push_back(nullptr);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    versions.push_back(SegmentTree::build(0, n, arr));
    int m;
    cin >> m;
    while (m--){
        string query;
        int version, id, x;
        cin >> query >> version >> id;
        if (query == "get")
            cout << SegmentTree::get(versions[version], 0, n, id - 1) << '\n';
        else{
            cin >> x;
            versions.push_back(SegmentTree::set(versions[version], 0, n, id - 1, x));
        }
    }
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
