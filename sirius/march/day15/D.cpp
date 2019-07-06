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

const int MAXN = 20;
int n;
int d[MAXN], dist[MAXN];
int used[MAXN];
vector<pair<int, int>> g[MAXN];
inline void init(){

}
bool bfs(int mask){
    memset(dist, 0, sizeof(int) * MAXN);
    memset(used, 0, sizeof(int) * MAXN);
    deque<int> q;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i)){
            q.push_back(i);
            dist[i] = 0;
        }
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        if (used[v])
            continue;
        used[v] = 1;
        for (auto [u, dd] : g[v]){
            if (dist[u] > dist[v] + 1 && dd <= d[v]){
                dist[u] = dist[v] + 1;
                q.push_back(u);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (!used[i])
            return 0;
    return 1;
}
inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n - 1; i++){
        int v, u, w;
        cin >> v >> u >> w;
        --v, --u;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    int ans = 1e9;
    for (int mask = 0; mask < (1 << n); mask++){
        if (!bfs(mask))
            continue;
        int cnt = 0;
        for (int i =0; i < n; i++)
            cnt += !!((1 << i) & mask);
        ans = min(cnt, ans);
    }
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#else
        freopen("alarm.in", "r", stdin);
        freopen("alarm.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}