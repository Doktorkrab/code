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

int n, m;
const int MAXN = 1e3 + 7;
unordered_map<int64_t, int> dist;
unordered_set<int64_t> used;
int field[MAXN][MAXN];
int lft[MAXN][MAXN], rgt[MAXN][MAXN], up[MAXN][MAXN], down[MAXN][MAXN];
int tmp_dist[MAXN][MAXN];
vector<pair<int, int>> shift = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// inline void init(){
// }
struct State{
	pair<int, int> cur_pos, portal_pos;
	
	State(const pair<int, int>& a, const pair<int, int>& b) : cur_pos(a), portal_pos(b) {}
	State() {}
	uint64_t get_hash() const {
		// cerr << cur_pos.first << ' ' << cur_pos.second << ' ' << portal_pos.first << ' ' << portal_pos.second << '\n';
		// cerr << cur_pos.first << ' ' << cur_pos.second * 10000LL << ' ' << portal_pos.first * 100000000LL << ' ' << portal_pos.second * 1000000000000LL << '\n';
		return cur_pos.first + cur_pos.second * 10000LL + portal_pos.first * 100000000LL + portal_pos.second * 1000000000000LL;
	}
	bool operator<(const State& oth) const {
		return get_hash() < oth.get_hash();
	}
};
State get_state(int64_t hash){
	return {{hash % 10000, (hash / 10000) % 10000}, {(hash / 100000000) % 10000, (hash / 1000000000000) % 10000}};
}
bool is_correct(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m && field[x][y] == 0; 
}
inline void solve(){
	State startPos;
	State endPos;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char x;
			cin >> x;
			if (x == 'S')
				startPos = {{i, j}, {1001, 1001}};
			if (x == 'C')
				endPos = {{i, j}, {1001, 1001}};
			if (x == '#')
				field[i][j] = -1;
			else
				field[i][j] = 0;
			tmp_dist[i][j] = 0x3f3f3f3f;
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

	// dist[startPos.get_hash()] = 0;
	deque<int64_t> q;
	q.push_back(startPos.get_hash());
	int ans = INT_MAX;
	while (!q.empty()){
		auto pos_hash = q.front();
		auto pos = get_state(pos_hash);
		auto [x, y] = pos.cur_pos;
		// cerr << pos_hash << '\n';
		q.pop_front();
		int dt = dist[pos_hash];
		if (endPos.cur_pos == pos.cur_pos){
			ans = min(ans, dt);
			break;
		}
		if (used.count(pos_hash))
			continue;
		used.insert(pos_hash);
		// cerr << x << ' ' << y << ' ' << x_p << ' ' << y_p << ' ' << dt << '\n';
		// dist[pos_hash] = dt;
		// tmp_dist[x][y] = min(tmp_dist[x][y], dt);
		vector<pair<int, int>> aval_protals = {pos.portal_pos};
		if (up[x][y] != x)
			aval_protals.push_back({up[x][y], y});
		if (down[x][y] != x)
			aval_protals.push_back({down[x][y], y});
		if (lft[x][y] != y)
			aval_protals.push_back({x, lft[x][y]});
		if (rgt[x][y] != y)
			aval_protals.push_back({x, rgt[x][y]});
		int kek = (up[x][y] == x) || (down[x][y] == x) || (lft[x][y] == y) || (rgt[x][y] == y);
		State portal = State(pos.portal_pos, pos.portal_pos);

		for (auto [sh_x, sh_y] : shift){
			int nx = sh_x + x, ny = sh_y + y;
			if (!is_correct(nx, ny))
				continue;
			for (auto pt : aval_protals){
				int64_t nxt = State({nx, ny}, pt).get_hash();
				// cerr << nxt << ' ' << pos_hash << '\n';
				if (!dist.count(nxt) || dist[nxt] > dt + 1){
					// cerr << nx << ' ' << ny << " " << pt.first << ' ' << pt.second << '\n';
					dist[nxt] = dt + 1;
					q.push_back(nxt);
				}
			}
		}

		if (kek == 0)
			continue;
		for (auto pt : aval_protals){
			int64_t pt_hash = State(pt, pt).get_hash();
			if (pt.first != 1001 && (!dist.count(pt_hash) || dist[pt_hash] > dt + 1)){
				q.push_back(pt_hash);
				dist[pt_hash] = dt + 1;
			}
		}
	}
	cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
		// freopen("portals.in", "r", stdin);
		// freopen("portals.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}