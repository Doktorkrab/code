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

int n;
const int MAXN = 1e3 + 7;
vector<int> g[MAXN];
int used[MAXN];
pair<int, int> points[MAXN];

inline int dist(const pair<int, int>& a, const pair<int, int>& b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
void dfs(int v){
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
}
inline void init(){

}

inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    int l = 0, r = 1e9 + 7;
    while (r - l > 1){
        int m = (l + r) / 2;
        for (int i = 0; i < n; i++){
            used[i] = 0;
            g[i].clear();
        }
        // cerr << m << '\n';
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                if (i != j && dist(points[i], points[j]) <= m){
                    g[i].push_back(j);
                }
            }
        dfs(0);
        int flag = 1;
        for (int i = 0; i < n; i++)
            flag &= used[i];
        if (flag)
            r = m;
        else
            l = m;
    }
    cout << r << '\n';

}


int main(){
	#ifdef LOCAL
		freopen("G.in", "r", stdin);
		freopen("G.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}