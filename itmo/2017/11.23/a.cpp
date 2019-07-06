#include <bits/stdc++.h>

using namespace std;
using ll = long long;
long long diff_sign(long long a, long long b){
    return a * b < 0;
}
long long lcm(long long a, long long b){
    return a * b;
}
int main(){
    freopen("crystals.in", "r", stdin);
    freopen("crystals.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0;i < n;i++) cin >> arr[i];
    vector<ll> arr1(n);
    for (int i = 0;i < n;i++) {
        cin >> arr1[i];
        arr1[i] -= arr[i];
    }
    for (int i = 0;i < n;i++){
        if (arr1[i] == 0) {
            cout << 1 << '\n' << i + 1 << '\n';
            return 0;
        }
        for (int j = 0;j < n;j++){
            if (i == j) continue;
            if (!diff_sign(arr1[i], arr1[j])) continue;
            ll l = lcm(arr1[i], arr1[j]);
            if (abs(l) >= 1e4) continue;
            cout << abs(l / arr1[j]) + abs(l / arr1[i]) << '\n';
            for (int k = 0;k < abs(l / arr1[i]);k++) cout << i + 1 << ' ';
            for (int k = 0;k < abs(l / arr1[j]);k++) cout << j + 1 << ' ';
            return 0;
        }
    }
    cout << -1;
}