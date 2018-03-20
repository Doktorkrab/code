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
vi v;
struct Node{
    ll L, R, x = 0, kost = 1, extra = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int L, int R) : L(L), R(R) {}
};
using node = Node*;
ll safe(node a) {return a ? a->x : 0;}
ll safe_k(node a) {return a ? a->kost : 0;}
void recaclc(node a){
    a->kost = safe_k(a->left) + safe_k(a->right);
    a->x = safe(a->left) + safe(a->right);
}
node bld(int L, int R){
    node gg = new Node(L, R);
    if (R - L == 1){
        gg->x = v[R];
        return gg;
    }
    int m = (L + R) / 2;
    gg->left = bld(L, m);
    gg->right = bld(m, R);
    return gg;
}
void push(node a){
    if (a->extra > a->x){}
}
void insert(node& a, int pos, int x){
    if (!a){
        return;
    }
    if (a->R >= pos || a->L < pos) return;
    if (a->R - a->L == 1){
        a->x = x;
        return;
    }
    insert(a->left, pos, x);
    insert(a->right, pos, x);
    recaclc(a);
}
pll func(node& a, int L, int R){
    if (!a) return {0, 0};
    if (a->L >= R || a->R <= L) return {0, 0};
    push(a);
    if (a->L >= L && a->R <= R) return {a->x, a->kost};
    // ll m = (a->L + a->R) / 2;
    pll ans = func(a->left, L, R), ans1 = func(a->right, L, R);
    recalc(a);
    return {ans.ft + ans1.ft, ans.st + ans1.st};
}
struct Solver{
    int n;
    vi t;
    Solver(){
        cin >> n;
        forn(i, n) cin >> v;
        forn(i, n) cin >> t;
        set<int> kek;
        forn(i, n){
            kek.insert(v[i]);

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