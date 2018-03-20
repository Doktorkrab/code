#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> A, B;
vector<vector<int>> mul(vector<vector<int>> const& A, vector<vector<int>> const& B){
    int n = A.size(), m = B[0].size();
    vector<vector<int>> ret(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < (int) B.size(); k++){
                ret[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return ret;
}
int main(){
    freopen("mmul.in", "r", stdin);
    freopen("mmul.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    A.assign(n, vector<int>(m));
    B.assign(m, vector<int>(k));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < k; j++){
            cin >> B[i][j];
        }
    }
    auto ans = mul(A, B);
    for (auto i : ans){
        for (int j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
}