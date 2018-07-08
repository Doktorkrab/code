#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXM = 3;
#else
const int INF = 1e9;
const int MAXM = 5;
#endif

// -*-*-* All variables *-*-*-

vector<vector<int>> can;
vector<int> dp;
int m, p;
// string n;

// -*-*-* All functions *-*-*-

string to_binary(int x) {
    string res;
    do {
        res += x % 2 + '0';
        x >>= 1;
    } while (x);
    while ((int)res.size() < m)
        res += '0';
    return res;
}
vector<vector<int>> multiply(const vector<vector<int>> &A,
                             const vector<vector<int>> &B) {
    int n = A.size(), m = B[0].size();
    vector<vector<int>> ret(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < (int)B.size(); k++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] += (A[i][k] * B[k][j]) % p;
                ret[i][j] %= p;
            }
        }
    }
    return ret;
}

vector<vector<int>> power(vector<vector<int>> matrix, int x) {
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix.size(), 0));
    for (int i = 0; i < (int)matrix.size(); i++)
        ans[i][i] = 1;
    while (x) {
        if (x & 1) {
            ans = multiply(ans, matrix);
        }
        matrix = multiply(matrix, matrix);
        x >>= 1;
    }
    return ans;
}
vector<vector<int>> power(vector<vector<int>> matrix, string x) {
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < (int)matrix.size(); i++)
        ans[i][i] = 1;
    while (x.size()) {
        int now = x.back() - '0';
        ans = multiply(ans, power(matrix, now));
        matrix = power(matrix, 10);
        x.pop_back();
    }
    return ans;
}
int power(int a, int x) { // for tests
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans *= a;
        }
        a *= a;
        x >>= 1;
        cerr << ans << ' ' << a << ' ' << x << "\n";
    }
    return ans;
}
bool test(int mask, int bit) { return mask & (1 << bit); }

void init() {
    can.assign(1 << m, vector<int>(1 << m, 1));
    for (int mask = 0; mask < (1 << m); mask++) {
        for (int mask1 = 0; mask1 < (1 << m); mask1++) {
            for (int i = 1; i < m; i++) {
                can[mask][mask1] &= (test(mask, i) + test(mask1, i) +
                                     test(mask, i - 1) + test(mask1, i - 1)) % 4 != 0;
            }
        }
    }

    dp.assign((1 << m), 1);
}

void solve() {
    string n;
    cin >> n;
    cin >> m >> p;
    init();
    int i;
    for (i = ((int)n.size()) - 1; i >= 0; i--) {
        if (n[i] != '0') {
            // cerr << n[i] << '\n';
            n[i]--;
            i++;
            break;
        }
    }
    for (; i < (int)n.size(); i++) {
        n[i] = '9';
    }
    // cout << n << '\n';
    vector<vector<int>> ans = power(can, n);
    int64_t ans1 = 0;
    for (auto i : ans) {
        for (int j : i) {
            ans1 += j;
            ans1 %= p;
        }
    }
    cout << ans1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    string taskName = "D";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "";
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