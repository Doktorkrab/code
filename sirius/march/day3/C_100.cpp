#pragma GCC optimize("Ofast")
// #pragma GCC target("sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
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
// #define int int64_t
using namespace std;
const int MAXN = 1e5 + 15;
const int64_t INF = LONG_LONG_MAX / 2;
 
int n, m;
int64_t distS[MAXN], distT[MAXN], distV[MAXN], distU[MAXN], dp[MAXN], dp1[MAXN];
vector<pair<int, int>> g[MAXN];
vector<int> g1[MAXN], g2[MAXN];
priority_queue<pair<int64_t, int>> heap;
int s, t, s1, t1;
bool used[MAXN];
 
inline void init(){
    fill(distS, distS + MAXN, INF);
    fill(distT, distT + MAXN, INF);
    fill(distV, distV + MAXN, INF);
    fill(distU, distU + MAXN, INF);
    memset(used, 0, sizeof(bool) * MAXN);
    memset(dp, 0, sizeof(int) * MAXN);
    memset(dp1, 0, sizeof(int) * MAXN);
    for (int i = 0; i < MAXN; i++){
        g[i].clear();
        g1[i].clear();
        g2[i].clear();
    }
    heap = priority_queue<pair<int64_t, int>>();
}

int64_t dfs(int v, vector<int>* g, int64_t* dp){
	used[v] = 1;
	for (int u : g[v]){
		if (used[u])
			dp[v] = min(dp[v], dp[u]);
		else
			dp[v] = min(dp[v], dfs(u, g, dp));
	}
	return dp[v];
}

inline void solve(){
    // init();
    --s, --t, --s1, --t1;
    fill(distS, distS + n, INF);
    fill(distT, distT + n, INF);
    fill(distV, distV + n, INF);
    fill(distU, distU + n, INF);
    
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
 
    distS[s] = 0; 
    heap.push({0, s});
    while (!heap.empty()){
        auto [dt, v] = heap.top();
        heap.pop();
        if (dt > distS[v])
        	continue;
        for (const auto& [u, w] : g[v]){
            if (distS[u] > 1LL * distS[v] + w){
                distS[u] = distS[v] + w;
                heap.push({distS[u], u});
            }
        }
    }
    distT[t] = 0;
    heap.push({0, t});
    while (!heap.empty()){
        auto [dt, v] = heap.top();
        heap.pop();
        if (dt > distT[v])
        	continue;
        for (const auto& [u, w] : g[v]){
            if (distT[u] > 1LL * distT[v] + w){
                distT[u] = distT[v] + w;
                heap.push({distT[u], u});
            }
        }
    }
 
    distU[s1] = 0;
    heap.push({0, s1});
    while (!heap.empty()){
        auto [dt, v] = heap.top();
        heap.pop();
        if (dt > distU[v])
        	continue;
        for (const auto& [u, w] : g[v]){
            if (distU[u] > 1LL * distU[v] + w){
                distU[u] = distU[v] + w;
                heap.push({distU[u], u});
            }
        }
    }
 
    distV[t1] = 0;
    heap.push({0, t1});
    while (!heap.empty()){
        auto [dt, v] = heap.top();
        heap.pop();
        if (dt > distV[v])
        	continue;
        for (const auto& [u, w] : g[v]){
            if (distV[u] > 1LL * distV[v] + w){
                distV[u] = distV[v] + w;
                heap.push({distV[u], u});
            }
        }
    }
    int shrt = distT[s];

    for (int i = 0; i < n; i++)
        dp[i] = dp1[i] = distU[i];
    
    for (int v = 0; v < n; v++){
    	if (distS[v] + distT[v] != shrt)
    		continue;
    	for (const auto& [u, w] : g[v]){
    		if (distS[u] + distT[u] != shrt || distS[v] + distT[u] + w != shrt)
    			continue;
    		if (distS[v] < distS[u]){
    			g1[v].push_back(u);
    			g2[u].push_back(v);
    		}
    	}
    }
    dfs(s, g1, dp);
    memset(used, 0, n);
    dfs(t, g2, dp1);
    int64_t ans = distU[t1];
    for (int i = 0; i < n; i++){
        if (distS[i] + distT[i] != shrt)
            continue;
        ans = min(ans, min(dp[i], dp1[i]) + distV[i]);
    }
    cout << ans << '\n';
 
}
 
 
int32_t main(){
    #ifdef LOCAL
        freopen("C_100.in", "r", stdin);
        freopen("C_100.out", "w", stdout);
    #endif
     
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> s >> t >> s1 >> t1)
        solve();
 
}