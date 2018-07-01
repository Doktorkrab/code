#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;
vector<vector<int>> placed_tree;
vector<vector<int>> deleted_tree;
vector<int> ans;

void delete_all(int l, int r){
    if (l == r || l == r - 1) return;
    if (deleted_tree[l][r] == -1) return;
    delete_all(deleted_tree[l][r], r);
    delete_all(l, deleted_tree[l][r]);
    ans.push_back(deleted_tree[l][r] + 1);
}

const int DELETE = -2;
void print_ans(int l, int r){
    if (placed_tree[l][r] == -1) return;
    if (placed_tree[l][r] == DELETE){
        delete_all(l, r);
        return;
    }
    print_ans(l, placed_tree[l][r]);
    print_ans(placed_tree[l][r], r);
}

signed main(){
    int n;
    cin >> n;
    vector<vector<int>> can_delete(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, INF));
    placed_tree.assign(n, vector<int>(n, -1));
    deleted_tree.assign(n, vector<int>(n, -1));
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    for (int i = 0; i + 1 < n;i++){
        can_delete[i][i + 1] = 1;
    }

    for (int len = 2; len <= n; len++){
        for (int l = 0; l + len - 1 < n;l++){
            int r = l + len - 1;
            for (int i = l + 1; i < r; i++){
                if ((arr[l] > arr[i] && arr[r] > arr[i]) || (arr[l] < arr[i] && arr[r] < arr[i])){
                    if (!can_delete[l][i] || !can_delete[i][r]) continue;
                    can_delete[l][r] = can_delete[l][i] && can_delete[i][r];
                    deleted_tree[l][r] = i;
                }
            }
        }
    }


    for (int len = 2; len <= n; len++){
        for (int l = 0; l + len - 1 < n; l++){
            int r = l + len - 1;
            if (arr[l] > arr[r]) continue;
            for (int i = l + 1; i < r; i++){
                if (arr[l] <= arr[i] && arr[i] <= arr[r]){
                    if (dp[l][r] > dp[l][i] + dp[i][r]){
                        dp[l][r] = dp[l][i] + dp[i][r];
                        placed_tree[l][r] = i;
                    }
                }
            }
            if (!can_delete[l][r]) continue;
            if (dp[l][r] > r - l - 1){
                dp[l][r] = r - l - 1;
                placed_tree[l][r] = DELETE;
            }
        }
    }

    if (dp[0][n - 1] == INF){
        cout << "-1\n";
        return 0;
    }


    cout << dp[0][n - 1] << '\n';
    print_ans(0, n - 1);
    for (int i : ans) cout << i << '\n';
}