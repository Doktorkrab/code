#include <bits/stdc++.h>
#define int int64_t

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
const int INF = 1e17;
const int MAXN = 32;
#else
#define err() ;
const int MAXN = 32;
const int INF = 1e17; 
#endif

// -*-*-* All variables *-*-*-
pair<int, int> t[MAXN], t1[MAXN];
int l, r, n;
struct Data_{
    int w = 0, s = 0, mask = 0;
    Data_(int w, int s, int mask) : w(w), s(s), mask(mask) {}
    Data_ () {}
    bool operator<(const Data_& o) const{
        return make_pair(s, w) < make_pair(o.s, o.w);
    }
};
// -*-*-* All functions *-*-*-
void init(){

}
vector<pair<Data_, Data_>> st, st1;
void push(Data_ s){
    Data_ mx = s;
    // print(cerr, "push");
    if (st.size()) mx = max(mx, st.back().second);
    st.push_back({s, mx});
    // print(cerr, "push end");
}

Data_ get_max(){
    // print(cerr, "get_max");
    // print(cerr, "get_max end");
    return max((st.size() ? st.back().second : Data_(-INF, -INF, -INF)), (st1.size() ? st1.back().second : Data_(-INF, -INF, -INF)));
}
bool cmp(const Data_& a, const Data_& b){
    return make_pair(a.w, a.s) < make_pair(b.w, b.s); 
}
void pop(){
    // print(cerr, "pop");
    if (st1.size()){
        st1.pop_back();
        return;
    }
    while (st.size()){
        auto top = st.back();
        st.pop_back();
        Data_ mx = top.first;
        if (st1.size()) mx = max(mx, st1.back().second);
        st1.push_back({top.first, mx});
    }
    st1.pop_back();
    // print(cerr, "pop end");
}
void solve(){
    for (int i = 0; i < n; i++){
        if (i < n / 2) cin >> t[i].first >> t[i].second;
        else cin >> t1[i - n / 2].first >> t1[i - n / 2].second;
    }
    Data_ kek[1 << (n / 2)];
    for (int mask = 0; mask < (1 << (n / 2)); mask++){
        int w = 0, s = 0;
        for (int i = 0; i < (n / 2); i++){
            if ((1 << i) & mask){
                w += t[i].first;
                s += t[i].second;
            }
        }
        kek[mask] = {w, s, mask};
    }
    sort(kek, kek + (1 << (n / 2)), cmp);
    Data_ lol[1 << (n / 2 + n % 2)];
    for (int mask = 0; mask < (1 << (n / 2 + n % 2)); mask++){
        int w = 0, s = 0;
        for (int i = 0; i < (n / 2 + n % 2); i++){
            if ((1 << i) & mask){
                w += t1[i].first;
                s += t1[i].second;
            }
        }
        lol[mask] = {w, s, mask};
    }
    sort(lol, lol + (1 << (n / 2 + n % 2)), cmp);
    reverse(lol, lol + (1 << (n / 2 + n % 2)));
    // for (int i = 0; i < (1 << (n / 2 + n % 2)); i++) cout << lol[i].first << ' ' << lol[i].second << '\n';
    int l1 = 0, r1 = 0;
    int ans = 0, mask = 0, mask1 = 0;
    for (int i = 0; i < (1 << (n / 2)); i++) {
        while (r1 < (1 <<(n / 2 + n % 2)) && lol[r1].w + kek[i].w >= l){
            push(lol[r1]);
            r1++;
        }
        while (l1 < r1 && lol[l1].w + kek[i].w > r){
            pop();
            l1++;
        }
        if (ans < kek[i].s + get_max().s){
            // cerr << kek[i].s + get_max().s << ' ' << l1 << ' ' << r1 << ' '   << get_max().s << '\n';
            // print(cerr, get_max().mask);
            ans = kek[i].s + get_max().s;
            mask = kek[i].mask;
            mask1 = get_max().mask;
        }
    }
    // cout << ans;
    vector<int> gg;
    // int w = 0;
    for (int i = 0; i < (n / 2); i++){
        if ((1 << i) & mask){
            gg.push_back(i + 1);
            // w += t[i].first;
        }
    }
    for (int i = 0; i < (n / 2 + n % 2); i++){
        if ((1 << i) & mask1){
            gg.push_back(i + 1 + n / 2);
            // w += t1[i].first;
        }
    }
    // cout << w << '\n';
    // print(cerr, mask, mask1, "masks");
    print(cout, gg.size());
    for (int i : gg) cout << i << ' ';
    print(cout);
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
    while(cin >> n >> l >> r){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}