#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int SIZE = 4;
vector<vector<int>> mul(vector<vector<int>> const& A, vector<vector<int>> const& B){
    int n = A.size(), m = B[0].size();
    vector<vector<int>> ret(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < (int) B.size(); k++){
                ret[i][j] += (A[i][k] * B[k][j]) % 2;
                ret[i][j] %= 2; 
            }
        }
    }
    return ret;
}

vector<vector<int>> pow(vector<vector<int>> const& A, int power){
    if (power == 0){
        vector<vector<int>> matr(A.size(), vector<int>(A.size()));
        for (int i = 0; i < (int) A.size(); i++){
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
vector<vector<int>> get_vector_from_mask(int mask){
    vector<vector<int>> ret(4, vector<int>(4));
    for (int i = 3; i >= 0; i--){
        for (int j = 3; j >= 0; j--){
            // cerr << i << ' ' << j << '\n';
            ret[i][j] = (mask & 1) % 2;
            mask >>= 1;
        }
    }
    return ret;
}
int main(){
    freopen("sqroot.in", "r", stdin);
    freopen("sqroot.out", "w", stdout);
    vector<vector<int>> A(4, vector<int>(4));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cin >> A[i][j];
        }
    }
    for (int mask = 0; mask < (1 << 17); mask++){
        vector<vector<int>> B = get_vector_from_mask(mask);
        // B = pow(B, 2);
        if (pow(B, 2) == A){
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    cout << B[i][j] % 2 << ' ';
                }
                cout << '\n';
            }
            return 0;
        }
    }
    cout << "NO SOLUTION\n";
}