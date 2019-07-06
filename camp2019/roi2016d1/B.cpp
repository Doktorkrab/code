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

const int MAXN = 105;
int n, m, g;
char field[MAXN][MAXN];
int used[MAXN][MAXN];
int depth[MAXN][MAXN];
int cycle_len[MAXN * MAXN];
int in[MAXN * MAXN];
inline void init(){
    for (int i = 0; i < MAXN; i++){
        memset(field[i], 0, MAXN);
        memset(used[i], 0, MAXN * sizeof(int));
    }
}
map<char, pair<int, int>> shift = {{'e', {0, 1}}, {'n', {-1, 0}}, {'s', {1, 0}}, {'w', {0, -1}}}; 
int now = 1;
int dfs(int x, int y, int dep = 1){
    cerr << x + 1 << ' ' << y + 1 << ' ' << now << ' ' << dep << ' ' << field[x][y] << '\n';
    int sx, sy;
    used[x][y] = now;
    depth[x][y] = dep;
    tie(sx, sy) = shift[tolower(field[x][y])];
    if (used[x + sx][y + sy]){
        used[x][y] = used[x + sx][y + sy];
        if (!cycle_len[used[x + sx][y + sy]]){
            cycle_len[used[x + sx][y + sy]] = dep - depth[x + sx][y + sy] + 1;
            if (isupper(field[x][y])){
                in[used[x][y]]++;
                field[x][y] = tolower(field[x][y]);
            }
        }
        return used[x][y];
    }
    dfs(sx + x, sy + y, dep + 1);
    used[x][y] = used[sx + x][sy + y];
    if (isupper(field[x][y])){
        in[used[x][y]]++;
        field[x][y] = tolower(field[x][y]);
    }
    return used[x][y];
}
inline void solve(){
    init();
    assert(g == 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> field[i][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (used[i][j]){
                if (isupper(field[i][i]))
                    in[used[i][j]]++;
                continue;
            
            }
            dfs(i, j);
            now++;
        }
    }
    int ans = 0;
    for (int i = 1; i < now; i++){
        cerr << in[i] << ' ' << cycle_len[i] << '\n';
        ans += min(in[i], cycle_len[i]);
    }
    cout << ans << '\n';
    cerr << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> g)
        solve();

}
