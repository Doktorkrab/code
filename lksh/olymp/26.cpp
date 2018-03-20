// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
int get(string kek){
    if (kek == "CHEMICAL") return 0;
    if (kek == "THERMAL") return 1;
    if (kek == "MECHANICAL") return 2;
    if (kek == "ELECTRIC") return 3;
    assert(false);
}
int main(){
    int n;
    cin >> n;
    vector<vector<bool>> dp(4, vector<bool>(500000));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[3][0] = 1;
    vector<vector<pair<int, int>>> moves(4);
    for (int i = 0;i < n;i++){
        string a, b;
        cin >> a >> b;
        int t;
        cin >> t;
        // cout << get(a) << ' ' << get(b) << "KEK\n"; 
        moves[get(a)].push_back({get(b), t});
    }
    for (int i = 0;i < 500000;i++){
            if (dp[0][i] != 0)
            for (auto c : moves[0]){
                    // if (c[1] == 3) cout << "!!!!KEK" << '\n';
                    if (i + c.second < 500000)
                    dp[c.first][i + c.second] = 1;
            }
            if (dp[1][i] != 0) 
            for (auto c : moves[1]){
                // if (c[0] == 1){
                    // if (c[1] == 3) cout << "!!!!KEK" << '\n';
                        if (i + c.second < 500000)
                    dp[c.first][i + c.second] = 1;
                // }
            }
            if (dp[2][i] != 0)
            for (auto c : moves[2]){
                    // if (c[1] == 3) cout << "!!!!KEK" << '\n';
                    if (i + c.second < 500000)
                    dp[c.first][i + c.second] = 1;
            }
            if (dp[3][i] != 0)
            for (auto c : moves[3]){
                    // if (c[1] == 3) cout << "!!!!KEK" << '\n';
                    if (i + c.second < 500000)
                    dp[c.first][i + c.second] = 1;
            }
    }
    string need;
    cin >> need;
    int t, i1 = 0;
    cin >> t;
    int minans = t;
    // dp[3][11] = 0;
    for (int i = 0;i < 500000;i++){
        if (dp[get(need)][i]){
            // cout << get(need) << ' ' << i << '\n';
            minans = min(minans, abs(t - i));
        }
    }
    cout << minans << '\n';
}