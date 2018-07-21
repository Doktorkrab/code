#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int64_t> arr(n);
    for (int64_t& i : arr) cin >> i;
    for (int gg = 0; gg < m; gg++){
        char q;
        int l, r, x;
        cin >> q >> l >> r >> x;
        --l, --r;
        if (q == '?'){
            string ans = "NO\n";
            for (int i = l; i <= r; i++){
                if (arr[i] == x){
                    ans = "YES\n";
                    break;
                }
            }
            cout << ans;
        }
        else{
            for (int i = l; i <= r; i++){
                arr[i] += x;
            }
        }
    }
}