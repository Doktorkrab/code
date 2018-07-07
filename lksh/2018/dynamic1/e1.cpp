#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

// -*-*-* All variables *-*-*-
vector<vector<string>> dp;
deque<pair<int, int>> q;
int n;
// -*-*-* All functions *-*-*-

void init() {
    dp.assign(n + 1, vector<string>(n + 1, "A"));
    q.clear();
    q.push_back({0, 0});
}

void solve() {
    cin >> n;
    init();
    dp[0][0] = "";
    while (!q.empty()) {
        auto top = q.front();
        q.pop_front();
        int s = top.first, m = top.second;
        // cerr << s << ' ' << m << ' ' << dp[s][m] << '\n';
        for (int i = 0; i <= 9; i++) {
            int ns = s + i;
            int nm = (m * 10 + i + n) % n;
            if (ns > n)
                continue;
            if (dp[ns][nm] == "A") {
                dp[ns][nm] = dp[s][m] + to_string(i);
                q.push_back({ns, nm});
            }
        }
    }
    cout << dp[n][0] << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "E";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "number";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
#endif
    while (t--) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}