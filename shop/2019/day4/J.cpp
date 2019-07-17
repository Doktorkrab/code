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
int n, d;
int best, who;
inline void init(){
    best = 0;
    who = 2;
}
void get_ans(int x){
    if (x < d || x < 2)
        return;
    int tmp = n, ans = 0;
    while (tmp > 0){
        if (tmp % x != d)
            break;
        ans++;
        tmp /= x;
    }
    if (best < ans || (best == ans && who > x)){
        best = ans;
        who = x;
    }
}
inline void solve(){
    init();
    if (n == 0 && d == 0){
        cout << "2 1" << '\n';
        return;
    }
    if (n == 0 || n < d){
        cout << "2 0\n";
        return;
    }
    for (int i = 2; i <= 1e7; i++){
        get_ans(i);
        get_ans((n - d) / i);
    }
    get_ans(n - d);
    cout << who << ' ' << best << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("J.in", "r", stdin);
		freopen("J.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> d)
        solve();

}