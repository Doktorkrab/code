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

const int MAXN = 3e3 + 7;
int n, q;
int a, b;
vector<pair<int, int>> g[MAXN][MAXN];
int used[MAXN][MAXN];
int x, y, x1, y11;
inline void init(){

}
bool in_rectangle(int x2, int y2){
    return x <= x2 && x2 <= x1 && y <= y2 && y2 <= y11;
}
void dfs(int x, int y){
    // cerr << x << ' ' << y << '\n';
    used[x][y] = q;
    for (auto p : g[x][y]){
        int xx = p.first, yy = p.second;
        if (in_rectangle(xx, yy) && used[xx][yy] != q)
            dfs(xx, yy);
    }
}
inline void solve(){
    // assert(n >= 10);
    // cerr << n << ' ' << q << '\n';
    vector<pair<int, int>> vertex(n);
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            used[i][j] = -1;
    for (int i = 1; i < n; i++){
        char t;
        cin >> t;
        int a, b;
        cin >> a >> b;
        --a, --b;
        vertex.push_back({a, b});
        if (t == 'h'){
            g[a][b].push_back({a + 1, b});
            g[a + 1][b].push_back({a, b});
            vertex.push_back({a + 1, b});

        }
        else{
            g[a][b].push_back({a, b + 1});
            g[a][b + 1].push_back({a, b});
            vertex.push_back({a, b + 1});
        }
    }
    // x = 0, y = 0;
    // x1 = a - 1, y11 = b - 1;
    // dfs(0, 0);
    // cerr << '\n';
    // cerr << "here\n";
    while (q--){
        cin >> x >> y >> x1 >> y11;
        --x, --y, --x1, --y11;
        int cnt = 0;
        for (auto p : vertex){
            int i = p.first, j = p.second;
                if (!in_rectangle(i, j) || used[i][j] == q)
                    continue;
                cnt++;
                dfs(i, j);
                // cerr <<'\t' <<i << ' ' << j << '\n';
        }
        // cerr << '\n';
        cout << cnt << '\n';

    }
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
        freopen("repair.in", "r", stdin);
        freopen("repair.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> b >> n >> q)
        solve();

}