#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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
const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
using namespace std;
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { } // must have!
int n, m;
const int MAXN = 1e3 + 7;
const int INF = 0x3f3f3f3f;
int dist[MAXN][MAXN];
int lft[MAXN][MAXN], rgt[MAXN][MAXN], up[MAXN][MAXN], down[MAXN][MAXN];
int field[MAXN][MAXN], used[MAXN][MAXN];
vector<pair<int, int>> shift = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
inline void init(){
	for (int i = 0; i < MAXN; i++)
		fill(dist[i], dist[i] + MAXN, INF);
}
bool is_correct(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m && field[x][y] == 0;
}
inline void solve(){
	init();
	pair<int, int> startPos;
	pair<int, int> endPos;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char x;
			cin >> x;
			if (x == 'S')
				startPos = {i, j};
			if (x == 'C')
				endPos = {i, j};
			if (x == '#')
				field[i][j] = -1;
			else
				field[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (j == 0 || field[i][j - 1] == -1)
				lft[i][j] = j;
			else
				lft[i][j] = lft[i][j - 1];
		}
		for (int j = m - 1; j >= 0; j--){
			if (j == m - 1 || field[i][j + 1] == -1)
				rgt[i][j] = j;
			else
				rgt[i][j] = rgt[i][j + 1];
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (j == 0 || field[j - 1][i] == -1)
				up[j][i] = j;
			else
				up[j][i] = up[j - 1][i];
		}
		for (int j = n - 1; j >= 0; j--){
			if (j == n - 1 || field[j + 1][i] == -1)
				down[j][i] = j;
			else
				down[j][i] = down[j + 1][i];
		}
	}
	// dist[startPos.first][startPos.second] = 0;
	set<pair<int, pair<int, int>>> q;
	q.insert({0, {startPos.first, startPos.second}});
	while (!q.empty()){
		auto [dt, tmp] = *(q.begin());
		auto [x, y] = tmp;
		q.erase(q.begin());
		// cerr << used[x][y] << '\n';
		if (dist[x][y] < dt)
			continue;
		dist[x][y] = dt;
		vector<pair<int, int>> to_sort = {{y - lft[x][y], 0}, {rgt[x][y] - y, 1}, {x - up[x][y], 2}, {down[x][y] - x, 3}};
		sort(to_sort.begin(), to_sort.end());
		dt = to_sort[0].first;
		if (to_sort[0].second == 0)
			dt = to_sort[1].first;
		if (dist[x][lft[x][y]] > dist[x][y] + dt + 1){
			q.insert({dist[x][y] + dt + 1, {x, lft[x][y]}}); 
		}
		dt = to_sort[0].first;
		if (to_sort[0].second == 1)
			dt = to_sort[1].first;
		if (dist[x][rgt[x][y]] > dist[x][y] + dt + 1){
			dist[x][rgt[x][y]] = dist[x][y] + dt + 1;
			q.insert({dist[x][y] + dt + 1, {x, rgt[x][y]}}); 
		}
		dt = to_sort[0].first;
		if (to_sort[0].second == 2)
			dt = to_sort[1].first;
		if (dist[up[x][y]][y] > dist[x][y] + dt + 1){
			dist[up[x][y]][y] = dist[x][y] + dt + 1;
			q.insert({dist[x][y] + dt + 1, {up[x][y], y}}); 
		}
		dt = to_sort[0].first;
		if (to_sort[0].second == 3)
			dt = to_sort[1].first;
		if (dist[down[x][y]][y] > dist[x][y] + dt + 1){
			dist[down[x][y]][y] = dist[x][y] + dt + 1;
			q.insert({dist[x][y] + dt + 1, {down[x][y], y}}); 
		}
		for (auto [sh_x, sh_y] : shift){
			int nx = sh_x + x, ny = sh_y + y;
			// cerr << nx << ' ' << ny << '\n';
			if (!is_correct(nx, ny))
				continue;
			if (dist[nx][ny] > dist[x][y] + 1){
				dist[nx][ny] = dist[x][y] + 1;
				q.insert({dist[x][y] + 1, {nx, ny}});
			}
		}
	}
	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < m; j++){
	// 		cerr << setw(2) << (dist[i][j] >= INF ? -1 : dist[i][j]); 
	// 		cerr << " \n"[j == m - 1];
	// 	}
	cout << dist[endPos.first][endPos.second] << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A_100.in", "r", stdin);
		freopen("A_100.out", "w", stdout);
	#else
		freopen("portals.in", "r", stdin);
		freopen("portals.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}