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
    ll L, R, sum_odd, sum_even, extra;
    TNode* left = nullptr;
    TNode* right = nullptr;
    TNode(int L, int R) : L(L), R(R), sum_odd(0), sum_even(0), extra(0) {}
};
using node = TNode*;
vi arr;
ll safe_sum_even(node a){
    return a ? a->sum_even : 0;
}
ll safe_sum_odd(node a){
    return a ? a->sum_odd : 0;
}
void recalc(node a){
    a->sum_even = safe_sum_even(a->left) + safe_sum_even(a->right);
    a->sum_odd = safe_sum_odd(a->left) + safe_sum_odd(a->right);  
}
node build(int L, int R){
    node cur = new TNode(L, R);
    if (R - L == 1){
        if (L & 1) cur->sum_odd += arr[L];
        else cur->sum_even += arr[L];
        return cur;
    }
    int M = (L + R) / 2;
    cur->left = build(L, M);
    cur->right = build(M, R);
    recalc(cur);
    return cur;
}
pll sum(node a, int L, int R){
    if (!a) return {0, 0};
    // cout << a->L << ' ' << a->R << ' ' << L << ' ' << R << ' ' << a->sum << '\n';
    if (a->R <= L || R <= a->L) return {0, 0};
    if (L <= a->L && a->R <= R) return {a->sum_even, a->sum_odd};
    pll rt = sum(a->left, L, R), rt1 = sum(a->right, L, R);
    return {rt.ft + rt1.ft, rt.st + rt1.st};
}

void insert(node a, int pos, ll x){
    if (!a) assert(0);
    if (a->R <= pos || a->L > pos) return;
    if (a->R - a->L == 1){
        if (a->L & 1) a->sum_odd = x;
        else a->sum_even = x;
        return;
    }
    insert(a->left, pos, x);
    insert(a->right, pos, x);
    recalc(a);
}

struct Solver{
    int n, q;
    node a = nullptr;
    Solver(){
        cin >> n;
        arr.resize(n);
        forn(i, n) cin >> arr[i];
        a = build(0, n);
        // cerr << "builded\n";
        cin >> q;
        forn(i, q){
            int c;
            cin >> c;
            int l, r;
            cin >> l >> r;
            if (c == 0){
                insert(a, l - 1, r);
            }
            else{
                auto rt = sum(a, l - 1, r);
                if (l & 1){
                    cout << rt.ft - rt.st << '\n';
                }
                else cout << rt.st - rt.ft << '\n';
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
    freopen("signchange.in", "r", stdin);
    freopen("signchange.out", "w", stdout);
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
