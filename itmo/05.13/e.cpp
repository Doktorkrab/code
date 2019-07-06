#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (arr.empty() || arr.back() != x)
            arr.push_back(x);
    }
    n = arr.size();
    vector<vector<int>> dp(2, vector<int>(n, 0x3f3f3f3f));
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i < n; i++){
        if (arr[i - 1] < arr[i])
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + 1);
        dp[0][i] = min(dp[0][i], min(dp[0][i - 1], dp[1][i - 1]) + 1);
        if (arr[i - 1] > arr[i])
            dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1]);
        dp[1][i] = min(dp[1][i], min(dp[0][i - 1], dp[1][i - 1]) + 1);
    }
//    for (int i : dp[0])
//        cout << i << ' ';
//    cout << '\n';
//    for (int i : dp[1])
//        cout << i << ' ';
//    cout << '\n';
    cout << min(dp[1][n - 1], dp[0][n - 1]) << '\n';
}