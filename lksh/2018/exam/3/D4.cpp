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
const int64_t INF = 100;
const int MAXN = 5;
#else
#define err() ;
const int MAXN = 32;
const int64_t INF = 1e18; 
#endif
struct LOL{
    int mask;
    int64_t k, w;
    LOL () {}
    LOL (int mask, int64_t k, int64_t w) : mask(mask), k(k), w(w) {}
    bool operator<(const LOL& o) const {
        return k < o.k;
    }
};
struct Node{
    int64_t x, y;
    LOL val, max;
    Node* left = nullptr;
    Node* right = nullptr;
    Node (int64_t x, int64_t val, int mask) : x(x), y(rand()), val(mask, val, x), max(mask, val, x) {}
};

using nd = Node*;

// -*-*-* All functions *-*-*-

LOL mx(nd a){
    return (a ? a->max : LOL(-INF, -INF, -INF));
}

nd rc(nd a){
    a->max = max(mx(a->left), max(mx(a->right), a->val));
    return a;
}

nd merge(nd a, nd b){
    if (!a) return b;
    if (!b) return a;
    if (a->y < b->y){
        a->right = merge(a->right, b->left);
        return rc(a);
    }
    b->left = merge(a, b->left);
    return rc(b);
}

using pnn = pair<nd, nd>;

pnn split(nd a, int64_t x){ // (-inf; x) [x; +inf)
    if (!a) return {nullptr, nullptr};
    if (a->x <= x){
        pnn tmp = split(a->right, x);
        a->right = tmp.first;
        return {rc(a), tmp.second};
    }
    pnn tmp = split(a->left, x);
    a->left = tmp.second;
    return {tmp.first, rc(a)};
}

void insert(nd& a, int64_t w, int64_t k, int mask){
    if (!a){
        a = new Node(w, k, mask);
        return;
    }
    pnn tmp = split(a, w);
    pnn tmp1 = split(tmp.first, w - 1);
    tmp1.second = new Node(w, k, mask);
    a = merge(merge(tmp1.first, tmp1.second), tmp.second);
}

void print(nd a){
    if (!a) return;
    print(a->left);
    print(cerr, a->x);
    print(a->right); 
}
// -*-*-* All variables *-*-*-
pair<int64_t, int64_t> things[MAXN], things1[MAXN];
int64_t r, l;
int n;

void init(){

}

void solve(){
    for (int i = 0; i < n; i++){
        if (i < n / 2) cin >> things[i].first >> things[i].second;
        else cin >> things1[i - (n / 2)].first >> things1[i - (n / 2)].second;
    }
    LOL kek[1 << (n / 2)];
    for (int mask = 0; mask < (1 << (n / 2)); mask++){
        int64_t w = 0, s = 0;
        for (int i = 0; i < n / 2; i++){
            if ((1 << i) & mask){
                w += things[i].first;
                s += things[i].second;
            }
        }
        kek[mask] = {mask, s, w};
    }
    nd b = nullptr;
    for (int mask = 0; mask < (1 << (n / 2 + n % 2)); mask++){
        int64_t w = 0, s = 0;
        for (int i = 0; i < (n / 2 + n % 2); i++){
            if ((1 << i) & mask){
                w += things1[i].first;
                s += things1[i].second;
            }
        }
        insert(b, w, s, mask);
    }
    sort(kek, kek + (1 << (n / 2)));
    int64_t ans = -INF, mask = -INF, mask1 = -INF;
    for (int i = 0; i < (1 << (n / 2)); i++) {
        pnn tmp = split(b, l - kek[i].w);
        pnn tmp1 = split(tmp.second, r - kek[i].w + 1);
        int64_t nw = kek[i].k + mx(tmp1.first).k;
        if (nw > ans){
            ans = nw;
            mask = kek[i].mask;
            mask1 = mx(tmp1.first).mask;
        }
    }
    if (mask == -INF){
        print(cout, 0);
    }
    else{
        vector<int> gg;
        for (int i = 0; i < (n / 2); i++){
            if ((1 << i) & mask){
                gg.push_back(i + 1);
            }
        }
        for (int i = 0; i < (n / 2 + n % 2); i++){
            if ((1 << i) & mask1){
                gg.push_back(i + 1 + n / 2);
            }
        }
        print(cout, (int)gg.size());
        for (int i : gg) cout << i << ' ';
        print(cout);
    }
}
int main(){
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