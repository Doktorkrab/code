#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
#ifdef LOCAL
const int INF = 1e2;
const int MAXN = 4e5 + 100;
#else
const int INF = 1e9;
const int MAXN = 4e5 + 100;
#endif
const ull BASE = 127;
const ull MOD = 150000001;
const ull MOD_SQR = MOD * MOD;
struct Node{
    ull hash = 0;
    int can_use = 0;    
};
ull BASES[MAXN];
struct Tree{
    Node st[MAXN];
    int N;
    Tree (int n){
        int power = 0;
        while ((1 << power) < n) power++;
        N = (1 << power);
    }
    Tree () {}
    Node get_hash(int v, int tl, int tr, int l, int r){
        if (tl > r || l > tr) return {0, 0};
        // cerr << tl << " " << tr << ' ' << l << ' ' << r << ' ' <<st[v].hash << '\n';
        if (l <= tl && tr <= r) return st[v];
        int tm = (tl + tr) / 2;
        auto left = get_hash(2 * v, tl, tm, l, r);
        auto right = get_hash(2 * v + 1, tm + 1, tr, l, r);
        // cerr << tl << ' ' << tm << ' ' << tm + 1 << ' ' << tr << ' ' << left.hash << ' ' << right.hash << " " << ((left.hash * BASES[right.can_use]) + right.hash) << " Exit\n";
        // cerr << left.can_use << ' ' << right.can_use << '\n';
        return {((left.hash * BASES[right.can_use]) % MOD + right.hash) % MOD, left.can_use + right.can_use}; //% MOD;
    }
    Node get_hash(int l, int r){ return get_hash(1, 0, N - 1, l, r); }
    void update(int v, int tl, int tr, int pos, char c){
        if (pos < tl || pos > tr) return;
        // cerr << tl << ' ' << tr << ' ' << pos << ' ' << v << '\n';
        if (tr == tl){
            st[v].hash = c;
            st[v].can_use = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, pos, c);
        update(2 * v + 1, tm + 1, tr, pos, c);
        st[v].can_use = st[2 * v].can_use + st[2 * v + 1].can_use;
        st[v].hash = ((st[2 * v].hash * BASES[st[2 * v + 1].can_use]) % MOD + st[2 * v + 1].hash) % MOD; // % MOD;
        // cerr << st[v].hash << ' ' << tl << ' ' << tr << ' ' << st[2 * v].hash << ' ' << st[2 * v + 1].hash << " Exit\n";
    }

    void update(int pos, char c) { return update(1, 0, N - 1, pos, c); }
};
// -*-*-* All variables *-*-*-
Tree regular, reversed;
string s;
// -*-*-* All functions *-*-*-
void init(){
    BASES[0] = 1;
    for (int i = 1; i < MAXN; i++) BASES[i] = (BASES[i - 1] * BASE) % MOD;
}

void solve(){
    init();
    regular = Tree((int)s.size());
    reversed = Tree((int)s.size());
    for (int i = 0; i < (int)s.size(); i++){
        regular.update(i, s[i]);
        reversed.update((int)s.size() - 1 - i, s[i]);
    }
    // exit(0);
    // for (int i = 1; i < 2 * regular.N; i++){
        // cerr << i << ' ' << regular.st[i].hash << ' ' << regular.st[i].can_use << ' ' << reversed.st[i].hash << ' ' << reversed.st[i].can_use << '\n';
    // }
    // exit(0);
    int m;
    cin >> m;
    while (m--){
        string query;
        cin >> query;
        if (query[0] == 'p'){
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            // cerr << l << ' ' << r << '\n';
            Node reg = regular.get_hash(l, r);
            int tl = (int) s.size() - r - 1;
            int tr = (int) s.size() - l - 1;
            // cerr << tl << ' ' << tr << '\n';
            Node rev = reversed.get_hash(tl, tr);
            // cerr << reg.hash << ' ' << rev.hash << '\n';
            cout << (reg.hash == rev.hash ? "Yes" : "No") << '\n';
        }
        else{
            int pos;
            char c;
            cin >> pos >> c;
            --pos;
            // cerr << "INSERT!!!!!\n\n\n\n";
            regular.update(pos, c);
            reversed.update((int)s.size() - pos - 1, c);
        }
    }
}
int main(){
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
    while(cin >> s){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}