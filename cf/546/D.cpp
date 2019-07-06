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

const int MAXN = 3e5 + 7;
int n, m;
vector<int> g[MAXN];
int good[MAXN];
int pos[MAXN];
inline void init(){
    memset(good, 0, sizeof(int) * MAXN);
    for (int i = 0; i < MAXN; i++)
        g[i].clear();
}

inline void solve(){
    // init();
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        pos[x] = i;
    }
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v = pos[v];
        u = pos[u];
        // g[v].push_back(u);
        g[u].push_back(v);
    }
    int good_cnt = 0;
    for (int u : g[n - 1])
        good[u]++;

    for (int i = n - 2; i >= 0; i--){
        // cerr << n - 1 - i - good_cnt << ' ' << good[i] << '\n';
        if (n - 1 - i - good_cnt == good[i]){
            good_cnt++;
            continue;
        }
        for (int u : g[i]){
            good[u]++;
        }
    }
    cout << good_cnt << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}