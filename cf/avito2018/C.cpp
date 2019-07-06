#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <string>
#include <cassert>

using namespace std;
using ull = unsigned long long;
//------------------------------------------------------------------------------

const ull mod = 998244353;

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    ull n, m, k;
    cin >> n >> m >> k;
    vector<vector<ull>> prefix(n + 1, vector<ull>(k + 1));
    for (int i = 1; i <= n; i++){
        prefix[i][0] = i;
        prefix[i][0] %= mod;
        for (int j = 1; j <= k; j++){
            prefix[i][j] = prefix[i - 1][j];
            prefix[i][j] += prefix[i - 1][j - 1];
            prefix[i][j] %= mod;
        }
    }
    ull kek = m;
    for (int i = 0; i < k; i++){
        kek *= (m - 1);
        kek %= mod;
    }
    cout << (((prefix[n][k] +mod -prefix[n - 1][k]) % mod)* kek) % mod << '\n';
}
