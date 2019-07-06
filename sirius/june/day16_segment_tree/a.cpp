#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

#define MX INT_MAX
#define MIN INT_MIN
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0;i < n;i++)
#define ft first
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


struct Node{
    int max = 0;
    int pos = 0;
};
const int MAXN = 1e5;
vector<Node> st(4ULL * MAXN);

int NEUTRAL = MIN;

pair<int, int> get(int x, int l, int r, int L, int R){ // x - index, l, r - now, L, R - need
    if (l >= R || r <= L) return {NEUTRAL, -1};
    if (L <= l && r <= R) return {st[x].max, st[x].pos};
    int m = (l + r) / 2;
    auto lft = get(2 * x, l, m, L, R);
    auto rgt = get(2 * x + 1, m, r, L, R);
    if (lft.first >= rgt.first) return lft;
    return rgt;

}
struct Solver{
    int n, k;
    Solver(){        
        cin >> n;
        int power = 1;
        while ((1 << power) < n) power++;
        int N = 1 << power;
        forn(i, n){
            int tmp;
            cin >> tmp;
            st[i + N] = {tmp, i};
        }
        for (int i = N - 1; i > 0;i--){
            if (st[2 * i].max >= st[2 * i + 1].max){
                st[i] = st[2 * i];
            }
            else st[i] = st[2 * i + 1];
        }
        cin >> k;
        forn(i, k){
            int l, r;
            cin >> l >> r;
            cout << get(1, N, 2 * N, l - 1 + N, r + N).second + 1 << ' ';
        }
        cout << '\n';
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
