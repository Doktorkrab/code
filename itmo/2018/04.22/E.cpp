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

int n;
int cnt[26];
string s;
inline void init(){
    n = s.size();
}
inline bool relax(int r, int len, int c){
    cnt[c]++;
    if (cnt[c] * 2 > len){
        // cerr << r << ' ' << len << '\n';
        cout << r - len + 2 << ' ' << r + 1 << '\n';
        return 1;
    }
    return 0;
}
inline void solve(){
    init();
    for (int len = 2; len <= min(4, n); len++){
        int i = 0;
        memset(cnt, 0, sizeof(int) * 26);
        for (i = 0; i < len; i++){
            cnt[s[i] - 'a']++;
        }
        for (int c = 0; c < 26; c++){
            if (cnt[c] * 2 > len){
                cout << 1 << ' ' << i << '\n';
                return;
            }
        }
        for (; i < n; i++){
            cnt[s[i - len] - 'a']--;
            if (relax(i, len, s[i] - 'a'))
                return;
        }
    }
    cout << "-1 -1\n";
}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}