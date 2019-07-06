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
inline void init(){

}

inline void solve(){
    n = s.size();
    int64_t ans = 0;
    for (int i = 0; i < n; i++)
        if ((s[i] - '0') % 2 == 0)
            ans += i + 1;
    cout << ans << '\n';
}


int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> s)
            solve();

}
