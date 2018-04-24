#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE
 
#define int long long
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define ALLOC
   
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
vector<int> ans;
struct TNode{
    ll l, r, mn = INT_MAX, ps = 0;
    TNode* left = nullptr;
    TNode* right = nullptr;
    TNode(int l, int r) : l(l), r(r) {}
};
using nd = TNode*;
ll sf(nd a){
    return a ? a->mn : LONG_LONG_MAX;
}
nd recalc(nd a){
    a->mn = LONG_LONG_MAX;
    if (a->left){
        a->mn = a->left->mn;
        a->ps = a->left->ps;
    }
    if (a->right && a->mn > a->right->mn){
        a->mn = a->right->mn;
        a->ps = a->right->ps;
    }
    return a;
}
nd bld(int l ,int r){
    nd cr = new TNode(l, r);
    if (r - l == 1){
        cr->mn = ans[l];
        cr->ps = l;
        return cr;
    }
    int m = (l + r) / 2;
    cr->left = bld(l, m);
    cr->right = bld(m, r);
    return recalc(cr);
}
pii get(nd a, int l, int r){
    // cout << a->l << ' ' << a->r << ' ' << l << ' ' << r << '\n';
    if (l >= a->r || r <= a->l) return {LONG_LONG_MAX, INT_MAX};
    if (l <= a->l && r >= a->r) return {a->mn, a->ps};
    return min(get(a->left, l, r), get(a->right, l, r));
}
struct Solver{
    int n, k;
    vector<pii> mos;
    vector<int> nxt_w, nxt_l;
    bool check(int i, int j){
        return mos[i].ft != mos[j].ft && mos[i].st != mos[j].st; 
    }
    Solver(){
        cin >> n;
        nxt_w.resize(n);
        nxt_l.resize(n);
        mos.resize(n);
        forn(i, n) cin >> mos[i].ft >> mos[i].st;
        nxt_w.back() = INT_MAX;
        nxt_l.back() = INT_MAX;
        for (int i = n - 2;i >= 0;i--){
            nxt_w[i] = (mos[i].ft == mos[i + 1].ft ? nxt_w[i + 1] : i + 1);
            nxt_l[i] = (mos[i].st == mos[i + 1].st ? nxt_l[i + 1] : i + 1);
        }
        cin >> k;
        forn(i, k){
            int l, r;
            cin >> l >> r;
            --l, --r;
            if (nxt_w[l] > r || nxt_l[l] > r){
                cout << "0 0\n";
                continue;
            }
            if (check(l, nxt_w[l])){
                cout << l + 1 << ' ' << nxt_w[l] + 1 << '\n';
            }
            else if (check(l, nxt_l[l])){
                cout << l + 1 << ' ' << nxt_l[l] + 1 << '\n';
            }
            else{
                cout << nxt_w[l] + 1 << ' ' << nxt_l[l] + 1 << '\n';
            }
        }
    }   
};
   
// CODE END
   
signed main(){
    int t  = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    string FN = "mosaic";
    freopen((FN + ".in").c_str(), "r", stdin);
    freopen((FN + ".out").c_str(), "w", stdout);
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