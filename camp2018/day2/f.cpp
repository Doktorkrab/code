#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define ALLOC

#define MX MAX_INT
#define MIX MIN_INT
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0;i < n;i++)
#define ft first
#define st second
#define pb push_back

#ifdef ALLOC
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { }
#endif

// TEMPLATE END

// CODE HERE
struct TNode{
    ll l, r, max;
    TNode* left = nullptr, *right = nullptr;
    TNode(int l, int r) : l(l), r(r) {}
};
using node = TNode*;

ll safe_max(node a){ return a ? a->max : 0;}

void recalc(node a){
    a->max = max(safe_max(a->left), safe_max(a->right));
}

node build(int l, int r){
    node cur = new TNode(l, r);
    if (r - l == 1){
        cur->max = 0;
        return cur;
    }
    int m = (l + r) / 2;
    cur->left = build(l, m);
    cur->right = build(m, r);
    return cur;
}

ll get(node a, int l, int r){
    if (r <= a->l || l >= a->r) return 0;
    if (a->l >= l && a->r <= r) return a->max;
    return max(get(a->left, l ,r), get(a->right, l, r));
}

void insert(node a, int pos, ll x){
    if (!a) assert(0);
    if (a->r <= pos || a->l > pos) return;
    if (a->r - a->l == 1){
        a->max = max(a->max, x);
        return;
    }
    insert(a->left, pos, x);
    insert(a->right, pos, x);
    recalc(a);
}
struct Event{
    int x, y, type, r;
    bool operator<(Event& o){
        return tie(x, type, y, r) < tie(o.x, o.type, o.y, o.r);
    }
};
struct Solver{
    unordered_map<int, int> compress;
    int n;
    vector<Event> events;
    vector<int> to_sort;
    node root = nullptr;
    Solver(){
        cin >> n;
        forn(i, n){
            int x, y, x1, y1, r;
            cin >> x >> y >> x1 >> y1 >> r;
            if (!compress.count(y)){
                compress[y] = 1;
                to_sort.push_back(y);
            }
            if (!compress.count(y1)){
                compress[y1] = 1;
                to_sort.push_back(y1);
            }
            events.push_back({x, y, 0, r});
            events.push_back({x1, y1, 1, r});
        }
        sort(all(events));
        sort(all(to_sort));
        root = build(0, to_sort.size() + 5);
        forn(i, to_sort.size()) compress[to_sort[i]] = i;
        for (Event ev : events){
            if (ev.type == 1){
                insert(root, compress[ev.y], ev.r);
            }
            else{
                if (get(root, compress[ev.y] + 1, to_sort.size() + 5) == 0) continue;
                cout << ev.x << ' ' << ev.y << ' ' << get(root, compress[ev.y] + 1, to_sort.size() + 5) << ' ' << ev.r << '\n';
                insert(root, compress[ev.y], get(root, compress[ev.y], to_sort.size() + 5) + ev.r);
            }
        }
        cout << get(root, 0, to_sort.size() + 5) << '\n';
    }   
};

// CODE END

int main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    string FN = "";
    // freopen(FN + ".in", "r", stdin);
    // freopen(FN + ".out", "w", stdout);
#endif
    while(t--){
#ifdef LOCAL
        clock_t t_elapsed = clock();
#endif
        Solver a;
#ifdef LOCAL
        cout << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }

}
