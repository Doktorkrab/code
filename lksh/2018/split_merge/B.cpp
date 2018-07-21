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
const int MAXN = 100;
#else
#define err() ;
const int MAXN = 4e6;
const int INF = 1e9; 
#endif

struct Version{
    int vertex, parent, sz;
};

struct Event{
    int type;
    int v, u; // for +, - events
    int pair; // for - event
};

// -*-*-* All variables *-*-*-
vector<Version> st; // (v, parent[v])
int parent[MAXN];
int sz[MAXN];
int n, k;
Event events[MAXN];
int ans[MAXN];
int components;
map<pair<int, int>, int> lst;
// -*-*-* All functions *-*-*-
void init(){
    for (int i = 0; i < n; i++) parent[i] = i, sz[i] = 1;
    st.clear();
    memset(ans, 0, sizeof(bool) * n);
    lst.clear();
    components = n;
}
int get(int v){ return (parent[v] == v ? parent[v] : get(parent[v])); }
void un(int a, int b){
    a = get(a), b = get(b);
    if (sz[a] > sz[b]) swap(a, b);
    st.emplace_back((Version){a, parent[a], sz[b]});
    parent[a] = b;
    sz[b] += sz[a];
    components--;
}
void get_prev(){
    Version top = st.back();
    st.pop_back();
    sz[parent[top.vertex]] = top.sz;
    parent[top.vertex] = top.parent;
    components++;
}

bool check(int v, int u) { return get(v) == get(u);}

void split(int tl, int tr){
    if (tr == 0) return; // if no events
    if (tr - tl == 1){
        // print(cerr, (char)events[tl].type, tl, tr);
        if (events[tl].type == '?'){
            ans[tl] = components;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    int cnt = 0;
    // print(cerr, tl + 1, tr, components);
    // for (int i = 0; i < n; i++){
    //     cerr << parent[i] << ' ';
    // }
    // cerr << '\n';
    for (int i = tl; i < tm; i++){
        if (events[i].type == '+' && events[i].pair >= tr && !check(events[i].v, events[i].u)){
            un(events[i].v, events[i].u);
            cnt++;
        }
    }
    split(tm, tr);
    while (cnt > 0) {
        get_prev();
        cnt--;
    }
    for (int i = tm; i < tr; i++){
        if (events[i].type == '-' && events[i].pair < tl && !check(events[i].v, events[i].u)){
            un(events[i].v, events[i].u);
            cnt++;
        }
    }
    split(tl, tm);
    while (cnt--) get_prev();
}
void solve(){
    init();
    for (int i = 0; i < k; i++){
        char c;
        cin >> c;
        int v, u;
        if (c == '+') {
            cin >> v >> u;
            lst[{min(v, u), max(v, u)}] = i;
            events[i] = {c, v - 1, u - 1, INF};
        }
        if (c == '-'){
            cin >> v >> u;
            events[lst[{min(v, u), max(v, u)}]].pair = i;
            events[i] = {c, v - 1, u - 1, lst[{min(v, u), max(v, u)}]};
        }
        if (c == '?'){
            events[i] = {c, -1, -1, -INF};
        }
        ans[i] = -1;
    }
    split(0, k);
    for (int i = 0; i < k; i++){
        if (ans[i] != -1) print(cout, ans[i]);
    }

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
    while(cin >> n >> k){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}