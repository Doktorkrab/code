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
#define int int64_t
using namespace std;
int n, k, r;
const int MAXN = 5e4 + 7, MAXK = 10;
string s;
string ans;
string kek = "ACGT";
int dp[MAXN][MAXK + 2][4];
inline void init(){
    ans.resize(n, 'N');
}
inline int get_i(char c){
    if (c == 'A')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'G')
        return 2;
    return 3;
}
void rec(int pos, int need, int form){
    // cerr << '\n';
    // cerr << pos << ' ' << need << ' ' << form << '\n';
    // for (int j = 1; j <= k; j++)
    //         for (int kk = 0; kk < 4; kk++)
    //             cerr << dp[pos][j][kk] << " \n"[kk == 3];
    //     // cerr << '\n';
    // cerr << '\t' << ans << '\n';
    if (pos == n){
        // reverse(ans.begin(), ans.end());
        cout << ans << '\n';
        return;
    }
    if (s[pos] != 'N'){
        if (pos != 0 && s[pos] < ans[pos - 1])
            form--;
        ans[pos] = s[pos];
        // need -= dp[pos][form][get_i(s[pos])];
        rec(pos + 1, need, form);
        return;
    }
    else if (pos == 0){
        // cerr << "?\n";
        for (int i = 0; i < 4; i++){
            if (dp[pos][form][i] < need)
                need -= dp[pos][form][i];
            else{
                ans[pos] = kek[i];
                rec(pos + 1, need, form);
                break;
            }
        }
    }
    else {
        for (int i = 0; i < get_i(ans[pos - 1]); i++){
            // cerr << "!"<<need << ' ' << dp[pos][form - 1][i] << ' ' << i << '\n';
            if (need > dp[pos][form - 1][i]){
                need -= dp[pos][form - 1][i];
            }
            else {
                ans[pos] = kek[i];
                rec(pos + 1, need, form - 1);
                return;
            }
        }
        for (int i = get_i(ans[pos - 1]); i < 4; i++){
            // cerr << "!"<<need << ' ' << dp[pos][form - 1][i] << ' ' << i << '\n';
            if (need > dp[pos][form][i]){
                need -= dp[pos][form][i];
            }
            else {
                ans[pos] = kek[i];
                rec(pos + 1, need, form);
                return;
            }
        }
    }

}
inline void solve(){
    init();
    // reverse(s.begin(), s.end());
    for (int j = 1; j <= k; j++){
        if (s[n - 1] != 'N'){
            dp[n - 1][j][get_i(s[n - 1])] = 1;
        }
        else {
            for (int i = 0; i < 4; i++)
                dp[n - 1][j][i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--){
        if (s[i] != 'N'){
            int id = get_i(s[i]);
            for (int j = 1; j <= k; j++){
                // dp[i][j][id] = dp[i][j - 1][id];
                if (s[i + 1] != 'N' && s[i + 1] >= s[i]){
                    // cerr << id << ' ' << j << ' ' << get_i(s[i - 1]) << ' ' << dp[i - 1][j][get_i(s[i - 1])] << "!\n";
                    dp[i][j][id] += dp[i + 1][j][get_i(s[i + 1])];
                }
                else if (s[i + 1] != 'N'){
                    // cerr << "rly?" << 
                    dp[i][j][id] += dp[i + 1][j - 1][get_i(s[i + 1])];
                }
                else{
                    for (int kk = 0; kk < id; kk++)
                        dp[i][j][id] += dp[i + 1][j - 1][kk];
                    for (int kk = id; kk < 4; kk++)
                        dp[i][j][id] += dp[i + 1][j][kk];
                }
            }
        }
        else {
            for (int j = 1; j <= k; j++){
                for (int l = 0; l < 4; l++){
                    // dp[i][j][l] = dp[i][j - 1][l];
                    if (s[i + 1] != 'N'){
                        // cerr << i << ' ' << l << ' ' << get_i(s[i + 1]) << ' ' << j << ' ' << dp[i + 1][j - 1][get_i(s[i + 1])] << ' ' << dp[i + 1][j][get_i(s[i + 1])] << '\n';
                        if (l <= get_i(s[i + 1])){
                            // cerr << dp[i + 1][j][get_i(s[i + 1])] << ' ' << i + 1 << ' ' << j << ' ' << get_i(s[i + 1]) << '\n';
                            dp[i][j][l] += dp[i + 1][j][get_i(s[i + 1])];
                        }
                        else
                            dp[i][j][l] += dp[i + 1][j - 1][get_i(s[i + 1])];
                    }
                    else {
                        for (int kk = 0; kk < l; kk++)
                            dp[i][j][l] += dp[i + 1][j - 1][kk];
                        for (int kk = l; kk < 4; kk++)
                            dp[i][j][l] += dp[i + 1][j][kk];
                    }
                }
            }
        }
    }
    rec(0, r, k);
}


int32_t main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k >> r >> s)
        solve();

}