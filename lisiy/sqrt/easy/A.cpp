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
const int INF = 1000;
const int MAXN = 12;
#else
#define err() ;
const int MAXN = 2e5;
const int INF = 1e18; 
#endif

// -*-*-* All variables *-*-*-
int n;
vector<int> arr;
// -*-*-* All functions *-*-*-
void init(){
    arr.assign(n, 0);
}
struct Decomposition{
    int block_size;
    vector<int> blocks;
    vector<int> arr;
    vector<int> add;
    Decomposition () {}
    Decomposition(int bl_sz, const vector<int>& arr_) : block_size(bl_sz) {
        blocks.assign((n + block_size - 1) / block_size, INF);
        arr.resize(n);
        add.resize((n + block_size - 1) / block_size);
        int block = 0;
        for (int i = 0; i < n; i++){
            arr[i] = arr_[i];
            blocks[block] = min(blocks[block], arr[i]);
            if ((i + 1) % block_size == 0){
                block++;
            }
        }
    }
    
    int get_block_by_index(int i) { return i / block_size; }

    void pull(int block){
        blocks[block] = INF;
        for (int i = 0; i + block * block_size < (int) arr.size() && i < block_size; i++){
            blocks[block] = min(blocks[block], arr[i + block * block_size]);
        }
    }
    void push(int block){
        // cerr << block << ' ' << add[block] << '\n';
        blocks[block] += add[block];
        for (int i = 0; i + block * block_size < (int) arr.size() && i < block_size; i++){
            arr[i + block * block_size] += add[block];
        }
        add[block] = 0;
    }
    int get_sum(int l, int r){
        int ans = INF;
        int bl_r = r / block_size, bl_l = l / block_size;
        push(bl_l);
        push(bl_r);
        for(;l <= min(r, block_size * (bl_l + 1) - 1); l++) ans = min(ans, arr[l]);
        if (l > r) return ans;
        for (int block = bl_l + 1; block < bl_r; block++) ans = min(blocks[block] + add[block], ans);
        l = min(r, bl_r * block_size);
        for (; l <= r; l++) ans = min(ans, arr[l]);
        return ans;
    }
    void update(int l, int r, int x){
        int bl_r = r / block_size, bl_l = l / block_size;
        push(bl_l);
        push(bl_r);
        for(;l <= min(r, block_size * (bl_l + 1) - 1); l++) arr[l] += x;
        if (l > r) return;
        for (int block = bl_l + 1; block < bl_r; block++) add[block] += x;
        l = min(r, bl_r * block_size);
        for (; l <= r; l++) arr[l] += x;
        pull(bl_l);
        pull(bl_r);
    }
};
void solve(){
    init();
    for (int i = 0; i < n; i++) cin >> arr[i];
    Decomposition dec = Decomposition(256, arr);
    int m;
    cin >> m;
    while (m--){
        int type, l ,r;
        cin >> type >> l >> r;
        if (type == 1){
            int x;
            cin >> x;
            dec.update(l - 1, r - 1, x);
        }
        else{
            cout << dec.get_sum(l - 1, r - 1) << '\n';
        }
    }
}
int32_t main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    #ifdef LOCAL
    string taskName = "A";
    assert(freopen((taskName + ".in").c_str(), "r", stdin));
    assert(freopen((taskName + ".out").c_str(), "w", stdout));
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n){
        solve();
        print(cout);
    }
}