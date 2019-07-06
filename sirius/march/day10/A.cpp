#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;
#define int int64_t
const int MAXN = 3e5 +7;
const int INF = 1e9;
int n;
int arr[MAXN];
int dp[MAXN];
int p[MAXN];
int last[MAXN];
bool is_last[MAXN];
inline void init(){
    fill(dp, dp + MAXN, INF);
    memset(p, -1, sizeof(int) * MAXN);
    memset(last, -1, sizeof(int) * MAXN);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++){
            cin >> arr[i];
            if (last[arr[i]] != -1)
                is_last[last[arr[i]]] = 0;
            is_last[i] = 1;
            last[arr[i]] = i;

    }
    memset(last, -1, sizeof(int) * MAXN);
    set<pair<int, int>> enter;
    dp[0] = 0;
    if (!is_last[0]){
        enter.insert({0, 0});
    }
    last[arr[0]] = 0;
    for (int i = 1; i < n; i++){
        if (enter.empty())
            break;
        // cerr << enter.begin()->first + 1 << ' ' << enter.begin()->second << '\n';
        dp[i] = enter.begin()->first + 1;
        p[i] = enter.begin()->second;
        if (last[arr[i]] != -1)
            enter.erase({dp[last[arr[i]]], last[arr[i]]});
        if (!is_last[i])
            enter.insert({dp[i], i});
        last[arr[i]] = i;
    }
    if (dp[n - 1] >= INF){
        cout << "0\n";
        return;
    }
    cout << dp[n - 1] << '\n';
    vector<int> ans;
    int now = p[n - 1];
    while (now != -1){
        ans.push_back(now + 1);
        now = p[now];
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
    // cerr << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
        freopen("expedition.in", "r", stdin);
        freopen("expedition.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}