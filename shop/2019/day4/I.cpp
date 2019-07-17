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
string s;
int cnt[2][26];
inline void init(){
    n = s.size();
}
void odd(){
    for (int i = 0; i < 26; i++){
        if (cnt[0][i] != cnt[1][i]){
            cout << "NO\n";
            return;
        }
    }
    int pnt = 0;
    int pnt1 = n - 1;
    int pnt2 = 0;
    string ans(n, '\0');
    while (pnt < pnt1){
        while (cnt[0][pnt2] == 0)
            pnt2++;
        ans[pnt++] = 'A' + pnt2;
        ans[pnt1--] = 'A' + pnt2;
        cnt[0][pnt2]--;
    }
    cout << ans << '\n';
}
void even(){
    if (n == 3 && s[0] == s[2]){
        cout <<s << '\n';
        return;
    }
    if (n == 3 && s[0] != s[2]){
        cout << "NO\n";
        return;
    }
    int gg = (n / 2) % 2;
    for (int i = 0; i < 26; i++){
        if (cnt[!gg][i] % 2){
            cout << "NO\n";
            return;
        }
    }
    int even = -1;
    for (int i = 0; i < 26; i++){
        if (cnt[gg][i] % 2){
            if (even != -1){
                cout << "NO\n";
                return;
            }
            even = i;
        }
    }
    if (even == -1){
        cout << "NO\n";
    }
    int pnt = 0;
    int pnt1[2];
    pnt1[0] = pnt1[1] = 0;
    string ans(n, '\0');
    cnt[gg][even]--;
    ans[n / 2] = even + 'A';
    while (pnt != n / 2){
        while (cnt[pnt % 2][pnt1[pnt % 2]] == 0)
            pnt1[pnt % 2]++;
        // if (cnt[pnt % 2][pnt])
        ans[n - pnt - 1] = ans[pnt] = pnt1[pnt % 2] + 'A';
        cnt[pnt % 2][pnt1[pnt % 2]] -= 2;
        pnt++;
    }
    cout << ans << '\n';
}
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cnt[i % 2][s[i] - 'A']++;
    if (n % 2 == 0)
        odd();
    else
        even();
}


int main(){
	// #ifdef LOCAL
	// 	freopen("I.in", "r", stdin);
	// 	freopen("I.out", "w", stdout);
	// #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
        solve();

}