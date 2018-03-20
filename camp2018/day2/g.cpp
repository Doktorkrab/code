#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
const int MOD = 1e9;
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
    TNode(int L, int R) : L(L), R(R), sum(0), extra(0) {}
};
using node = TNode*;

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
ll sum(node a, int L, int R){
    if (!a) return 0;
    // cout << a->L << ' ' << a->R << ' ' << L << ' ' << R << ' ' << a->sum << '\n';
    if (a->R <= L || R <= a->L) return 0;
    if (L <= a->L && a->R <= R) return a->sum;
    return sum(a->left, L, R) + sum(a->right, L, R);
}
ll safe_sum(node a){
    return a ? a->sum : 0;
}

void recalc(node a){
    a->sum = safe_sum(a->left) + safe_sum(a->right); 
}
void insert(node a, int pos, ll x){
    if (!a) assert(0);
    if (a->R <= pos || a->L > pos) return;
    if (a->R - a->L == 1){
        a->sum += x;
        return;
    }
    insert(a->left, pos, x);
    insert(a->right, pos, x);
    recalc(a);
}

struct Solver{
    int n, k;
    vector<node> nodes;
    // vi arr;
    Solver(){
        cin >> n >> k;
        nodes.resize(k + 1);
        // arr.resize(n);
        forn(i, k + 1) nodes[i] = build(0, n + 20);
        insert(nodes[0], n + 2, 1);
        forn(i, n){
            int now;
            cin >> now;
            forn(j, k){
                // cout << j << ' ' << now << ' ' << sum(nodes[j], now + 1, n + 5) << '\n';
                insert(nodes[j + 1], now, sum(nodes[j], now + 1, n + 5) % MOD);
            }
        }
        cout << sum(nodes[k], 0, n + 1) % MOD << '\n';

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
    freopen("kinverse.in", "r", stdin);
    freopen("kinverse.out", "w", stdout);
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
