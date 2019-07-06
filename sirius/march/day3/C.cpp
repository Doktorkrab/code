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
int n, m;
const int MAXN = 305;
const int INF = LONG_LONG_MAX / 2;
int s, t, v1, u1;
inline void init(){
    --s, --t, --v1, --u1;
}
 
inline void solve300(){
    init();
    vector<vector<int>> matrix(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        matrix[i][i] = 0;
    for (int i = 0; i < m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        --x, --y;
        matrix[x][y] = matrix[y][x] = min(matrix[x][y], c);
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
    int shortest = matrix[s][t];
    int ans = matrix[u1][v1];
    // cerr << v + 1 << ' ' << u + 1 << '\n';
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (matrix[s][i] + matrix[i][j] + matrix[j][t] != shortest && matrix[s][j] + matrix[j][i] + matrix[i][t] != shortest)
                continue;
            // cerr << i + 1 << ' ' << j + 1 << ' ' << matrix[u][i] + matrix[j][v] << '\n';
            ans = min(ans, matrix[u1][i] + matrix[j][v1]);
        }
    }
    cout << ans << '\n';
}
inline void solvesu(){
    init();
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++){
        int v, u, c;
        cin >> v >> u >> c;
        g[--v].push_back({--u, c});
        g[u].push_back({v, c});
    }
    vector<int> distS(n, INF);
    set<pair<int, int>> heap;
    distS[s] = 0;
    heap.insert({0, s});
    while (!heap.empty()){
        auto top = *(heap.begin());
        heap.erase(top);
        int v = top.second;
        for (auto [u, w] : g[v]){
            if (distS[u] > distS[v] + w){
                distS[u] = distS[v] + w;
                heap.insert({distS[u], u});
            }
        }
    }
    heap.clear();
    vector<int> distT(n, INF);
    distT[t] = 0;
    heap.insert({0, t});
    while (!heap.empty()){
        auto top = *(heap.begin());
        heap.erase(top);
        int v = top.second;
        for (auto [u, w] : g[v]){
            if (distT[u] > distT[v] + w){
                distT[u] = distT[v] + w;
                heap.insert({distT[u], u});
            }
        }
    }
    vector<int> distV(n, INF);
    distV[v1] = 0;
    heap.insert({0, v1});
    while (!heap.empty()){
        auto top = *(heap.begin());
        heap.erase(top);
        int v = top.second;
        for (auto [u, w] : g[v]){
            if (distV[u] > distV[v] + w){
                distV[u] = distV[v] + w;
                heap.insert({distV[u], u});
            }
        }
    }
    int ans = distS[v1];
    int len = distS[t];
    for (int i = 0; i < n; i++){
        if (distS[i] + distT[i] != len)
            continue;
        ans = min(ans, distV[i]);
    }
    cout << ans << '\n';
}
inline void solveone(){
    init();
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        g[--x].push_back({--y, c});
        g[y].push_back({x, c});
    }
    // cerr << "here\n";
    vector<int> dist(n, INF);
    vector<int> path(n, -1);
    dist[s] = 0;
    set<pair<int, int>> heap;
    heap.insert({0, s});
    while (!heap.empty()){
        auto top = *(heap.begin());
        heap.erase(top);
        int v = top.second;
        for (auto [u, w] : g[v]){
            // cerr << u << ' ' << v << '\n';
            if (dist[u] > dist[v] + w){
                dist[u] = dist[v] + w;
                heap.insert({dist[u], u});
                path[u] = v;
            }
        }
    }
    assert(dist[t] < INF);
    vector<int> dist1(n, INF);
    heap.clear();
    int now = t;
    while (now != -1){
        dist1[now] = 0;
        heap.insert({0, now});
        now = path[now];
    }
    while (!heap.empty()){
        auto top = *(heap.begin());
        heap.erase(top);
        int v = top.second;
        for (auto [u, w] : g[v]){
            if (dist1[u] > dist1[v] + w){
                dist1[u] = dist1[v] + w;
                heap.insert({dist1[u], u});
            }
        }
    }
    vector<int> dist2(n, INF);
    heap.clear();
    dist2[u1] = 0;
    heap.insert({0, u1});
    while (!heap.empty()){
        auto top = *(heap.begin());
        heap.erase(top);
        int v = top.second;
        for (auto [u, w] : g[v]){
            if (dist2[u] > dist2[v] + w){
                dist2[u] = dist2[v] + w;
                heap.insert({dist2[u], u});
            }
        }
    }
    cout << min(dist1[u1] + dist1[v1], dist2[v1]) << '\n';
}
int32_t main(){
    #ifdef LOCAL
        freopen("C.in", "r", stdin);
        freopen("C.out", "w", stdout);
    #endif
     
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> s >> t >> u1 >> v1){
        if (n <= 300)
            solve300();
        else if (s == u1)
            solvesu();
        else
            solveone();
                         
    }
 
}