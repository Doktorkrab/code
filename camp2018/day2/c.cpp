#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define ALLOC

#define MX MAX_INT
#define MIX MIN_INT
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
struct TNode{
    ll L, R, sum, extra;
    TNode* left = nullptr;
    TNode* right = nullptr;
    TNode(int L, int R) : L(L), R(R), sum(0), extra(INT_MIN) {}
};
using node = TNode*;
ll safe_sum(node a){
    return a ? a->sum : 0;
}

void recalc(node a){
    a->sum = safe_sum(a->left) + safe_sum(a->right); 
}

node build(int L, int R){
    node cur = new TNode(L, R);
    if (R - L == 1){
        return cur;
    }
    int M = (L + R) / 2;
    cur->left = build(L, M);
    cur->right = build(M, R);
    return cur;
}
void push(node a){
    // a->sum = a->extra * (a->R - a->L);
    if(a->extra == INT_MIN) return;
    if (a->left) {
        a->left->extra = a->extra;
        a->left->sum = a->extra * (a->left->R - a->left->L);
    }
    if (a->right) {
        a->right->extra = a->extra;
        a->right->sum = a->extra * (a->right->R - a->right->L);
    }
    a->extra = INT_MIN;
}
ll sum(node a, int L, int R){
    if (!a) return 0;
    if (a->R <= L || R <= a->L) return 0;
    if (L <= a->L && a->R <= R){return a->sum;}
    push(a);
    ll kek = sum(a->left, L, R) + sum(a->right, L, R);
    recalc(a);
    return kek;
}

void insert(node a, int L, int R, ll x){
    if (!a) return;
    // cout << a->L << ' ' << a->R << ' ' << L << ' ' << R << '\n';
    if (a->R <= L || R <= a->L) return;
    if (L <= a->L && a->R <= R){
        a->extra = x;
        a->sum = x * (a->R - a->L);
        // cout << a->L << ' ' << a->R << ' ' << L << ' ' << R << '\n';
        // push(a);
        return;
    }
    // push(a);
    insert(a->left, L, R, x);
    insert(a->right, L, R, x);
    recalc(a);
}
struct Solver{
    int n, q;
    node a = nullptr;
    Solver(){
        cin >> n;
        a = build(0, n);
        // cerr << "builded\n";
        cin >> q;
        forn(i, q){
            char c;
            cin >> c;
            int l, r;
            cin >> l >> r;
            if (c == 'A'){
                int x;
                cin >> x;
                insert(a, l - 1, r, x);
            }
            else
                cout << sum(a, l - 1, r) << '\n';
            // cout << c << " ready\n";
            // print(a);
            // cout << '\n';
            // cout << "sum" << a->sum << '\n';
        }
    }   
};

// CODE END

int main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
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
