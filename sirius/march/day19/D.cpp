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
#define int int64_t
const int MAXN = 1e4 + 7;
vector<pair<int, pair<int, int>>> g[MAXN];
pair<int, int> dist[MAXN];
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> setik;
int n, m;
inline void init(){
    fill(dist, dist + MAXN, make_pair(0x3f3f3f3f, 0x3f3f3f3f));
    for (int i = 0; i < MAXN; i++)
        g[i].clear();
}
bool cmp (const pair<int, int>& a, const pair<int, int>& b){
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
inline void solve(){
    init();
    for (int i = 0; i < m; i++){
        int cnt = 0;
        cin >> cnt;
        int prev;
        cin >> prev;
        prev--;
        vector<pair<int, int>> tmp = {{0, prev}};        
        //cerr << cnt <<  ' ' << prev << '\n';
        for (int j = 0; j < cnt; j++){
            int t, u;
            cin >> t >> u;
            //cerr << t << ' ' << u - 1 << '\n';
            tmp.push_back({t, u - 1});
        }
        for (int j = 0; j < (int)tmp.size(); j++){
            int sm = 0;
            for (int k = j + 1; k < (int)tmp.size(); k++){
                sm += tmp[k].first;
                //cerr << tmp[j].second << "->" << tmp[k].second << "(cost: " << sm << ", " << sm * sm << ")\n";
                g[tmp[j].second].push_back({tmp[k].second, {sm, -sm * sm}});
            }
        }
    }
    setik.push({{0, 0}, 0});
    while (!setik.empty()){
        auto top = setik.top();
        setik.pop();
        auto dt = top.first;
        auto v = top.second;
        //cerr << v << ' ' << dt.first << ' ' << dt.first << '\n';
        if (dist[v] <= dt)
            continue;
        dist[v] = dt;
        for (auto e : g[v]){
            int u = e.first;
            int t = e.second.first;
            int tt = e.second.second;
            pair<int, int> nxt = {dist[v].first + t, dist[v].second + tt};
            if (dist[u] > nxt)
                setik.push({nxt, u});
        }
    }
    assert(dist[n - 1].first < 0x3f3f3f3f);
    cout << dist[n - 1].first << ' ' << -dist[n - 1].second << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
