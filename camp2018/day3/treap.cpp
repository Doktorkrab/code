#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
struct node{
    ll x, y, sz = 1, mn = INT_MAX;
    node* left = nullptr;
    node* right = nullptr;
    node(ll x) : x(x), y((rand() << 16) | rand()), mn(x) {}
};
using nd = node*;
int sz(nd a){
    return a ? a->sz : 0;
}
ll mn(nd a){
    return a ? a->mn : INT_MAX;
}
nd rc(nd a){
    a->sz = sz(a->left) + 1 + sz(a->right);
    a->mn = min(mn(a->left), min(a->x, mn(a->right)));
    return a;
}
nd merge(nd a, nd b){
    if (!a) return b;
    if (!b) return a;
    if (a->y > b->y){
        a->right = merge(a->right, b);
        return rc(a);
    }
    b->left = merge(a, b->left);
    return rc(b);
}
pair<nd, nd> split(nd a, int x) {
    if (!a) return make_pair(a, a);
    if (sz(a->left) + 1 <= x) {
        auto tmp = split(a->right, x - sz(a->left) - 1);
        a->right = tmp.first;
        return {rc(a), tmp.second};
    }
    auto tmp = split(a->left, x);
    a->left = tmp.second;
    return {tmp.first, rc(a)};
}
void insert(nd&a, int pos, int x) {
    if (!a){
        a = new node(x);
        return;
    }
    auto t = split(a, pos);
    a = new node(x);
    a = merge(t.first, a);
    a = merge(a, t.second);
}
void print(nd a){
    if (!a) return;
    print(a->left);
    cerr << a->x << ' ';
    print(a->right);
}
signed main(){
    srand(time(0));
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    int n;
    cin >> n;
    nd a = nullptr;
    for (int i = 0;i < n;i++){
        char c;
        cin >> c;
        if (c == '+'){
            ll i, j;
            cin >> i >> j;
            insert(a, i, j);
        }
        else{
            int l, r;
            cin >> l >> r;
            // print(a);
            // cerr << '\n';
            if (l > r) swap(l, r);
            auto tmp = split(a, r);
            // print(tmp.first);
            // cerr << '\n';
            // print(tmp.second);
            // cerr << '\n';
            auto tmp1 = split(tmp.first, l - 1);
            // print(tmp1.first);
            // cerr << '\n';
            // print(tmp1.second);
            // cerr << '\n';
            assert(tmp1.second);
            assert(tmp1.second->mn != INT_MAX);
            cout << tmp1.second->mn << '\n';
            a = merge(merge(tmp1.first, tmp1.second), tmp.second);
        }

    }
}