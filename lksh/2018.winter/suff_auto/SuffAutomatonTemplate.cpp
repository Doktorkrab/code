//#define _FORTIFY_SOURCE 0
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("fast-math")

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <string>
#include <cassert>
#include <deque>
//#define FAST_ALLOCATOR_MEMORY 3e8
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
    char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
    inline void * operator new ( size_t n ) {
        char *res = allocator_memory + allocator_pos;
        allocator_pos += n;
        assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
        return (void *)res;
    }
    inline void operator delete ( void * ) noexcept { }
    //inline void * operator new [] ( size_t ) { assert(0); }
    //inline void operator delete [] ( void * ) { assert(0); }
#endif
using namespace std;

#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)

//------------------------------------------------------------------------------

struct Node {
    int link = -1;
    int len = 0;
    int go[26];
    int minLen = 0;

    Node() {
        for (int i = 0; i < 26; i++)
            go[i] = -1;
    }

    bool operator==(const Node &rhs) const {
        return tie(link, len, go) == tie(rhs.link, rhs.len, rhs.go);
    }
};

const int MAXN = 3e5;
Node sa[MAXN];
int last = 0, pnt = 1;

void add(char c) {
    int newLast = pnt++;
    sa[newLast].len = sa[last].len + 1;
    while (last != -1 && sa[last].go[c] == -1) {
        sa[last].go[c] = newLast;
        last = sa[last].link;
    }
    if (last == -1) {
        sa[newLast].link = 0;
        last = newLast;
        return;
    }

    int b = sa[last].go[c];
    if (sa[b].len == sa[last].len + 1) {

        sa[newLast].link = b;
        sa[newLast].minLen = sa[sa[newLast].link].len + 1;
        last = newLast;
        return;
    }
    int cloneB = pnt++;
    sa[cloneB] = sa[b];
    sa[cloneB].len = sa[last].len + 1;
    while (last != -1 && sa[last].go[c] == b) {
        sa[last].go[c] = cloneB;
        last = sa[last].link;
    }
    sa[newLast].link = cloneB;
    sa[b].link = cloneB;

    last = newLast;
}

void add(const string &s) {
    for (char c : s) {
        add(c - 'a');
    }
}

bool have(int now, int pos, const string &s) {
    if (now == -1)
        return 0;
    if (pos == (int) s.size()) {
        return 1;
    }
    if (sa[now].go[s[pos]] == -1)
        return 0;
    return have(sa[now].go[s[pos]], pos + 1, s);
}

int n, m, t;
Node automat2[MAXN];
int is_terminal2[MAXN];
int is_terminal_suf[MAXN];

bool check() {
    deque<pair<int, int>> q = {{0, 0}};
    map<pair<int, int>, bool> used;
    while (!q.empty()) {
        auto top = q.front();
        q.pop_front();
        int v = top.first, u = top.second;
        if (used.count({v, u}) && used[{v, u}])
            continue;
        used[{v, u}] = 1;
        if (is_terminal_suf[v] != is_terminal2[u])
            return 0;
        for (char w = 0; w < 26; w++) {
            int new_v = pnt, new_u = n;
            if (sa[v].go[w] != -1)
                new_v = sa[v].go[w];
            if (automat2[u].go[w] != -1)
                new_u = automat2[u].go[w];
            if (!used[{new_v, new_u}]) {
                q.push_back({new_v, new_u});
            }
        }
    }
    return 1;


}

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
//    freopen("suffix2.out", "w", stdout);
#endif
    string s;
//    freopen("suffix2.in", "r", stdin);
    for (int cnt = 1;; cnt++) {
        last = 0;
        cin >> n >> m >> t;
        if (n == 0 && m == 0 && t == 0)
            break;
        rep(i, n + 1) {
            automat2[i] = Node();
            is_terminal2[i] = 0;
        }
        rep(i, t) {
            int x;
            cin >> x;
            is_terminal2[x - 1] = 1;
        }
        rep(i, m) {
            int v, u;
            char c;
            cin >> v >> u >> c;
            --v, --u;
            automat2[v].go[c - 'a'] = u;
        }
        cin >> s;
        rep(i, 2 * s.size() + 5) {
            sa[i] = Node();
            is_terminal_suf[i] = 0;
        }
        add(s);
        int now = last;
        while (now != -1) {
            is_terminal_suf[now] = 1;
            now = sa[now].link;
        }
        if (check())
            cout << "Automaton " << cnt << " is a machinegun.\n";
        else
            cout << "Automaton " << cnt << " is not a machinegun.\n";
    }
}