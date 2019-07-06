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

string s, t;
const int MAXN = 4e3 + 100;
bool used[MAXN][MAXN];
pair<int, pair<int, char>> pre[MAXN][MAXN];
int n, m;
int hh[2][MAXN];
int ss[2][MAXN];
inline void init(){
	for (int i = 0; i < MAXN; i++){
		memset(used[i], 0, sizeof(char) * MAXN);
		fill(pre[i], pre[i] + MAXN, pair<int, pair<int, char>>(-1, {-1, 0}));
	}
	memset(hh[0], 0, sizeof(int) * MAXN);
	memset(hh[1], 0, sizeof(int) * MAXN);
	memset(ss[0], 0, sizeof(int) * MAXN);
	memset(ss[1], 0, sizeof(int) * MAXN);
}
struct gg{
	int i, j;
};
inline void solve(){
	n = s.size();
	m = t.size();
	init();
	deque<gg> q = {{n + 1, m + 1}};
	hh[0][n] = hh[1][n] = n;
	hh[0][n + 1] = hh[1][n + 1] = n;
	ss[0][m] = ss[1][m] = m;
	ss[0][m + 1] = ss[1][m + 1] = m;
	for (int i = n - 1; i >= 0; --i){
		if (i == n - 1){
			hh[0][i] = (s[i] == '0' ? i : n);
			hh[1][i] = (s[i] == '1' ? i : n);
			continue;
		}
		hh[0][i] = hh[0][i + 1];
		hh[1][i] = hh[1][i + 1];
		hh[s[i] - '0'][i] = i; 
	}
	for (int i = m - 1; i >= 0; --i){
		if (i == m - 1){
			ss[0][i] = (t[i] == '0' ? i : m);
			ss[1][i] = (t[i] == '1' ? i : m);
			continue;
		}
		ss[0][i] = ss[0][i + 1];
		ss[1][i] = ss[1][i + 1];
		ss[t[i] - '0'][i] = i; 
	}
	while (q.size()){
		auto top = q.front();
		q.pop_front();
		if (top.i == n && top.j == m){
			string ans;
			int x = n, y = m;
			while (x != -1 && y != -1){
				char ch = pre[x][y].second.second;
				// cerr << x << ' ' << y << ' ' << pre[x][y].first << ' ' << pre[x][y].second.first << ' ' << ch << ' ' << used[x][y] << '\n';
				ans += ch;
				int ll = x;
				int kk = y;
				x = pre[ll][kk].first;
				y = pre[ll][kk].second.first;
			}
			reverse(ans.begin(), ans.end());
			cout << ans << '\n';
			return;
		}
		if (top.i == n + 1)
			top.i = -1;
		if (top.j == m + 1)
			top.j = -1;
		for (char ch = '0'; ch <= '1'; ch++){
			int x = hh[ch - '0'][min(top.i + 1, n)], y = ss[ch - '0'][min(top.j + 1, m)];
			if (!used[x][y]){
				used[x][y] = used[top.i][top.j] + 1;
				pre[x][y] = {top.i, {top.j, ch}};
				q.push_back({x, y});
			}
		}
	}
	assert(0);
	// cerr << "FAILED\n";

}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s >> t)
        solve();

}