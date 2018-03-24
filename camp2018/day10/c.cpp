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
    int x = 0, l, r;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int L, int R) : l(L), r(R) {}
};
using nd = Node*;
vector<int> arr;
int safe(nd a){
    return a ? a->x : 0;
}
nd recalc(nd a){
    a->x = safe(a->left) + safe(a->right);
    return a;
}
nd build(int L, int R){
    nd now = new Node(L, R);
    if (R - L == 1){
        now->x = arr[L];
        return now;
    }
    int M = (L + R) / 2;
    now->left = build(L, M);
    now->right = build(M, R);
    return recalc(now);
}
nd build_new(nd now, int pos, int x){
    // cout << now->l << ' ' << now->r << ' ' << pos << ' ' << x << '\n';
    assert(!(now->l > pos || now->r<= pos));
    nd new_now = new Node(now->l, now->r);
    if (now->r - now->l == 1){
        // cout << now->l << ' ' << now->r << ' ' << pos << ' ' << x << '\n';
        new_now->x = x;
        return new_now;
    }
    if (pos >= (now->l + now->r) / 2){
        new_now->left = now->left;
        new_now->right = build_new(now->right, pos, x);
    }
    else{
        new_now->right = now->right;
        new_now->left = build_new(now->left, pos, x);
    }
    return new_now;
}

int get(nd a, int pos){
    if (a->l > pos || a->r<= pos) return LONG_LONG_MIN;
    if (a->r - a->l == 1) {
        // cout << pos << ' ' << a->l << ' ' << a->r << ' ' << a->x << '\n';
        return a->x;
    }
    return max(get(a->left, pos), get(a->right, pos));
}

struct Solver{
    int n, m;
    vector<nd> versions;
    Solver(){
        cin >> n;
        arr.resize(n);
        forn(i, n) cin >> arr[i];
        versions.pb(nullptr);
        versions.pb(build(0, n));
        cin >> m;
        forn(i, m){
            string s;
            cin >> s;
            if (s[0] == 'c'){
                int from, pos, x;
                cin >> from >> pos >> x;
                versions.pb(build_new(versions[from], pos - 1, x));
            }
            else{
                int version, pos;
                cin >> version >> pos;
                cout << get(versions[version], pos - 1) << '\n';
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
    cout.tie(0);
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