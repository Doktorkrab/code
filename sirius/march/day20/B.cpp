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

const int MAXN = 5e4;
int n;
int arr[MAXN];
inline void init(){

}
const int MAXC = 2e5 + 7; 
int t[MAXC];
void update(int i, int x){
    for (; i < MAXC; i = (i | (i + 1)))
        t[i] = min(t[i], x);
}

int getmax(int r){
    int res = MAXC;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res = min(res, t[r]);
    return res;
}
inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        --l;
        fill(t, t + MAXC, MAXC);
        int res = -1;
        int l1 = -2;
        int r1 = -2;
        for (int i = l; i < r; i++){
            int kek = getmax(arr[i] - 1);
            if (res < i - kek){
                res = i - kek;
                l1 = kek;
                r1 = i;
            }
            update(arr[i], i);
        }
        cout << l1 + 1 << ' ' << r1 + 1 << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
