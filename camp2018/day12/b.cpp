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
struct Solver{
    vector<unordered_set<int>> ne_razn;
    int n, m;
    vector<int> ans;
    vector<vector<int>> scenes;
    Solver(){
        cin >> n >> m;
        ans.resize(n);
        scenes.resize(n);
        forn(i, m){
            int cnt;
            cin >> cnt;
            forn(j, cnt){
                int tmp;
                cin >> tmp;
                scenes[tmp - 1].pb(i + 1);
            }
        }
        forn(i, n){
            int mx = 0;
            forn(j, n){
                if (i == j) continue;
                if (!scenes[i].size()) {
                    mx = max(mx, scenes[j].size() ? scenes[j][0] : MAX);
                    continue;
                }
                if (!scenes[j].size()){
                    mx = max(mx, scenes[i].size() ? scenes[i][0] : MAX);
                    continue;
                }
                int sht = 0;
                while (sht < scenes[i].size() && sht < scenes[j].size() && scenes[i][sht] == scenes[j][sht]){
                    sht++;
                }
                // cout << i << ' ' << j << ' ' <<sht << '\n';
                if (sht == scenes[i].size()){
                    if (sht == scenes[j].size()){
                        mx = max(mx, 1LL * MAX);
                    }
                    else{
                        // cout << scenes[j][sht] << " "<< sht << "!!!\n";
                        mx = max(mx, scenes[j][sht]);
                    }
                }
                else if (sht == scenes[j].size()){
                    mx = max(mx, scenes[i][sht]);
                }
                else{
                    mx = max(mx, min(scenes[i][sht], scenes[j][sht]));
                }
            }
            ans[i] = mx;
        }
        for (int i : ans) cout << (i == MAX ? 0 : i) << ' ';
        cout << '\n'; 
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
    string FN = "theatre";
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