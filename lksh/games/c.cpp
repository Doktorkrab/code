#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define ea(i, v) for (auto i : v)

using ll = long long;
int main(){
    freopen("cruel.in", "r", stdin);
    freopen("cruel.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> prev(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++){
        unordered_set<int> set_;
        for (int j = 0; j < i; j++){
            int left = (j <= 1 ? 0 : j), right = (j >= i - 2 ? 0 : i - j - 1);
            set_.insert(dp[left] ^ dp[right]);
        }
        for (int j = 0; j <= n; j++){
            if (!set_.count(j)) {
                dp[i] = j;
                break;
            }
        }
    }
    if (!dp[n]){
        cout << "Mueller\n";
    }
    else{
        cout << "Schtirlitz\n";
        for (int j = 0; j < n; j++){
            int left = (j <= 1 ? 0 : j), right = (j >= n - 2 ? 0 : n - j - 1);
            // cout << left << ' ' << right << ' ' << (dp[left] ^ dp[right]) << '\n';
            if ((dp[left] ^ dp[right]) == 0) cout << j + 1 << '\n';
        }
    }
}