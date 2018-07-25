#include <bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        --l, --r;
        int64_t ans = 0;
        for (int i = l; i <= r; i++){
            for (int j = i - 1; j >= l; j--){
                ans += arr[j] > arr[i];
            }
        }
        cout << ans << '\n';
    }
}