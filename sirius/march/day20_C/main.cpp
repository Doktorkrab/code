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

const int MAXN = 1e7 + 7;
int n;
string s; // ) - close with open, f - just close
int used[MAXN];
inline void init(){
    n = s.size();
}
inline void solve(){
    init();
    int bal = 0;
    int bal1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')' && bal > 0)
            bal--;
        else if (s[i] == ')')
            s[i] = 'f';
        else
            bal++;
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++){
        if (s[i] == '?'){
            if (bal >= 2) {
                s[i] = ')';
                bal -= 2;
            }
            else
                s[i] = '(';
        }

        if (s[i] == 'f')
            s[i] = ')';
        else if (s[i] == ')')
            bal1++;

        if (s[i] == '?' || s[i] == '('){
            if (bal1 == 0)
                bal--;
            else
                bal1--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}


int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
        solve();

}
