#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define ea(i, v) for (auto i : v)

using ll = long long;


vector<vector<int>> dp(501, vector<int>(101, INT_MAX));


int recurse(int pos, int max_){
    if (pos == 0){
        return 0;
    }
    if (dp[pos][max_] != INT_MAX) return dp[pos][max_];
    rep(i, max_){
        if (recurse(pos - i - 1, i + 1) == 0){
            return dp[pos][max_] = i + 1;
        }
    }
    return dp[pos][max_] = 0;
}


int main(){
    freopen("sweets.in", "r", stdin);
    freopen("sweets.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    cout << recurse(n, k) << '\n';
}