#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
// TEMPLATE HERE
 
#define int long long
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
struct Node{
    int l, r, cnt_q = 0, cnt = 0, cnt_kost = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int l, int r) : l(l), r(r) {}
};
using nd = Node*;
int safe_cnt(nd a){
    return a ? a->cnt_kost : 0;
}
int safe_cnt_q(nd a){
    return a ? a->cnt_q : 0;
}
nd recalc(nd a){
    a->cnt_kost = safe_cnt(a->left) + safe_cnt(a->right);
    a->cnt_q = safe_cnt_q(a->left) + safe_cnt_q(a->right);
    return a;
}
nd add1(nd a, int pos, int l, int r){
    nd now = new Node(l, r);
    // cout << l << ' ' << r << ' ' << (l + r) / 2 << ' ' << pos << '\n'; 
    if (r - l == 1){
        now->cnt = (a ? a->cnt : 0) + 1;
        now->cnt_kost = 1;
        now->cnt_q = (now->cnt == 1);
        return now;
    }
    int m = (l + r) / 2;
    if (pos >= m){
        now->left = a ? a->left : nullptr;
        // cerr << "here";
        now->right = add1(a ? a->right : nullptr , pos, m, r);
    }
    else{
        now->right = a ? a->right : nullptr;
        now->left = add1(a ? a->left : nullptr, pos, l, m);
    }
    return recalc(now);
}
nd remove(nd a, int pos){
    if (!a) return nullptr;
    nd now = new Node(a->l, a->r);
    if (a->l > pos || a->r <= pos) return a;
    if (a->r - a->l == 1){
        // cout << a->cnt << '\n';
        if (a->cnt > 0){
            now->cnt = a->cnt - 1;
            now->cnt_kost = (now->cnt > 0);
            now->cnt_q = (now->cnt == 1);
        }
        return now;
    }
    now->left = remove(a->left, pos);
    now->right = remove(a->right, pos);
    return recalc(now);
}

int get(nd a, int pos){
    if (!a) return 0;
    if (a->l > pos || a->r<= pos) return 0;
    if (a->r - a->l == 1) {
        return a->cnt;
    }
    return max(get(a->left, pos), get(a->right, pos));
}
int get1(nd a, int pos){
    if (a->l > pos || a->r<= pos) return LONG_LONG_MIN;
    if (a->r - a->l == 1) {
        return a->cnt_q;
    }
    return max(get1(a->left, pos), get1(a->right, pos));
}
struct Solver{
    int n, m;
    vector<nd> versions;
    Solver(){
        cin >> n >> m;
        versions.pb(nullptr);
        int sm = 0;
        forn(i, n){
            string s;
            cin >> s;
            if (s == "add"){
                int a;
                cin >> a;
                versions.pb(add1(versions.back(), a, 0, m + 1));
            }
            if (s == "remove"){
                int a;
                cin >> a;
                versions.pb(remove(versions.back(), a));
            }
            if (s == "different"){
                int a;
                cin >> a;
                a = (a + sm) % (i + 1);
                cout << safe_cnt(versions[a]) << '\n';
                sm += safe_cnt(versions[a]);
                versions.pb(versions.back());
            }
            if (s == "unique"){
                int a;
                cin >> a;
                a = (a + sm) % (i + 1);
                // cout << a << '\n';
                // cout << "a" << ' ' << a << ' ' << i << '\n';
                cout << safe_cnt_q(versions[a]) << '\n';
                sm += safe_cnt_q(versions[a]);
                versions.pb(versions.back());

            }
            if (s == "count"){
                int a, b;
                cin >> a >> b;
                b = (b + sm) % (i + 1);
                int tmp = get(versions[b], a);
                cout << tmp << '\n';
                sm += tmp;
                versions.pb(versions.back());

            }
            // cout << "successfull " << i + 1 << versions.size() << '\n';
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
    cout.tie(0);
    cin.tie(0);
    // string FN = "cut";
    // freopen((FN + ".in").c_str(), "r", stdin);
    // freopen((FN + ".out").c_str(), "w", stdout);
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