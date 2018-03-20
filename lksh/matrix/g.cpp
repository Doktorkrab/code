#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

vector<vector<unsigned int>> mul(vector<vector<unsigned int>> const& A, vector<vector<unsigned int>> const& B, int module){
    unsigned int n = A.size(), m = B[0].size();
    vector<vector<unsigned int>> ret(n, vector<unsigned int>(m));
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int k = 0; k < (unsigned int) B.size(); k++){
            for (unsigned int j = 0; j < m; j++){
                ret[i][j] += ((long long) A[i][k] * B[k][j]) % module;
                ret[i][j] %= module;
            }
        }
    }
    return ret;
}


vector<vector<unsigned int>> I(10, vector<unsigned int>(10));
vector<vector<unsigned int>> pow(vector<vector<unsigned int>>& A, int power, int module){
    auto res = I;
    while (power) {
        if (power & 1)
            res = mul(res, A, module);
        A = mul(A, A, module);
        power >>= 1;
    }
    return res;
}


vector<vector<unsigned int>> matrix_dp(10, vector<unsigned int>(10));
int main(){
    freopen("smooth.in", "r", stdin);
    freopen("smooth.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++) I[i][i] = 1;
    vector<vector<unsigned int>> ans(10, vector<unsigned int>(1));
    for (int i = 0; i < 10; i++){
        matrix_dp[i][max(0, i - 1)] = 1;
        matrix_dp[i][i] = 1;
        matrix_dp[i][min(i + 1, 9)] = 1;
        ans[i][0] = (i ? 1 : 0);
    }
    matrix_dp = pow(matrix_dp, n - 1, MOD);
    ans = mul(matrix_dp, ans, MOD);
    int ans1 = 0;
    for (int i = 0; i < 10; i++){
        ans1 += ans[i][0];
        ans1 %= MOD;
    }
    cout << '\n' << ans1 << '\n';
}