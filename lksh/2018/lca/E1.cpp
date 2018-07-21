#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 20;
const int MAXN = 100;
#else
const int INF = 1e9;
const int MAXN = 2e6 + 1e4;
#endif
const int OPEN = -1, CLOSE = 1;
struct Event{
    int x, type, ind;
    bool operator<(const Event& o) const{
        return tie(x, type, ind) < tie(o.x, o.type, o.ind);
    }
};
// -*-*-* All variables *-*-*-
int tree[2 * MAXN];
int arr[2 * MAXN];
int ans[MAXN];
int tin[MAXN];
int tout[MAXN];
int color[MAXN];
int timer = 0;
Event events[MAXN];
pair<int, int> segments[MAXN];
vector<int> g[MAXN];
int n, m;
// -*-*-* All functions *-*-*-
int pointer = 0;
void insert(int x, int what){
    for (int i = x; i < MAXN; i = i | (i + 1)) tree[i] += what;
}

int get_sum(int r){
    int ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) ans += tree[i];
    return ans;
}
void dfs(int v){
    assert(timer + 1 < 2 * MAXN);
    tin[v] = timer;
    arr[timer++] = color[v];
    for (int u : g[v]){
        dfs(u);
    }
    tout[v] = timer;
    assert(timer + 1 < 2 * MAXN);
    arr[timer++] = color[v];
    segments[v] = {tin[v], tout[v]};
    events[pointer++] = {tout[v], CLOSE, v};

}
void solve(){
    int root = -1;
    for (int i = 0; i < n; i++){
        int p, cl;
        cin >> p >> cl;
        if (!p) root = i;
        else g[--p].push_back(i);
        color[i] = cl;
    }
    dfs(root);
    unordered_map<int, int> lst;
    int nxt = 0;
    for (int i = 0;i < 2 * n; i++){
        cerr << arr[i] << ' ' << (lst.count(arr[i]) ? lst[arr[i]] : -1) << ' ' << i << '\n';
        if (lst.count(arr[i])) insert(lst[arr[i]], -1);
        insert(i, 1);
        lst[arr[i]] = i;
        while (nxt < n && events[nxt].x <= i){
            ans[events[nxt].ind] = get_sum(i) - get_sum(segments[events[nxt].ind].first - 1);
            nxt++;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
    string taskName = "E";
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