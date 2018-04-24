#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> dp;
vector<ll> happy;
int n, k;


void prep() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}


ll lazy(int pos, int towers) {
    if (k > n + pos + towers || n - pos > k) return -1;
    if (pos == 0) return 0;
    if (dp[pos][towers] != -2) return dp[pos][towers];
    for (int i = pos; i >= 1; i--) {
        ll tmp = lazy(pos - i, towers + 1);
        if (tmp == -1) continue;
        dp[pos][towers] = max(dp[pos][towers], tmp + happy[i]);
    }
    dp[pos][towers] = max(1LL * dp[pos][towers], -1LL);
    return dp[pos][towers];
}


void run() {
    cin >> n >> k;


    dp.assign(n + 1UL, vector<ll>(n + 1UL, -2));
    happy.resize(n + 1UL);
    for (int i = 1; i <= n; i++) {
        cin >> happy[i];
    }
    ll ans = lazy(n, 0);
    if (ans == -1) cout << "Impossible\n";
    else cout << ans << '\n';
}


int main() {
    string FN = "pancakes";
    assert(freopen((FN + ".in").c_str(), "r", stdin));
    freopen((FN + ".out").c_str(), "w", stdout);


    int t = 1;
    prep();


// #ifdef LOCAL
//     cin >> t;
// #endif
    while (t--) run();
// #ifdef LOCAL
//     cerr << "Elapsed: " << (clock() * 1.) / CLOCKS_PER_SEC << '\n';
// #endif

    return 0;
}