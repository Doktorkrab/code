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
const int MAXN = 1e5 + 7;
vector<pair<int, int>> g[MAXN];
priority_queue<pair<int, int>> edges;
int used[MAXN];
inline void init(){
    for (int i = 0; i < MAXN; i++)
        g[i].clear();
    memset(used, 0, sizeof(int) * MAXN);
}

inline void solve(){
    init();
    for (int i = 0; i < m; i++){
        int v, u, w;
        cin >> v >> u >> w;
        --v, --u;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    vector<int> ans = {0};
    for (auto [u, d] : g[0]){
        edges.push({d, u});
    }
    used[0] = 1;
    int64_t sum = 0;
    while (!edges.empty()){
        auto [d, v] = edges.top();
        edges.pop();
        if (used[v])
            continue;
        used[v] = 1;
        sum += d;
        ans.push_back(v);
        for (auto [u, d] : g[v]){
            if (used[u])
                continue;
            edges.push({d, u});
        }
    }
    cout << sum << '\n';
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#else
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
