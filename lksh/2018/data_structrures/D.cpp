#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXN = 100;
#else
const int INF = 1e9 + 239;
const int MAXN = 1e6; 
#endif

struct Node{
    int pref, sum, ans, suff;
    bool operator==(const Node& o){
        return tie(pref, sum, ans, suff) == tie(o.pref, o.sum, o.ans, o.suff);
    }
};
// -*-*-* All variables *-*-*-
const Node NEUTRAL = {-INF, 0, 0, 0};
Node t[MAXN];
int n, m, N;

// -*-*-* All functions *-*-*-
void init(){
    int power = 0;
    while ((1 << power) < n) power++;
    N = (1 << power);
    for (int i = 0;i < 2 * N; i++) t[i] = NEUTRAL;
}

Node merge(Node a, Node b){
    if (a == NEUTRAL) return b;
    if (b == NEUTRAL) return a;
    Node ans;
    ans.sum = a.sum + b.sum;
    ans.pref = max(a.pref, a.sum + b.pref);
    ans.suff = max(b.suff, b.sum + a.suff);
    ans.ans = max(a.ans, b.ans);
    ans.ans = max(ans.ans, b.sum);
    ans.ans = max(ans.ans, b.sum);
    ans.ans = max(ans.ans, a.suff + b.pref);
    return ans;
}

Node get(int pos, int tl, int tr, int l, int r){
    if (tl >= r || l >= tr) return NEUTRAL;
    // cerr << pos << ' ' << tl << ' ' << tr << ' ' << l << ' ' << r  << ' ' << (l <= tl && tr <= r) << '\n';
    if (l <= tl && tr <= r) return t[pos];
    int tm = (tl + tr) / 2;
    auto g_left = get(2 * pos, tl, tm, l, r);
    auto g_right = get(2 * pos + 1, tm, tr, l, r);
    return merge(g_left, g_right);
}
void solve(){
    init();
    // cerr << n << ' ' << m << '\n';
    for (int i = 0; i < n; i++){
        // cerr << i << '\n';
        int tmp;
        cin >> tmp;
        t[N + i] = {tmp, tmp, tmp, tmp};
    }
    for (int i = N - 1; i >= 1; i--){
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    while (m--){
        int l, r;
        cin >> l >> r;
        cout << get(1, 0, N, l - 1, r).ans << '\n';
    }
}
int main(){
    #ifdef LOCAL
    string taskName = "D";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
    #endif
    while(cin >> n >> m){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}