#include <bits/stdc++.h>
#define int long long
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
    ll sum = 0;
};
const int MAXN = 1e5;
vector<Node> st;

int NEUTRAL = 0;

ll get(int x, int l, int r, int L, int R){ // x - index, l, r - now, L, R - need
    if (l >= R || r <= L) return NEUTRAL;
    if (L <= l && r <= R) return st[x].sum;
    int m = (l + r) / 2;
    auto lft = get(2 * x, l, m, L, R);
    auto rgt = get(2 * x + 1, m, r, L, R);
    st[x].sum = st[2 * x].sum + st[2 * x + 1].sum;
    return lft + rgt;
}

void insert(int x, int l, int r, int where, ll what){
    if (where < l || where >= r) return;
    if (where == l && where == r - 1){
        st[x].sum += what;
        return;
    }
    int m = (l + r) / 2;
    insert(2 * x, l, m, where, what);
    insert(2 * x + 1, m, r, where, what);
    st[x].sum = st[2 * x].sum + st[2 * x + 1].sum;
}

struct Solver{
    int n, l, ans = 0;
    vi arr, arr1;
    Solver(){        
        cin >> n >> l;
        arr.resize(n);
        arr1.resize(n);
        forn(i, n){
            cin >> arr[i];
            arr[i] *= l;
            arr[i] += i;
            arr1[i] = arr[i];
        }
        sort(all(arr1));
        unordered_map<int, int> id;
        for (int i = 0;i < n;i++){
            id[arr1[i]] = i;
        }
        int power = 1;
        while ((1 << power) < n) power++;
        int N = 1 << power;
        st.assign(2 * N, {0});
        for (int i = 0; i < n;i++){
            // print(cout, get(1, 0, N, id[arr[i]] + 1, N), arr[i], id[arr[i]]);
            ans += get(1, 0, N, id[arr[i]] + 1, N);
            insert(1, 0, N, id[arr[i]], 1);
        }
        cout << ans << '\n';
    }   
};

// CODE END

signed main(){
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
