#include <bits/stdc++.h>


using namespace std;

vector<vector<int>> used;
vector<vector<int>> fld;
vector<pair<int, int>> shift = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m;
bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y){
    used[x][y] = 1;
    for (auto sh : shift){
        if (!check(x + sh.first, y + sh.second)) continue;
        if (used[x + sh.first][y + sh.second] || !fld[x + sh.first][y + sh.second]) continue;
        dfs(x + sh.first, y + sh.second);
    }
}
int main(){
    cin >> n >> m;
    fld.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> fld[i][j];
        }
    }
    used.assign(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i< n;i++){
        for (int j = 0; j < m;j++){
            if (fld[i][j] && !used[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';

}