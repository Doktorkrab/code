#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;
int n, m;
const int MAXN = 5e6;
int st[MAXN];
inline int get_ind(char c){
    if (c == 'A')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'G')
        return 2;
    return 3;
}
struct Node{
    int lft = -1, rgt = -1, in = -1, out = -1;
    vector<int> terminal;
    Node* go[4];
};
struct Event{
    int x, type, index;
    int mn, mx;
    bool operator<(const Event& oth) const {
        return tie(x, type, index, mn, mx) < tie(oth.x, oth.type, oth.index, oth.mn, oth.mx);
    }
};
Node* root_normal, *root_reversed;
void add_str(Node* root, const string& s, int index){
    for (char c : s){
        int ch = get_ind(c);
        if (!root->go[ch])
            root->go[ch] = new Node();
        root = root->go[ch];
    }
    root->terminal.push_back(index);
}
vector<int> lft, rgt;
vector<int> euler;
vector<int> ans;
int now = 0;

inline void init(){
    root_normal = new Node();
    root_reversed = new Node();
    lft.resize(n, -1);
    rgt.resize(n, -1);
    ans.resize(m, 0);
}

void dfs(Node* v){
    if (!v)
        return;
    int ll = now;
    now++;
    for (int i = 0; i < 4; i++)
        dfs(v->go[i]);
    for (int i : v->terminal){
        lft[i] = ll;
        rgt[i] = now;
    }
    // if (v->terminal.empty())
    v->lft = ll;
    v->rgt = now;
}

void dfs2(Node* v){
    if (!v)
        return;
    int inn = euler.size();
    for (int i : v->terminal)
        euler.push_back(lft[i]);
    for (int i = 0; i < 4; i++)
        dfs2(v->go[i]);
    v->in = inn;
    v->out = euler.size();
}

void insert(int v, int L, int R, int x, int how){
    // cerr << v << ' ' << L << ' ' << R << ' ' << x << ' ' << how << '\n';
    if (x < L || R <= x)
        return;
    if (R - L == 1){
        st[v] += how;
        return;
    }
    int M = (L + R) / 2;
    insert(v * 2, L, M, x, how);
    insert(v * 2 + 1, M, R, x, how);
    st[v] = st[2 * v] + st[2 * v + 1];
}

int get(int v, int L, int R, int l, int r){
    if (r <= L || R <= l)
        return 0;
    if (l <= L && R <= r)
        return st[v];

    int M = (L + R) / 2;
    return get(v * 2, L, M, l, r) + get(v * 2 + 1, M, R, l, r);
}

Node* tour(Node* now, const string& s, int pos){
    if (!now || (int)s.size() == pos)
        return now;
    return tour(now->go[get_ind(s[pos])], s, pos + 1);
}
inline void solve(){
    init();
    int cnt = 0;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        add_str(root_normal, s, i);
        reverse(s.begin(), s.end());
        add_str(root_reversed, s, i);
        cnt += s.size();
    }
    euler.reserve(cnt);

    dfs(root_normal);
    // cerr << "dfs1\n";
    //     for (int i : lft)
    //         cerr << i << ' ';
    //     cerr << '\n';
    dfs2(root_reversed);
    // cerr << "dfs2\n";
    // for (int i : euler)
    //     cerr << i << ' ';
    // cerr << '\n';
    vector<Event> events;
    for (int i = 0; i < m; i++){
        // cerr << "!" << i << '\n';
        string p, q;
        cin >> p >> q;
        reverse(q.begin(), q.end());
        Event start, stop;
        start.type = -1;
        stop.type = 1;
        start.index = i;
        stop.index = i;
        Node* normal = tour(root_normal, p, 0);
        if (!normal){
            continue;
        }
        start.mn = stop.mn = normal->lft;
        start.mx = stop.mx = normal->rgt;
        Node* reversed = tour(root_reversed, q, 0);
        if (!reversed)
            continue;
        start.x = reversed->in;
        stop.x = reversed->out;
        // cerr << "Start Event:\n";
        // cerr << '\t' << start.type << ' ' << start.index << ' ' << start.mn << ' ' << start.mx << ' ' << start.x << '\n';
        // cerr << "End Event\n";
        // cerr << '\t' << stop.type << ' ' << stop.index << ' ' << stop.mn << ' ' << stop.mx << ' ' << stop.x << '\n';
        events.push_back(start);
        events.push_back(stop);
    }
    sort(events.begin(), events.end());
    // cerr << "sorted\n";
    int pnt = 0;
    int N = (1 << 21);
    euler.push_back(N - 1);
    for (int i = 0; i < euler.size(); i++){
        // cerr << "added " << euler[i] << " at " << i << '\n';
        while (pnt < events.size() && events[pnt].x == i){
            const Event& e = events[pnt];
            int tmp = get(1, 0, N, e.mn, e.mx);
            // cerr << "getting " << tmp << " for " << e.index << " " << e.type << '\n';
            // cerr << '\t' << e.mn << ' ' << e.mx << '\n';
            ans[e.index] += e.type * tmp;
            pnt++;
        }
        insert(1, 0, N, euler[i], 1);
    }
    for (int i : ans)
        cout << i << '\n';

}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}