#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> fld(n, vector<bool>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0;j < m;j++){
            char kek;
            cin >> kek;
            fld[i][j] = kek == '*';
        }
    }
    // cerr << "!!!!";
    long long ans = 0;
    if (k == 1){
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (!fld[i][j]) ans++;
            }
        }
        cout << ans << '\n';
    }
    else{
        long long ans = 0;
        for (int i = 0;i < n;i++){
            int j, cur = 0;
            if (m < k) break;
            for (j = 0;j < min(k, m);j++){
                cur += fld[i][j];
            }
            // cout << cur << '\n';
            --j;
            // cerr << "!!!!";
            for (;j < m;j++){
                // cerr << i << ' ' << ' ' << j << ' ' <<cur << ' ' << ans << '\n';
                ans += !cur;
                cur -= fld[i][j - k + 1];
                if (j + 1 < m){
                    cur += fld[i][j + 1];
                }
            }
        }
        // cout << ans << '\n';
        // cerr << "!!!!";
        for (int i = 0;i < m;i++){
            int j, cur = 0;
            if (n < k) break;
            for (j = 0;j < min(k, n);j++){
                cur += fld[j][i];
            }
            --j;
            for (;j < n;j++){
                ans += !cur;
                // cerr << j - k + 1 << '\n';
                cur -= fld[j - k + 1][i];
                if (j + 1 < n){
                    cur += fld[j + 1][i];
                }
            }
        }
        // cerr << "!!!!";
        cout << ans << '\n';
    }
}