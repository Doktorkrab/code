#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
// #define ALLOC
 
#define MAX INT_MAX
#define MIN INT_MIN
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0;i < n;i++)
#define ft first
#define st second
#define pb push_back
 
#ifdef ALLOC
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { }
#endif
 
// TEMPLATE END
 
// CODE HERE
mt19937 gen(time(0));
uniform_int_distribution<ll> uid(0, MAX);
struct Treap;
using treap = Treap*;
struct Treap{
    int x, y, sz = 1;
    Treap* left = nullptr;
    Treap* right = nullptr;
    Treap(int x) : x(x), y(uid(gen)) {}
    void recalc(){
        sz = 1;
        if (left) sz += left->sz;
        if (right) sz += right->sz;
    }
    ~Treap(){
        delete left;
        delete right;
    }
 
};
bool find(treap a,int k){
    if (!a) return 0;
    if (a->x == k) return 1;
    if (a->x > k) return find(a->left, k);
    return find(a->right, k);
}
treap merge(treap a, treap b){
    if (!a) return b;
    if (!b) return a;
    if (a->y < b->y){
        a->right = merge(a->right, b);
        return a;
    }
    b->left = merge(a, b->left);
    return b;
}
 
pair<treap, treap> split(treap a, int k){ // (-inf; x) [x;+inf]
    if (!a) return {nullptr, nullptr};
    if (a->x >= k){
        auto tmp = split(a->left, k);
        a->left = tmp.second;
        tmp.second = a;
        return tmp;
    }
    auto tmp = split(a->right, k);
    a->right = tmp.first;
    tmp.first = a;
    return tmp;
}
treap insert_fast(treap a, treap x){
    if (!a) return x;
    if (a->y >= x->y){
        auto tmp = split(a, x->x);
        x->left = tmp.first;
        x->right = tmp.second;
        return x;
    }
    if (a->x > x->x){
        a->left = insert_fast(a->left, x);
        return a;
    }
    a->right = insert_fast(a->right, x);
    return a;
}
int prev(treap& a, int x){
    if (!a) return MIN;
    auto tmp = split(a, x);
    if (!tmp.ft) return MIN;
    while(tmp.ft->right) tmp.ft = tmp.ft->right;
    a = merge(tmp.ft, tmp.st);
    return tmp.ft->x;
}
 
int next(treap& a, int x){
    if (!a) return MIN;
    auto tmp = split(a, x + 1);
    // node tmp1 = tmp.st;
    if (!tmp.st) return MIN;
    while(tmp.st->left) tmp.st = tmp.st->left;
    a = merge(tmp.ft, tmp.st);;
    return tmp.st->x;
}
 
treap del_fast(treap a, int x){
    if (!a) return nullptr;
    if (a->x == x){
        // cout << a->x << ' ' << x << '\n'; 
        return merge(a->left, a->right);
    }
    if (a->x > x){
        a->left = del_fast(a->left, x);
        return a;
    }
    a->right = del_fast(a->right, x);
    return a;
}
struct Solver{
    string s;
    int x;
    treap a = nullptr;
    Solver(){
        while(cin >> s){
            cin >> x;
            if (s == "insert"){
                if (find(a, x)) continue;
                a = insert_fast(a, new Treap(x));
            }
            if (s == "delete"){
                if (!find(a, x)) continue;
                a = del_fast(a, x);
            }
            if (s == "exists"){
                cout << (find(a, x) ? "true\n" : "false\n");
            }
            if (s == "next"){
                int ret = next(a, x);
                cout << (ret == MIN ? "none" : to_string(ret)) << '\n';
            }
            if (s == "prev"){
                int ret = prev(a, x);
                cout << (ret == MIN ? "none" : to_string(ret)) << '\n';
            }
        }
    }   
};
 
// CODE END
 
int main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
#endif
    while(t--){
#ifdef LOCAL
        clock_t t_elapsed = clock();
#endif
        Solver a;
#ifdef LOCAL
        cout << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }
 
}