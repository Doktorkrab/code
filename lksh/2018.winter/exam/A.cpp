#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

int64_t a, b;

inline void init(){

}
const int MOD = 1e9 + 7;

vector<vector<unsigned int>> mul(vector<vector<unsigned int>> const& A, vector<vector<unsigned int>> const& B){
    unsigned int n = A.size(), m = B[0].size();
    vector<vector<unsigned int>> ret(n, vector<unsigned int>(m));
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int k = 0; k < (unsigned int) B.size(); k++){
            for (unsigned int j = 0; j < m; j++){
                ret[i][j] += ((long long) A[i][k] * B[k][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}
using ll = int64_t;
vector<vector<unsigned int>> I;
vector<vector<unsigned int>> pow(vector<vector<unsigned int>>& A, ll power){
    auto res = I;
    while (power) {
        if (power & 1)
            res = mul(res, A);
        A = mul(A, A);
        power >>= 1;
    }
    return res;
}
int fib(int n){
	 vector<vector<unsigned int>> matrix = {{1, 1}, 
	 										{1, 0}};
	 I = {{1, 0}, 
	 	  {0, 1}};
	return pow(matrix, n)[1][0];
}
inline void solve(){
	int64_t c = __gcd(a + 1, b + 1);
	cout << fib(c) << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> b)
        solve();

}