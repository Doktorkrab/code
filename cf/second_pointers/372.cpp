#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<bool> used(n);
    for (int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    // for (auto u : arr) cout << u << ' ';
    // cout << '\n';
    int r = n - 1, ans = 0;
    for (int l = n - 1;l >= 0 && r >= 0;l--){
        if (used[l]) continue;
        while(r >= 0 && 2 * arr[r] > arr[l]) r--;
        if (r >= 0){
            ans++;
            used[r--] = 1;
        }
    }
    cout << n - ans << '\n';
}