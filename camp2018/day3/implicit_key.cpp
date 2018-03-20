#include <iostream>
#include <time.h>
#include <random>
#include <cassert>
using namespace std;
 
struct TNode {
    int y, val, size, zeroes = 0;
    TNode *left;
    TNode *right;
 
    TNode(int val) : size(1), val(val), y(rand()), left(NULL), right(NULL), zeroes(1) {}
};
 
#define Treap TNode*
 
int safe(Treap a) {
    return a ? a->size : 0;
}
 int safez(Treap a){
    return a ? a->zeroes : 0;
 }
void recalc(Treap a) {
    a->size = safe(a->left) + 1 + safe(a->right);
    a->zeroes = safez(a->left) + (a->val == 0) + safez(a->right);
}
 
Treap merge(Treap a, Treap b) {
    if (!a) return b;
    if (!b) return a;
    if (a->y > b->y) {
        a->right = merge(a->right, b);
        recalc(a);
        return a;
    }
    b->left = merge(a, b->left);
    recalc(b);
    return b;
}
 
// (-inf, x)[x, inf)
pair<Treap, Treap> split(Treap a, int x) {
    if (!a) return make_pair(a, a);
    if (safe(a->left) < x) {
        pair<Treap, Treap> tmp = split(a->right, x - safe(a->left) - 1);
        a->right = tmp.first;
        recalc(a);
        tmp.first = a;
        return tmp;
    }
    pair<Treap, Treap> tmp = split(a->left, x);
    a->left = tmp.second;
    recalc(a);
    tmp.second = a;
    return tmp;
}
vector<int> ans;
void print(Treap a) {
    if (!a) return;
    print(a->left);
    // cout << a->val << ' ';
    ans.push_back(a->val);
    print(a->right);
}
 
void insert(Treap&a, int pos, int x) {
    pair<Treap, Treap> t = split(a, pos);
    a = new TNode(x);
    a = merge(t.first, a);
    a = merge(a, t.second);
}
bool kth(Treap a, int x, int y){
    // cout << safe(a->left) << ' ' << x << '\n';
    if (safe(a->left) + 1 == x){
        // cout << a->val << ' ' << y << '\n';
        if (a->val == 0){
            a->val = y;
            recalc(a);
            return 1;
        }
        return 0;
    }
    if (safe(a->left) >= x){
        return kth(a->left, x, y);
    }
    return kth(a->right, x - safe(a->left) - 1, y);
}
int main() {
    freopen("key.in", "r", stdin);
    freopen("key.out", "w", stdout);
    srand(time(NULL));
    int n, m;
    cin >> n >> m;
    Treap root = new TNode(0);
    for (int i = 1; i < m; i++) {
        insert(root, i + 1, 0);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bool gg = kth(root, a, i + 1);
        if (gg) continue;
        insert(root, a - 1, i + 1);
    }
    int ans1 = 0;
    print(root);
    for (int i = ans.size() - 1;i >= 0;i--){
        // cout << "! " << ans[i] << '\n';
        if (ans[i] != 0) break;
        ans1++;
    }
    assert(ans.size() - ans1 > 0);
    cout << ans.size() - ans1 << '\n';
    for (int i = 0;i < ans.size() - ans1;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}