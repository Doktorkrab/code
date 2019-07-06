#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

#define MAX INT_MAX
#define MIN INT_MIN
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0;i < n;i++)
#define ft first
#define st second
#define pb push_back

void print(ostream& os){
    os << "\n";
}

template <typename Arg1, typename... Args>
void print(ostream& os, const Arg1& arg1, const Args&... args){
    os << arg1 << " ";
    print(os, args...);
}

// TEMPLATE END

// CODE HERE
const ull BASE = 127;
const ull MOD = 150000001;
const ull MOD_SQR = MOD * MOD;

vector<ull> hashes, bases;

void build(const string& s){
    int n = s.size();
    hashes.resize(n + 1);
    bases.resize(n + 1);
    hashes[0] = 0, bases[0] = 1;
    for (int i = 0;i < n;i++){
        hashes[i + 1] = ((hashes[i] * BASE) % MOD + s[i]) % MOD;
        bases[i + 1] = (bases[i] * BASE) % MOD;
    }
}

ull get_hash(int l, int r){ // [l; r)
    return (hashes[r] + MOD_SQR - (hashes[l] * bases[r - l]) % MOD) % MOD;
}
struct Solver{
    string s;
    int n;
    Solver(){
        cin >> s;
        n = s.size();
        build(s);
        for (int i = 1; i <= n;i++){
            int j = 0;
            ull need = hashes[i];
            while (j < n && j + i <= n && need == get_hash(j, i + j)) j += i;
            if (j == n){
                cout << i << '\n';
                return;
            }
            if (j + i <= n) continue;
            if (hashes[n - j] == get_hash(j, n)){
                cout << i << '\n';
                return;
            }
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
