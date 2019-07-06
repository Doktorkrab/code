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
#define int int64_t
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

const int MAXN = 6e5;
Node sa[MAXN];
int last = 0, pnt = 1;
int ans = 0;

int get(int x){
	return sa[x].len - sa[sa[x].link].len;
}
void add(char c) {      
    int cur = pnt++;
    sa[cur].len = sa[last].len + 1;
    int p;
    for (p = last; p != -1 && sa[p].go[c] == -1; p = sa[p].link) {
        sa[p].go[c] = cur;        
    }
    if (p == -1) {
        sa[cur].link = 0;
        ans += get(cur);
    } else {
        int q = sa[p].go[c];
        if (sa[p].len + 1 == sa[q].len) {
            sa[cur].link = q;
            ans += get(cur); 
        } else {
            int clone = pnt++;
            sa[clone].len = sa[p].len + 1;  
            for (int i = 0; i < 26; i++)
            	sa[clone].go[i] = sa[q].go[i];

            sa[clone].link = sa[q].link;
            ans += get(clone); 
            for (; p != -1 && sa[p].go[c] == q; p = sa[p].link) {
                sa[p].go[c] = clone;
            } 
            ans -= get(q); 
            sa[q].link = sa[cur].link = clone;
            ans += get(q); 
            ans += get(cur); 
        }
    }
    last = cur;
}

void add(const string &s) {
    for (char c : s) {
        add(c - 'a');
        cout << ans << '\n';
    }
}

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
//    freopen("suffix2.out", "w", stdout);
#endif
    string s;
    cin >> s;
    add(s);
}