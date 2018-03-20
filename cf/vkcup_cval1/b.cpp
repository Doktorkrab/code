#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sqr(x) 1LL * x * x

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Solver{
    int n, k;
    vector<int> left, ans, links;
    void solve(){
        for (int i = 0; i < n; i++){
            if (links[i] == -1){
                ans[i] += min(i, k);
                ans[i] += min(n - i - 1, k);
                left[i] += min(i, k);
                continue;
            }
            ans[i] += min(i - links[i] - 1, k);
            ans[i] += min(n - i - 1, k);
            ans[i] += left[links[i]] + max(min((i - k) - links[i] - 1, k), 0);
            left[i] += min(i - links[i] - 1, k) + left[links[i]] + max(min((i - k) - links[i] - 1, k), 0);
        }
    }
    Solver() {
        cin >> n >> k;
        left.assign(n, 1);
        ans.assign(n, 1);
        links.resize(n);
        for (int i = 0;i < n;i++){
            cin >> links[i];
            links[i]--;
        }
        solve();
        for (int i = 0;i < n;i++) cout << ans[i] << ' ';
        cout << '\n';
        // for (int i = 0;i < n;i++) cout << left[i] << ' ';
        // cout << '\n';
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int t = 1;
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    cin >> t;
    #endif
    while(t--) Solver a;
}