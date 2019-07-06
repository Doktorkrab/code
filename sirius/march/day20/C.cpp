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
vector<pair<int, int>> stack;
string s;
const int MAXN = 1e7 + 7;
int used[MAXN];
inline void init(){
    n = s.size();
    stack.clear();
}

inline void solve(){
    init();
    int on_suf = 0;
    for (int i = 0; i < n; i++)
        on_suf += s[i] != '(';
    int open = 0;
    for (int i = 0; i < n; i++){
        cerr << s[i] << open << ' ' << on_suf << '\n';
        if (s[i] == '(')
            open++;
        else if (s[i] == ')'){
            on_suf--;
            if (open > 0)
                open--;
        }
        else if (open + 1 > on_suf - 1){
                s[i] = ')';
                if (open)
                    open--;
                on_suf--;
        }
        else{
            s[i] = '(';
            open++;
            on_suf--;
        }
    }
    cout << s << '\n';
}
inline void stupid(){
    init();
    vector<int> stack;
    vector<int> ask;
    string ans;
    int best = -1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '?')
            ask.push_back(i);
    for (int mask = 0; mask < (1 << ask.size()); mask++){
        for (int i = 0; i < ask.size(); i++)
            if ((mask >> i) & 1)
                s[ask[i]] = '(';
            else
                s[ask[i]] = ')';
        stack.clear();
        int tmp = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '(')
                stack.push_back(i);
            if (s[i] == ')' && !stack.empty()){
                stack.pop_back();
                tmp++;
            }
        }
        if (tmp > best){
            best = tmp;
            ans = s;
        }
    }
    cout << ans << '\n';
}
int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}
