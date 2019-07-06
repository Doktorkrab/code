#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mines.in", "r", stdin);
    freopen("mines.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m)), is(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (!arr[i][j]){
                for (int ii = -1; ii <= 1; ii++){
                    for (int jj = -1; jj <= 1; jj++){
                        if (i + ii < n && i + ii >= 0 && j + jj < m && j + jj >= 0){
                            is[i + ii][j + jj] = 1;
                        }
                    }
                }
            }
        }
    }
    vector<vector<char>> arr1(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!is[i][j] && arr[i][j]) arr1[i][j] = '*';
            else if (!arr[i][j]) arr1[i][j] = '.';
            else arr1[i][j] = '0';
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (!is[i][j] || !arr[i][j]) continue;
            for (int ii = -1; ii <= 1; ii++) {
                for (int jj = -1; jj <= 1; jj++) {
                    if (i + ii < n && i + ii >= 0 && j + jj < m && j + jj >= 0 && arr1[i + ii][j + jj] == '*')
                        arr1[i][j]++;
                }
            }
            if (arr[i][j] && arr1[i][j] == '0'){
                cout << "No solution\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cout << arr1[i][j];
        cout << '\n';
    }
    return 0;
}