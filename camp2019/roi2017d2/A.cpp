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

const int MAXN = 1e6 + 7;
int n;
string s, t;
int block_startt[MAXN];
int block_starts[MAXN];
int p[MAXN];
int sz[MAXN];
int ok[MAXN];
int llft[MAXN];
int rrgt[MAXN];
inline void init(){
    n = s.size();
    iota(p, p + n, 0);
    iota(llft, llft + n, 0);
    iota(rrgt, rrgt + n, 0);
    fill(sz, sz + n, 1);
    fill(ok, ok + n, 0);
}
int find_set(int v){
    if (p[v] == v)
        return v;
    else
        return (p[v] = find_set(p[v]));
}

void mrg(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    if (sz[a] > sz[b])
        swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
    llft[b] = min(llft[b], llft[a]);
    rrgt[b] = max(rrgt[b], rrgt[a]);
}
inline void solve(){
    init();
    char prev = -1;
    for (int i = 0; i < n; i++){
        if (prev != s[i])
            block_starts[i] = 1;
        else
            block_starts[i] = 0;
        prev = s[i];
    }
    prev = -1;
    for (int i = 0; i < n; i++){
        if (prev != t[i])
            block_startt[i] = 1;
        else
            block_startt[i] = 0;
        prev = t[i];
    }
    for (int i = 0; i < n; i++){
        if (block_startt[i] && !block_starts[i]){
            cout << "No\n";
            return;
        }
    }
    vector<pair<int, int>> now;
    vector<vector<int>> blocks;
    int cnt = 0, start = 0, len = 1, good = s[0] == t[0];
    for (int i = 1; i <= n; i++){
        if (i == n || s[i] != s[i - 1]){
            blocks.push_back({start, len, s[i - 1]});
            sz[cnt] = len;
            if (good){
                now.push_back({cnt, cnt});
                ok[cnt] = 1;
            }
            cnt++;
            start = i;
            len = 1;
            good = s[i] == t[i];
        }
        else{
            len++;
            if (s[i] != t[i])
                good = 0;
        }
    }
    while (now.size()){
        vector<pair<int, int>> nxt;
        for (auto i : now){
            int lft, rgt;
            tie(lft, rgt) = i;
            int sl = sz[find_set(lft)];
            int sr = sz[find_set(rgt)];
            int was = 0;
            if (lft > 0 && !ok[lft - 1] && sl > sz[find_set(lft - 1)] && blocks[lft - 1][2] != blocks[lft][2]){
                for (int j = 0; j < blocks[lft - 1][1]; j++)
                    s[blocks[lft - 1][0] + j] = blocks[lft][2];
                mrg(lft, lft - 1);
                was = 1;
                ok[lft - 1] = 1;
                if (lft > 1){
                    mrg(lft, lft - 2);
                }
            }
            if (rgt + 1 < cnt && !ok[rgt + 1] && sr > sz[find_set(rgt + 1)] && blocks[rgt + 1][2] != blocks[rgt][2]){
                for (int j = 0; j < blocks[rgt + 1][1]; j++)
                    s[blocks[rgt + 1][0] + j] = blocks[rgt][2];
                mrg(rgt, rgt + 1);
                ok[rgt + 1] = 1;
                was = 1;
                if (rgt + 2 < cnt){
                    mrg(rgt, rgt + 2);
                }
            }
            if (was)
                nxt.push_back({llft[find_set(lft)], rrgt[find_set(rgt)]});
        }
        swap(now, nxt);
    }
    if (s == t)
        cout << "Yes\n";
    else
        cout << "No\n";
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (cin >> s >> t)
        solve();

}
