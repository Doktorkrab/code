#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> arr;
void print(){
    for (auto i : arr){
        for (auto j : i){
            cout << j;
        }
        cout << '\n';
    }
    exit(0);
}
int main(){
    freopen("cafe.in", "r", stdin);
    freopen("cafe.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 1){
        vector<char> arr(m, '.');
        for (int i = 1; i < m; i += 3){
            arr[i - 1] = 'h';
            arr[i] = 'T';
            --k;
            if (!k) break;
            if (i + 1 < m) {
                arr[i + 1] = 'h';
                --k;
                if (!k) break;
            }
        }
        if (!k) for (auto c : arr) cout << c;
        else cout << "Impossible";
        cout << '\n';
        return 0;
    }
    if (m == 1){
        vector<vector<char>> arr(n, vector<char>(1, '.'));
        for (int i = 1; i < n; i += 3){
            arr[i - 1][0] = 'h';
            arr[i][0] = 'T';
            --k;
            if (!k) break;
            if (i + 1 < n) {
                arr[i + 1][0] = 'h';
                --k;
                if (!k) break;
            }
        }
        if (!k) for (int i = 0; i < n; i++) cout << arr[i][0] << '\n';
        else cout << "Impossible\n";
        return 0;
    }
    arr.assign(n, vector<char>(m, '.'));
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            arr[i][j] = 'T';
            for (int i_shift = -1; i_shift <= 1; i_shift++){
                for (int j_shift = -1; j_shift <= 1; j_shift++){
                    if (!(i + i_shift < n && i + i_shift >= 0 && j + j_shift < m && j + j_shift >= 0)) continue;
                    if (arr[i + i_shift][j + j_shift] != '.') continue;
                        --k;

                    arr[i + i_shift][j + j_shift] = 'h';
                    if (k == 0) print();
                }
            }
            if (j + 3 < m){
                j += 2;
            }
            else j++;
        }
        if (i + 3 < n){
            i += 2;
        }
        else i++;
    }
//    print();
    cout << "Impossible\n";
}