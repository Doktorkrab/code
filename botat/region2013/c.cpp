#include <bits/stdc++.h>
using namespace std;
struct Node{
    int l, r, c;
    bool operator<(Node& ot){
        return tie(l, r, c) < tie(ot.l, ot.r, ot.c);
    }
};
vector<Node> dp;
int bin_search(int l, int x){
    int r = dp.size() - 1;
    cerr << "SIZE " << r << ' ' << l << '\n';
    while (r - l > 1){
        int m = (l + r) / 2;
        cerr << m << ' ' << dp[m].l << ' ' << x << '\n';
        if (dp[m].l < x){
            l = m;
        }
        else{
            r = m;
        }
    }
    return r;
}
int main(){
    int n;
    cin >> n;
    dp.resize(n);
    for (int i = 0;i < n;i++){
        int l, r, c;
        cin >> l >> r >> c;
        dp[i] = {l, r, c};
    }
    sort(dp.begin(), dp.end());
    vector<vector<int>> dp1(2, vector<int>(n));
    for (int i = n - 1; i >= 0; i--){
        if (i == n - 1){
            dp1[0][i] = 0;
            dp1[1][i] = dp[i].c;
            continue;
        }
        dp1[0][i] = max(dp1[1][i + 1], dp1[0][i + 1]);
        dp1[1][i] = dp[i].c;
        int pos = bin_search(i + 1, dp[i].r);
        cerr << pos << '\n';
        if (pos == n) continue;
        dp1[1][i] += max(dp1[0][pos], dp1[1][pos]);
    }
    cout << max(dp1[1][0], dp1[0][0]) << '\n';
}