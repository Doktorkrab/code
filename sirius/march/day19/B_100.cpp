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
const int MAXLOG = 35;
const int MAXN = 1e6 + 7;

int n;
int arr[MAXN], zerone[MAXLOG], onezero[MAXLOG];  
inline void init(){
    memset(arr, 0, sizeof(int) * MAXN);
    memset(zerone, 0, sizeof(int) * MAXLOG);
    memset(onezero, 0, sizeof(int) * MAXLOG);
}
inline int get_ans(){
    int ans = 0;
    for (int power = 31; power >= 0; power--){
        if (onezero[power] && zerone[power])
            return -1;
        if (onezero[power])
            ans |= (1 << power);
    }
    return ans;
}
inline void update(int i, int x = 1){
    if (i < 0 || i + 1 >= n)
        return;
    int gg = 0, hh = 0, was = 0;
    for (int power = 31; power >= 0; power--){
        int bit = (arr[i] >> power) & 1;
        int bit1 = (arr[i + 1] >> power) & 1;
        if (bit < bit1 && gg >= hh && !was)
            zerone[power] += x;
        if (bit > bit1 && gg >= hh && !was){
            onezero[power] += x;
            was = 1;
        }
        gg = (gg << 1) | bit;
        hh = (hh << 1) | bit1;
    }
}
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++){
        update(i);
    }
    cout << get_ans() << '\n';
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        --a;
        update(a, -1);
        update(a - 1, -1);
        arr[a] = b;
        update(a);
        update(a - 1);
        cout << get_ans() << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("B_100.in", "r", stdin);
		freopen("B_100.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
