#include <bits/stdc++.h>

using namespace std;
vector<int> comps = {0};
int arr[5][5], used[5][5];
vector<pair<int, int>> shift = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void dfs( int x, int y, int color )
{
    used[x][y] = 1;
    comps[color]++;
    for (auto sh : shift){
        int nx = x + sh.first, ny = y + sh.second;
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
        if (used[nx][ny] || !arr[nx][ny]) continue;
        dfs(nx, ny, color);
    }
}
int main( void )
{
    int color = 1, ans = 0;
    for(int i = 0; i < 5; i++) for (int j = 0; j <  5; j++) {
        char tmp;
        cin >> tmp;
        arr[i][j] = tmp == '#';
//        cout << arr[i][j];
    }
    for (int i = 0;i < 5; i++) for (int j = 0; j < 5; j++) if (!used[i][j] && arr[i][j]){
                comps.push_back(0);
                dfs(i, j, color++);
                ans += (comps[color - 1] == 4);
//                cout << comps[color - 1] << '\n';
    }
    cout << ans << '\n';
}