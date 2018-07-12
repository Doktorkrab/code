#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    for (int i = 0;i < m; i++){
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        --l, --r;
        int ans = 0;
        for (int j = l; j <= r; j++){
            // cout << arr[j] << '\n';
            // cerr << j << '\n';
            if (arr[j] <= b && arr[j] >= a) ans++;
        }
        cout << ans << '\n';
    }

}