#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)


using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui = unsigned int;
using namespace std;
using pii = pair<int, int>;


void print(ostream& st){
    st << '\n';
}


template <typename Arg, typename... Arg1>
void print(ostream& st, const Arg& a, const Arg1&... a1){
    st << a << ' ';
    print(st, a1...);
}


void input(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #endif
    #ifdef DEBUG
    freopen("kek.in", "r", stdin);
    freopen("kek.out", "w", stdout);
    #endif
}
//------------------------------------END_TEMPLATE---------------------------------------------------
mt19937 gen(time(0));
uniform_int_distribution<int> distr(0, INT_MAX - 1);

struct Node{
    ll y, val, size = 1;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(ll val) : y(distr(gen)), val(val) {}
    ~Node(){
        delete left;
        delete right;
    }
};


using node = Node*;


ll safe_sz(node a){
    return a ? a->size : 0;
}


ll safe_sqr(node a){
    return a ? a->sqr : 0;
}


node recalc(node a){
    a->size = 1 + safe_sz(a->left) + safe_sz(a->right);
    return a;
}
node merge(node a, node b){
    if (!b) return a;
    if (!a) return b;
    if (a->y > b->y){
        a->right = merge(a->right, b);
        return recalc(a);
    }
    b->left = merge(a, b->left);
    return recalc(b);
}




using ptt = pair<node, node>;
ptt split(node a, int k){
    if (!a) return {nullptr, nullptr};
    if (safe_sz(a->left) + 1 <= k){
        ptt tmp = split(a->right, k - safe_sz(a->left) - 1);
        a->right = tmp.first;
        return {recalc(a), tmp.second};
    }
    ptt tmp = split(a->left, k);
    a->left = tmp.second;
    return {tmp.first, recalc(a)};
}



void insert(node& a, int ind, int val){
    if (!a){
        a = new Node(val);
        return;
    }
    ptt tmp = split(a, ind);
    a = merge(merge(tmp.first, new Node(val)), tmp.second);
}
void print(node a){
    if (!a) return;
    print(a->left);
    cout << a->val << ' ';
    print(a->right);
}
int main(){
    input();
    int n, p;
    cin >> n >> p;
    // assert(p != 3);
    node a = nullptr;
}