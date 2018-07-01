#include <bits/stdc++.h>

using namespace std;

vector<string> fld;
vector<pair<int, int>> shift = {{-1, 0}, {1, 0}, {0 ,1}, {0, -1}};
string need;
int k;
int n, m;

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(int pos, int x, int y){
    if (pos == k - 1){
        cout << "YES\n";
        exit(0);
    }
    for (auto sh : shift){
        int x1 = sh.first, y1 = sh.second;
        if (!check(x + x1, y + y1)) continue;
        if (fld[x + x1][y + y1] != need[pos + 1]) continue;
        dfs(pos + 1, x + x1, y + y1);
    }
}
int main(){
    cin >> n >> m;
    fld.resize(n);
    for (int i = 0; i < n;i++){
        cin >> fld[i];
    }
    cin >> k;
    cin >> need;
    for (int i = 0;i < n;i++){
        for (int j = 0; j < m;j++){
            if (fld[i][j] != need[0]) continue;
            dfs(0, i, j);
        }
    }
    cout << "NO\n";
}