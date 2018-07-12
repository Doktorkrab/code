#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXN = 10;
#else
const int INF = 1e9;
const int MAXN = 3e5;
#endif
const int OPEN = -1, CLOSE = 1;
struct Event{
    int x, type, ind;
    bool operator<(const Event& o) const{
        return tie(x, type, ind) < tie(o.x, o.type, o.ind);
    }
};
// -*-*-* All variables *-*-*-
int tree[MAXN];
int arr[MAXN], arr1[MAXN];
int ans[MAXN];
vector<Event> events;
vector<pair<int, int>> segments;
int n, m;
// -*-*-* All functions *-*-*-
void init(){
    memset(arr, 0, MAXN);
    memset(tree, 0, MAXN);
    memset(ans, 0, MAXN);
    memset(arr1, 0, MAXN);
    events.clear();
    segments.clear();
}
void insert(int x, int what){
    for (int i = x; i < n; i = i | (i + 1)) tree[i] += what;
    arr1[x] += what;
}
int get_sum(int r){
    int ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) ans += tree[i];
    return ans;
}
void solve(){
    init();
    for (int i = 0;i < n;i++) cin >> arr[i];
    cin >> m;
    events.resize(m);
    segments.resize(m);
    for (int i = 0;i < m; i++){
        int l, r;
        cin >> l >> r;
        events[i] = {r - 1, CLOSE, i};
        segments[i] = {l - 1, r - 1};
    }
    unordered_map<int, int> lst;
    sort(events.begin(), events.end());
    int nxt = 0;
    for (int i = 0;i < n; i++){
        if (lst.count(arr[i])) insert(lst[arr[i]], -1);;
        insert(i, 1);
        lst[arr[i]] = i;
        while (nxt < m && events[nxt].x <= i){
            ans[events[nxt].ind] = get_sum(i) - get_sum(segments[events[nxt].ind].first - 1);
            nxt++;
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << '\n';
}
int main(){
    #ifdef LOCAL
    string taskName = "B";
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