#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), can(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        --v, --u;
        can[v] = 0;
    }
    int mx = 0;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (can[i]) mx = max(arr[i], mx);
    }
//    cout << mx << '\n';
    cout << sum - mx << '\n';
}