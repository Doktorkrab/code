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
int n, m;
const int MAXN = 51;
int matrix[MAXN][MAXN];
vector<vector<int>> g, g1;
vector<int> used, used1;;
// int found = 0;
bool find_cycle(const vector<vector<int>>& g, vector<int>& used, int v){
    used[v] = 1;
    for (int u : g[v]){
        if (used[u] == 2)
            continue;
        else if (used[u] == 1)
            return 1;
        else if (find_cycle(g, used, u))
            return 1;
    }
    used[v] = 2;
    return 0;
}
inline void init(){
    g.resize(n, {}), g1.resize(m, {});
    used.resize(n, 0);
    used1.resize(m, 0);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                if (matrix[i][j] < matrix[i][k])
                    g1[k].push_back(j);
            }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (matrix[j][i] < matrix[k][i])
                    g[k].push_back(j);
    bool good = 1;
    // for (int i = 0; i < n; i++)
    //     for (int j : g[i])
    //         cout << i + 1 << "->" << j + 1 << '\n';
    for (int i = 0; i < n; i++)
        if (!used[i])
            good &= !find_cycle(g, used, i);
    // cerr << good << '\n';
    // cerr << "Here\n";
    for (int i = 0; i < m; i++)
        if (!used1[i])
            good &= !find_cycle(g1, used1, i);
    if (good)
        cout << "YES\n";
    else
        cout << "NO\n";
    

}


int main(){
	#ifdef LOCAL
		freopen("L.in", "r", stdin);
		freopen("L.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}