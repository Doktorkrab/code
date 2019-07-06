#include <bits/stdc++.h>


using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, int>> arr(m + 1);
    for (int i = 0; i <= m; i++) {
        arr[i] = {vector<int>(n), i}; }
    for (int i = 0; i < n; i++) {
        cin >> arr[0].first[i];
        for (int j = 1; j <= m; j++) {
            arr[j].first[i] = arr[0].first[i];
        }
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        for (int j = i; j <= m; j++) arr[j].first[l] = r;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i <= m; i++) {
        cout << arr[i].second << ": ";
        for (int j : arr[i].first) cout << j << ' ';
        cout << '\n';
    }
    cout << '\n';

}