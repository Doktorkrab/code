#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
string s;
vector<int> p, c;
int n;

bool cmp(int i, int j) { return s[i] < s[j];}
// -*-*-* All functions *-*-*-
void build_zero_level(){
    stable_sort(p.begin(), p.end(), cmp);
    int class_now = 0;
    for (int i = 0; i < n; i++){
        cerr << i << ' ' << p[i] << ' ' << s[p[i]] << ' ' << class_now << '\n';
        if (i && s[p[i]] != s[p[i - 1]]) class_now++;
        c[p[i]] = class_now;
    }
    for (int i : p) cerr << s[i] << ' ';
    cerr << '\n';
    for (int i : c) cerr << i << ' ';
    cerr << '\n';
}
void build_suff_array(){
    build_zero_level();
    for (int k = 2; k <= n; k <<= 1){
        vector<int> pos(n + 1), c2(n), p2(n);
        for (int i = 0; i < n; i++){
            pos[c[i] + 1]++;
        }
        for (int i = 1;i < n; i++){
            pos[i] += pos[i - 1];
        }
        for (int i = 0; i < n; i++){
            int j = (p[i] - k / 2 + n) % n;
            p2[pos[c[j]]++] = j;
        }
        for(int i : p2) cerr << i << ' ';
        cerr << '\n';
        int class_now = 0;
        for (int i = 0; i < n; i++){
            if (i && make_pair(c[p2[i]], c[(p2[i] + k) % n]) != make_pair(c[p2[i - 1]], c[(p2[i - 1] + k) % n])) class_now++;
            c2[p2[i]] = class_now;
        }
        swap(c, c2);
        swap(p, p2);
        for (int i : p){
            // cerr << n - i << ' ' << k - n + i << '\n';
            if (i + k - 1 < n){
                cerr << s.substr(i, k) << ' ' << i + 1 << '\n';
            }
            else cerr << s.substr(i, n - i) << s.substr(0, k - n + i) << ' ' << i + 1 << '\n';
        }
    }
    vector<int> ans(n);
}
void init(){
    p.resize(n);
    c.resize(n);
    iota(p.begin(), p.end(), 0);
}

void solve(){
    getline(cin, s);
    n = s.size() + 1;
    init();
    s += '#';
    cout << s << '\n';
    build_suff_array();
    for (int i : p) cout << i + 1<< ' ';
    cout << '\n';
}
int main(){
    #ifdef LOCAL
    string taskName = "A";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    solve();
    #ifdef LOCAL
    cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
    #endif
}