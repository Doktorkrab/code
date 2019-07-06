#pragma GCC optimize("Ofast")
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
#define FMA 1e7
#ifdef FMA
int alloc_pos = 0;
char alloc[(int) FMA];
void* operator new (size_t n){
    char *res = alloc + alloc_pos;
    alloc_pos += n;
    assert(alloc_pos <= (int) FMA);
    return (void*) res;
}
void operator delete( void* ) noexcept {}
#endif
const int MAXN = 1507;
int n;
pair<int, int> islands[MAXN];
vector<int> g[MAXN];
int dist[MAXN];
bool used[MAXN];

inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> islands[i].first >> islands[i].second;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (islands[i].first < islands[j].first && islands[i].second < islands[j].second){
                g[i].push_back(j);
                g[j].push_back(i);
            }

    deque<int> q;
    for (int i = 0; i < n; i++){
        fill(dist, dist + n, 0x3f3f3f3f);
        dist[i] = 0;
        memset(used, 0, n);
        int sum = 0;
        q.push_back(i);
        while (!q.empty()){
            int v = q.front();
            q.pop_front();
            if (used[v])
                continue;
            used[v] = 1;
            sum += dist[v];
            for (int u = 0; u < n; u++){
                if (islands[v].first < islands[u].first && islands[v].second < islands[u].second){
                    if (dist[u] > dist[v] + 1 && !used[u]){
                        dist[u] = dist[v] + 1;
                        q.push_back(u);
                    }
                }
                if (islands[v].first > islands[u].first && islands[v].second > islands[u].second){
                    if (dist[u] > dist[v] + 1 && !used[u]){
                        dist[u] = dist[v] + 1;
                        q.push_back(u);
                    }
                }
            }
        }
        cout << sum << '\n';
    }
}


int main(){
#ifdef LOCAL
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
#else
    freopen("adriatic.in", "r", stdin);
    freopen("adriatic.out", "w", stdout);
#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
