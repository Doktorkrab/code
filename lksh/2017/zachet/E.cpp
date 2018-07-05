#define _GLIBCXX_DEBUG
/*Ребята, не стоит вскрывать эту тему. 
Вы молодые, шутливые, вам все легко. 
Это не то. Это не Чикатило и даже не архивы спецслужб. 
Сюда лучше не лезть. Серьезно, любой из вас будет жалеть. 
Лучше закройте тему и забудьте, что тут писалось. 
Я вполне понимаю, что данным сообщением вызову дополнительный интерес, но хочу сразу предостеречь пытливых - стоп. 
Остальные просто не найдут.*/
#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1e9 + 7;

vector<vector<unsigned int>> mul(vector<vector<unsigned int>> const& A, vector<vector<unsigned int>> const& B){
    unsigned int n = A.size(), m = B[0].size();
    vector<vector<unsigned int>> ret(n, vector<unsigned int>(m));
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            for (unsigned int k = 0; k < (unsigned int) B.size(); k++){
                ret[i][j] += (A[i][k] * B[k][j]) % MOD;
                ret[i][j] %= MOD; 
            }
        }
    }
    return ret;
}

vector<vector<unsigned int>> pow(vector<vector<unsigned int>> const& A, unsigned int power){
    if (power == 0){
        vector<vector<unsigned int>> matr(A.size(), vector<unsigned int>(A.size()));
        for (unsigned int i = 0; i < (unsigned int) A.size(); i++){
            matr[i][i] = 1;
        }
        return matr;
    }
    if (power == 1){
        return A;
    }
    if (power % 2){
        return mul(A, pow(A, power - 1));
    }
    auto tmp = pow(A, power / 2);
    return mul(tmp, tmp);
}


int main(){
    unsigned int n, k;
    cin >> k >> n;
    vector<vector<unsigned int>> matrix_dp;
    matrix_dp.assign(k + 1, vector<unsigned int>(k + 1));
    matrix_dp[0][1] = 1;
    matrix_dp[1][0] = 1;
     for (unsigned int i = 0; i < k + 1; ++i) {
        if (i >= 1)
        matrix_dp[i][i - 1] = 1;
        if (i + 1 < k + 1)
        matrix_dp[i][i + 1] = 1;
    }
    matrix_dp[k][k - 1] = 1;
    matrix_dp[k - 1][k] = 1;
    vector<vector<unsigned int>> ans(k + 1, vector<unsigned int>(1, 0));
    ans[0][0] = 1;
    ans = mul(pow(matrix_dp, n * 2), ans);
    cout << ans[0][0];
    // cout << '\n';
}