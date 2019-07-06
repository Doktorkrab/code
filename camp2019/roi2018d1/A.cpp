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

const int MAXN = 5e3 + 7;
int n, m, q;
vector<vector<int>> arr;
vector<set<pair<int, int>>> rows;
vector<set<pair<int, int>>> columns;
inline void init(){
    arr.assign(n, vector<int>(m));
    rows.resize(n);
    columns.resize(m);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            rows[i].insert({arr[i][j], j});
            columns[j].insert({arr[i][j], i});
        }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (rows[i].rbegin()->first == columns[rows[i].rbegin()->second].rbegin()->first){
            // cerr << rows[i].rbegin()->first << ' ' << rows[i].rbegin()->second << '\n'; 
            ans++;
        }
    // cerr << ans << '\n';
    for (int k = 0; k < q; k++){
        int x, y, z;
        cin >> x >> y >> z;
        --x, --y;
        if (rows[x].rbegin()->first == columns[rows[x].rbegin()->second].rbegin()->first)
            ans--;
        if (columns[y].rbegin()->first == rows[columns[y].rbegin()->second].rbegin()->first && columns[y].rbegin()->second != x)
            ans--;
        rows[x].erase({arr[x][y], y});
        columns[y].erase({arr[x][y], x});
        arr[x][y] = z;
        rows[x].insert({arr[x][y], y});
        columns[y].insert({arr[x][y], x});
        if (rows[x].rbegin()->first == columns[rows[x].rbegin()->second].rbegin()->first)
            ans++;
        if (columns[y].rbegin()->first == rows[columns[y].rbegin()->second].rbegin()->first && columns[y].rbegin()->second != x)
            ans++;
        cout << ans << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> q)
        solve();

}