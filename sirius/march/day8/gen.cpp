#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fld;
vector<vector<int>> dist;
vector<vector<bool>> used;
int n, m;
vector<pair<int, int>> shift = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void bfs(int xs, int ys){
	dist[xs][ys] = 0;
	deque<pair<int, int>> q = {{xs, ys}};
	while (!q.empty()){
		auto [x, y] = q.front();
		q.pop_front();
		if (used[x][y])
			continue;
		used[x][y] = 1;
		for (auto [nx, ny] : shift){
			int sx = x + nx, sy = y + ny;
			if (0 > sx || 0 > sy || sx >= n || sy >= m || fld[sx][sy] == 1)
				continue;
			if (dist[sx][sy] > dist[x][y] + 1){
				dist[sx][sy] = dist[x][y] + 1;
				q.push_back({sx, sy});
			}
		}
	}
}
int main(){
	mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
	n = rnd() % 5 + 3, m = rnd() % 5 + 3;
	cerr << n << ' ' << m << '\n';
	fld.assign(n, vector<int>(m));
	used.assign(n, vector<bool>(m));
	dist.assign(n, vector<int>(m, (int) 1e9));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int ch = (rnd() % 3) / 2;
			if (ch)
				fld[i][j] = 1;
			else
				fld[i][j] = 0;
		}
	}
	while (1){
		int x = rnd() % n;
		int y = rnd() % m;
		if (fld[x][y])
			continue;
		bfs(x, y);
		vector<pair<int, int>> aval;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (dist[i][j] < (int)1e9 && dist[i][j] != 0)
					aval.push_back({i, j});
		if (!aval.size())
			continue;
		shuffle(aval.begin(), aval.end(), rnd);
		cout << n << ' ' << m << '\n';
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (fld[i][j])
					cout << '#';
				else if (i == x && j == y)
					cout << 'S';
				else if (i == aval[0].first && j == aval[0].second)
					cout << 'C';
				else
					cout << '.';
			}
			cout << '\n';
		}
		break;
	}
}