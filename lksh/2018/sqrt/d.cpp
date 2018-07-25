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

#ifdef LOCAL
const int INF = 100;
const int MAXN = 10;
#else
#define err() ;
const int MAXN = 2e5 + 1;
const int INF = 1e9; 
#endif

const int MAXC = 1e6 + 1;
// -*-*-* All variables *-*-*-
struct Segment{
    int l, r, id;
};
Segment segments[MAXN];
int64_t cnt[MAXC];
int arr[MAXN];
int64_t segments_ans[MAXN];
int n, m;
int BLOCK_SIZE = 256;
// -*-*-* All functions *-*-*-
void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(segments_ans, 0, sizeof(segments_ans));
}
bool cmp(Segment a, Segment b){
    if (a.l / BLOCK_SIZE == b.l / BLOCK_SIZE){
        if ((a.l / BLOCK_SIZE) % 2) return a.r > b.r;
        return a.r < b.r;
    }
    return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
}
void solve(){
    // init();
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        segments[i] = {--l, --r, i};
        // cerr << segments[i].first << ' ' << segments[i].second << '\n';
    }
    sort(segments, segments + m, cmp);
    int l = 0, r = -1;   
    int64_t ans = 0;
    for (int i = 0; i < m ; i++){
        // print(cerr, l, r, segments[i].first, segments[i].second);
        while (r < segments[i].r){
            // print(cerr, l, r, segments[i].first, segments[i].second, "down r");            
            r++;
            ans -= cnt[arr[r]] * cnt[arr[r]] * arr[r];
            cnt[arr[r]]++;
            ans += cnt[arr[r]] * cnt[arr[r]] * arr[r];
        }
        while (r > segments[i].r){
            // print(cerr, l, r, segments[i].first, segments[i].second, "up r");            
            ans -= cnt[arr[r]] * cnt[arr[r]] * arr[r];
            cnt[arr[r]]--;
            ans += cnt[arr[r]] * cnt[arr[r]] * arr[r];
            --r;
        }
        while (l < segments[i].l){
            // print(cerr, l, r, segments[i].first, segments[i].second, "up l");            
            ans -= cnt[arr[l]] * cnt[arr[l]] * arr[l];
            cnt[arr[l]]--;
            ans += cnt[arr[l]] * cnt[arr[l]] * arr[l];
            l++;
        }
        while (l > segments[i].l){
            // print(cerr, l, r, segments[i].first, segments[i].second, "down l");            
            l--;
            ans -= cnt[arr[l]] * cnt[arr[l]] * arr[l];
            cnt[arr[l]]++;
            ans += cnt[arr[l]] * cnt[arr[l]] * arr[l];
        }
        segments_ans[segments[i].id] = ans;
    }
    for (int i = 0; i < m; i++) cout << segments_ans[i] << '\n';
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
    string taskName = "e";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n >> m){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}