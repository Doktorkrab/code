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
#else
#define err() ;

const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
struct Node{
    vector<Node*> edges;
    int cnt;
    Node() : edges(2, nullptr), cnt(0) {}
};
using nd = Node*;
nd root;
vector<int> prefs;
int n, m, q;
// -*-*-* All functions *-*-*-

void insert(nd a, const string& s){
    for (char c : s){
        a->cnt++;
        if (!a->edges[c - '0']) a->edges[c - '0'] = new Node();
        a = a->edges[c - '0'];
    }
}
int safe(nd a){
    return (a ? a->cnt : 0);
}
int k;
string t;
int get(nd a, int pos){
    cerr << ((bool) a) << ' ' << pos << '\n';
    cerr << prefs.size() << '\n';
    if (!a) return 0;
    if (pos == n){
        return (prefs[pos] <= k) * a->cnt;
    }
    return  (prefs[max(pos, 0)] <= k) * safe(a->edges[1 - (t[pos] - '0')]) + get(a->edges[t[pos] - '0'], pos + 1);
}
void init(){
    root = new Node();
    prefs.assign(n + 1, 0);
}

void solve(){
    init();
    for (int i = 0; i < n; i++){
        cin >> prefs[i + 1];
        prefs[i + 1] += prefs[i];
    }
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        insert(root, s);
    }
    for (int i = 0; i < q; i++){
        cin >> t >> k;
        cout << get(root, 0) << '\n';
    }
}
int main(){
    #ifdef LOCAL
    string taskName = "";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n >> m >> q){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}