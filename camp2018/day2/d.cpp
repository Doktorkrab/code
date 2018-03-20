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
    ll L, R, max, min, extra;
    TNode* left = nullptr;
    TNode* right = nullptr;
    TNode(int L, int R) : L(L), R(R), max(INT_MIN), extra(0) {}
};
using node = TNode*;
ll safe_max(node a){
    return a ? a->max : INT_MIN;
}
void recalc(node a){
    a->max = max(safe_max(a->left), safe_max(a->right));
}
void update_extra(node a, ll x){
    a->max += x;
    a->extra += x;
}
void push(node a){
    if (a->left){
        update_extra(a->left, a->extra);
    }
    if (a->right){
        update_extra(a->right, a->extra);
    }
    a->extra = 0;
}
vi arr;
node build(ll L, ll R){
    node cur = new TNode(L, R);
    if (R - L == 1){
        cur->max = arr[L];
        // cout << cur->max << '\n';
        return cur;
    }
    ll M = (L + R) / 2;
    cur->left = build(L, M);
    cur->right = build(M, R);
    recalc(cur);
    return cur;
}
ll sum(node a, int L, int R){
    if (!a) return INT_MIN;
    if (a->R <= L || R <= a->L) return INT_MIN;
    if (L <= a->L && a->R <= R) return a->max;
    push(a);
    auto ret = sum(a->left, L, R);
    auto ret1 = sum(a->right, L, R);
    recalc(a);
    return max(ret, ret1);
}


void insert(node a, int L, int R, ll x){
    if (!a) assert(0);
    if (!a) return;
    if (a->R <= L || R <= a->L) return;
    if (L <= a->L && a->R <= R){
        update_extra(a, x);
        return;
    }
    push(a);
    insert(a->left, L, R, x);
    insert(a->right, L, R, x);
    recalc(a);
}

struct Solver{
    int n, q;
    node a = nullptr;
    Solver(){
        cin >> n >> q;
        arr.resize(n);
        forn(i, n) cin >> arr[i];
        a = build(0, n);
        // cerr << "builded\n";
        forn(i, q){
            string s;
            int l, r;
            cin >> s >> l >> r;
            if (s == "max"){
                cout << sum(a, l - 1, r) << '\n';
            }
            if (s == "add"){
                int x;
                cin >> x;
                insert(a, l - 1, r, x);
            }
            
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
    // freopen("rvq.in", "r", stdin);
    // freopen("rvq.out", "w", stdout);
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