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
const int MAXN = 10;
#else
#define err() ;
const int MAXN = 2e5 + 1;
const int INF = 1e9; 
#endif

const int OPEN = -1;
const int CLOSE = 1;
struct Segment{
    int l, r;
    bool operator< (const Segment& o) const {
        return make_pair(l, r) < make_pair(o.l, o.r);
    }
};
struct Event{
    int type, x, index;
    bool operator< (const Event& o) const {
        return tie(x, type, index) < tie(o.x, o.type, o.index);
    }
};

// -*-*-* All variables *-*-*-
set<Segment> skyline;
Segment segments[MAXN];
Event events[2 * MAXN];
int n;
// -*-*-* All functions *-*-*-
void init(){
    skyline.clear();  
}

void solve(){
    init();
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if (!i) continue;
        int l = i, r = i + tmp;
        events[2 * i] = {OPEN, l, i};
        events[2 * i + 1] = {CLOSE, r, i};
        segments[i] = {l, r};
    }
    sort(events, events + n + n);
    int pnt = 0;
    for (int i = 0; i < n; i++){
        while (pnt < 2 * n && events[pnt].x == i){
            // print(cerr, i, events[pnt].type, events[pnt].index);
            if (events[pnt].type == OPEN) skyline.insert(segments[events[pnt].index]);
            else skyline.erase(segments[events[pnt].index]);
            pnt++;
        }
        if (skyline.empty()) cout << 0 << ' ';
        else cout << i - skyline.begin()->l + 1 << ' ';
    }
}
int main(){
    #ifdef LOCAL
    string taskName = "D3";
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