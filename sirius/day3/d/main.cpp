#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<int> strings(n, INT_MAX), rows(m, INT_MIN);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            strings[i] = min(strings[i], arr[i][j]);
            rows[j] = max(rows[j], arr[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strings[i] == arr[i][j] && rows[j] == arr[i][j]) ans++;
        }
    }
    cout << ans << '\n';
}