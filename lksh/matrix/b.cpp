#include <bits/stdc++.h>
using namespace std;
using ll = unsigned int long long;
vector<vector<unsigned int>> A;
vector<vector<unsigned int>> mul(vector<vector<unsigned int>> const& A, vector<vector<unsigned int>> const& B, ll module){
    unsigned int n = A.size(), m = B[0].size();
    vector<vector<unsigned int>> ret(n, vector<unsigned int>(m));
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int k = 0; k < (unsigned int) B.size(); k++){
            for (unsigned int j = 0; j < m; j++){
                ret[i][j] += (A[i][k] * B[k][j]) % module;
                ret[i][j] %= module;
            }
        }
    }
    return ret;
}
vector<vector<unsigned int>> I;
vector<vector<unsigned int>> pow(vector<vector<unsigned int>>& A, ll power, ll module){
    auto res = I;
    while (power) {
        if (power & 1)
            res = mul(res, A, module);
        A = mul(A, A, module);
        power >>= 1;
    }
    return res;
}
int main(){
    freopen("mpow.in", "r", stdin);
    freopen("mpow.out", "w", stdout);
    ll n, power, module;
    cin >> n >> power >> module;
    A.assign(n, vector<unsigned int>(n));
    I.assign(n, vector<unsigned int>(n));
    for (unsigned int i = 0; i < n; i++) I[i][i] = 1;
    for (unsigned int i = 0; i < n; i++) for (unsigned int j = 0; j < n; j++) cin >> A[i][j];
    auto ans = pow(A, power, module);
    for (auto i : ans){
        for (unsigned int j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
}