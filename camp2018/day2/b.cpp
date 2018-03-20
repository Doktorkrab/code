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
    TNode(int L, int R) : L(L), R(R), max(INT_MIN), min(INT_MAX), extra(0) {}
};
using node = TNode*;
ll safe_min(node a){
    return a ? a->min : INT_MAX;
}
ll safe_max(node a){
    return a ? a->max : INT_MIN;
}
void recalc(node a){
    a->min = min(safe_min(a->left), safe_min(a->right));
    a->max = max(safe_max(a->left), safe_max(a->right));
}
node build(ll L, ll R){
    node cur = new TNode(L, R);
    if (R - L == 1){
        cur->min = R * R % 12345 + R * R * R % 23456;
        cur->max = R * R % 12345 + R * R * R % 23456;
        return cur;
    }
    ll M = (L + R) / 2;
    cur->left = build(L, M);
    cur->right = build(M, R);
    recalc(cur);
    return cur;
}
pair<ll, ll> sum(node a, int L, int R){
    if (!a) return {INT_MAX, INT_MIN};
    // cout << a->L << ' ' << a->R << ' ' << L << ' ' << R << ' ' << a->sum << '\n';
    if (a->R <= L || R <= a->L) return {INT_MAX, INT_MIN};
    if (L <= a->L && a->R <= R) return {a->min, a->max};
    auto ret = sum(a->left, L, R);
    auto ret1 = sum(a->right, L, R);
    return {min(ret.ft, ret1.ft), max(ret1.st, ret.st)};
}


void insert(node a, int pos, ll x){
    if (!a) assert(0);
    if (a->R <= pos || a->L > pos) return;
    if (a->R - a->L == 1){
        a->min = x;
        a->max = x;
        return;
    }
    insert(a->left, pos, x);
    insert(a->right, pos, x);
    recalc(a);
}

struct Solver{
    int n = 100005, q;
    node a = nullptr;
    Solver(){
        cin >> q;
        a = build(0, n);
        // cerr << "builded\n";
        forn(i, q){
            int x, y;
            cin >> x >> y;
            if(x > 0){
                auto ret = sum(a, x - 1, y);
                cout << ret.st - ret.ft << '\n';
            }
            else{
                insert(a, -x - 1, y);
            }
            // cout << i << " ready\n";
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
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
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
