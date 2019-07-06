#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ans(n, vector<int>(m));
    vector<pair<int, pair<int, int>>> arr;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
//            cerr << i << ' ' << j << '\n';
            if (x == 0) continue;
            arr.push_back({x, {i, j}});
        }
    }
    if (arr.size() - 1 > k){
        cout << "Wrong Board\n";
        return 0;
    }
    sort(arr.begin(), arr.end());
    arr.push_back(arr[0]);
//    cerr << arr.size() << '\n';
    for (int i = 0; i < k; i++){
        ans[arr[i].second.first][arr[i].second.second] = i + 1;
//        cerr << arr[i].second.first << ' ' <<arr[i].second.second << ' ' << arr[i + 1].second.first << ' ' << arr[i + 1].second.second << '\n';
        if (!(arr[i].second.first == arr[i + 1].second.first || arr[i].second.second == arr[i + 1].second.second ||
              abs(arr[i].second.first - arr[i + 1].second.first) == abs(arr[i].second.second - arr[i + 1].second.second)) || arr[i].first == arr[i + 1].first) {
            cout << "Wrong Board\n";
            return 0;
        }
    }
    ans[arr[k].second.first][arr[k].second.second] = k + 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}