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
    string s, t;
    vector<int> sum;
    int get_sum(int l, int r){
        return l ? sum[r] - sum[l - 1] : sum[r];
    }
    int n, m;
    Solver(){
        cin >> s >> t;
        n = s.size();
        m = t.size();
        sum.resize(n);
        sum[0] = s[0] - '0';
        for (int i = 1;i < n;i++){
            sum[i] = s[i] - '0' + sum[i - 1];
        }
        for (int i = 0;i < m;i++){
            for (int j = i + 1;j < n;j++){
                int sm = get_sum(i, j);
                int tmp_sm = sm;
                int l = 0;
                do{
                    l += 1;
                    tmp_sm /= 10;
                } while(tmp_sm > 0);
                if (sm == stoi(t.substr(i, l))){
                    // cout << sm << ' ' << stoi(t.substr(i, l)) << ' ' <<l << '\n';
                    bool f = 0;
                    int k = 0;
                    --l;
                    for (k = 1;j + k < n && i + l + k < m;k++){
                        if (s[j + k] == t[i + l + k]) continue;
                        f = 1;
                        break;
                    }
                    if (f) continue;
                    if (j + k < n || i + l + k < m) continue;
                    cout << i + 1 << ' ' << j + 1 << '\n';
                    return;
                }
            }
        }
        cout << "1 1\n";
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
    string FN = "password";
    freopen((FN + ".in").c_str(), "r", stdin);
    freopen((FN + ".out1").c_str(), "w", stdout);
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