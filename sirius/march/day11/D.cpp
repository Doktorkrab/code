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

int n, k;
const int MAXN = 1005;
int cnt = 0;
int dp[2][MAXN][MAXN];
pair<int, int> p[2][MAXN][MAXN];
inline void init(){
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            fill(dp[i][j], dp[i][j] + k + 1, 0x3f3f3f3f);
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++)
            fill(p[i][j], p[i][j] + k + 1, make_pair(-1, -1));
    }
}

inline void solve(){
    init();
    cnt++;
    string s;
    cin >> s;
    dp[s[0] - '0'][0][1] = 0;
    dp[1 - (s[0] - '0')][0][1] = 1;
    for (int i = 1; i < n; i++){
        for (int kk = 1; kk <= k; kk++){
            int c = s[i] - '0';
            int ac = 1 - c;
            if (dp[c][i - 1][kk] < dp[ac][i - 1][kk - 1]){
                p[c][i][kk] = {c, 0};
                dp[c][i][kk] = dp[c][i - 1][kk];
            }
            else{
                p[c][i][kk] = {ac, -1};
                dp[c][i][kk] = dp[ac][i - 1][kk - 1];
            }
            if (dp[c][i - 1][kk - 1] < dp[c][i][kk]){
                dp[c][i][kk] = dp[c][i - 1][kk - 1];
                p[c][i][kk] = {c, -1};
            }
            if (dp[ac][i - 1][kk] < dp[c][i - 1][kk - 1]){
                p[ac][i][kk] = {ac, 0};
                dp[ac][i][kk] = dp[ac][i - 1][kk] + 1;
            }
            else {
                p[ac][i][kk] = {c, -1};
                dp[ac][i][kk] = dp[c][i - 1][kk - 1] + 1;
            }
            if (dp[ac][i - 1][kk - 1] < dp[ac][i][kk]){
                dp[ac][i][kk] = dp[ac][i - 1][kk - 1] + 1;
                p[ac][i][kk] = {ac, -1};
            }
        }
    }
    int pos = n - 1, pos1 = k;
    int pos2;
    string ans;
    if (dp[0][pos][pos1] < dp[1][pos][pos1]){
        pos2 = 0;
        ans += '0';
    }
    else {
        pos2 = 1;
        ans += '1';
    }
    while (p[pos2][pos][pos1].first != -1){
        ans += p[pos2][pos][pos1].first + '0';
        int tmp = pos2, tmp1 = pos1;
        pos2 = p[tmp][pos][tmp1].first;
        pos1 += p[tmp][pos][tmp1].second;
        pos--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    // cerr << cnt << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#else
        freopen("penguins.in", "r", stdin);
        freopen("penguins.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (cin >> n >> k)
        solve();

}