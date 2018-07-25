#include <bits/stdc++.h>

using namespace std;
void print(ostream& ot){
    ot << '\n';
}
template<typename Arg, typename... Args>
void print(ostream& ot, const Arg& arg, const Args&... arg1){
    ot << arg << ' ';
    print(ot, arg1...);
}


#define err(x) print(cerr, #x, x)
#define int int64_t
#ifdef LOCAL
const int INF = 100;
const int MAXN = 10;
#else
const int MAXN = 2e5 + 2;
#define err() ;
const int INF = 1e9; 
#endif
const int MAXC = 4e5 + 1;
struct Segment{
    int l, r, ind;
};
// -*-*-* All variables *-*-*-
int n, m;
int tree[MAXC];
int arr[MAXN];
int ans1[MAXN];
Segment segments[MAXN];
const int BLOCK_SIZE = 256;
// -*-*-* All functions *-*-*-
void insert(int x, int what){
    for (int i = x; i < MAXC; i = i | (i + 1)) tree[i] += what;
}

int get_sum(int r){
    int ans = 0;
    for (int i = r; i >= 0; i = (i & (i +  1)) - 1) ans += tree[i];
    return ans;
}

bool cmp(Segment a, Segment b){
    if (a.l / BLOCK_SIZE == b.l / BLOCK_SIZE){
        if ((a.l / BLOCK_SIZE) % 2) return a.r > b.r;
        return a.r < b.r;
    }
    return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
}

void init(){
    memset(tree, 0, sizeof(tree));
    memset(arr, 0, sizeof(arr));
    memset(ans1, 0, sizeof(ans1));

}
void solve(){
    init();
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        segments[i] = {l - 1, r - 1, i};
    }
    sort(segments, segments + m, cmp);
    int l = 0, r = -1;
    int cnt = 0;
    int64_t ans = 0;
    for (int i = 0; i < m; i++){
        while (r < segments[i].r) {
            // print(cerr, arr[r + 1], cnt, get_sum(arr[r + 1] - 1), r);
            // assert(cnt >= get_sum(arr[r + 1]));
            ans += get_sum(MAXC - 1) - get_sum(arr[++r] - 1);
            insert(arr[r], 1);
        }
        while (r > segments[i].r) {
            // print(cerr, '\t', arr[r], cnt - 1, get_sum(arr[r]), r);
            insert(arr[r], -1);
            // assert(cnt - 1 >= get_sum(arr[r]));
            ans -= get_sum(MAXC - 1) - get_sum(arr[r--] - 1);
        }
        while (l < segments[i].l){
            // print(cerr, "\t\t", arr[l], get_sum(arr[l]), l);
            insert(arr[l], -1);
            --cnt;
            ans -= get_sum(arr[l++]);
        }
        while (l > segments[i].l){
            // print(cerr, "\t\t\t", arr[l - 1], get_sum(arr[l - 1]), l);
            ans += get_sum(arr[--l]);
            insert(arr[l], 1);
            cnt++;
        }
        // cerr << segments[i].ind << ' ' << ans << '\n';
        ans = max(ans, (int64_t)0);
        assert(ans >= 0);
        ans1[segments[i].ind] = ans;
    }
    for (int i = 0; i < m; i++) cout << ans1[i] << '\n';
}
int32_t main(){
    #ifdef LOCAL
    string taskName = "D4";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}