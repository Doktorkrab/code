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
    int x = 0;
    Node* nxt = nullptr;
    Node(int x) : x(x){}
};
using nd = Node*;
struct Solver{
    int n;
    vector<nd> perst = {new Node(0)};
    Solver(){
        cin >> n;
        forn(i, n){
            int t, m;
            cin >> t >> m;
            nd now = new Node(m);
            if (m > 0){
                now->nxt = perst[t];
                now->x += perst[t]->x;
                perst.pb(now);
            }
            else{
                perst.pb(perst[t]->nxt);
            }
        }
        int ans = 0;
        for (auto node : perst){
            ans += node->x;
        }
        cout << ans << '\n';
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