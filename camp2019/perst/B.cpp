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
#include <climits>
using namespace std;
#define int int64_t

const int DELETE = LONG_LONG_MIN;
const int MAXN = 2e5 + 7;
int n;
vector<pair<int, int>> g[MAXN];
deque<int> kek;
int ans[MAXN];
inline void init(){
    for (int i = 0; i < MAXN; i++)
        g[i].clear();
    fill(ans, ans + MAXN, DELETE);
    kek.clear();
}
void dfs(int v, bool to_delete = 0){
    if (to_delete){
        ans[v] = kek.front();
        kek.pop_front();
    }
    for (auto u : g[v]){
        if (u.second != DELETE)
            kek.push_back(u.second);
        dfs(u.first, u.second == DELETE);
        if (u.second != DELETE)
            kek.pop_back();
    }
    if (to_delete)
        kek.push_front(ans[v]);
}
inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        int type, version, element;
        cin >> type >> version;
        if (type == -1)
            g[version].push_back({i + 1, DELETE});
        else{
            cin >> element;
            g[version].push_back({i + 1, element});
        }
    }
    dfs(0);
    for (int i = 0; i <= n; i++){
        if (ans[i] != DELETE)
            cout << ans[i] << '\n';
    }
}


int32_t main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
