#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif

struct Node{
    int prior, size, min, val, reverse;
    Node* left = nullptr, *right = nullptr;
    Node (int val) : val(val), min(val), reverse(0), prior(rand()), size(1) {}
    void merge(Node& other) {
        
    }
};

using node = Node*;

// -*-*-* All variables *-*-*-
node t;
int n, m;

// -*-*-* All functions *-*-*-

int safe_sz(node a){
    return (a ? a->size : 0);
}

int safe_min(node a){
    return (a ? a->min : INF);
}
node pull(node a){
    a->size = safe_sz(a->left) + 1 + safe_sz(a->right);
    a->min = min(min(safe_min(a->left), safe_min(a->right)), a->val);
    return a;
}
void push(node a){
    // cerr << a->val << ' ' << a->reverse << " val\n";
    if (a->left){
        a->left->reverse ^= a->reverse;
    }
    if (a->right){
        a->right->reverse ^= a->reverse;
    }
    if (a->reverse){
        // cerr << "val " << a->val << '\n';
        swap(a->left, a->right);
        a->reverse = 0;
    }
    // cerr << "kekekke";
}
node merge(node a, node b){
    if (!a) return b;
    if (!b) return a;
    // cerr << safe_sz(a) << ' ' << safe_sz(b) << '\n';
    push(a);
    push(b);
    if (a->prior < b->prior){
        a->right = merge(a->right, b);
        return pull(a);
    }
    b->left = merge(a, b->left);
    return pull(b);
}

void print (node t){
    if (!t) return;
    print(t->left);
    cerr << t->val << ' ';
    print(t->right);
}
using ptt = pair<node, node>;
ptt split(node t, int key){ // (-inf; x] x; +inf)
    if (!t) return {nullptr, nullptr};
    push(t);
    if (safe_sz(t->left) < key){
        auto tmp = split(t->right, key - safe_sz(t->left) - 1);
        t->right = tmp.first;
        return make_pair(pull(t), tmp.second);
    }
    auto tmp = split(t->left, key);
    t->left = tmp.second;
    return make_pair(tmp.first, pull(t));
}

void insert(node& t, int key){ // t not nullptr
    assert(t);
    // cerr << "kek";
    t = merge(t, new Node(key));
    // cerr << "lol\n";
}


void push_reverse(node& t, int l, int r){
    auto tmp = split(t, r);
    // print(tmp.first);
    // cerr << '\n';
    auto tmp1 = split(tmp.first, l - 1);
    // print(tmp1.second);
    // cerr << '\n';
    tmp1.second->reverse ^= 1;
    // push(tmp1.second);
    t = merge(merge(tmp1.first, tmp1.second), tmp.second);
}

int get_min(node t, int l, int r){
    auto tmp = split(t, r);
    auto tmp1 = split(tmp.first, l - 1);
    int ans = tmp1.second->min;
    t = merge(merge(tmp1.first, tmp1.second), tmp.second);
    return ans;
}
void init(){
    t = nullptr;
}
void solve(){
    srand(time(0));
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if (!t) t = new Node(tmp);
        else insert(t, tmp);
    }
    for (int i = 0; i < m; i++){
        int query, l, r;
        cin >> query >> l >> r;
        if (query == 2){
            cout << get_min(t, l, r) << '\n';
        }
        else{
            push_reverse(t, l, r);
        }
        // cerr << i << '\n';
    }
    
}
int main(){
    #ifdef LOCAL
    string taskName = "F";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
    #endif
    while(t--){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}