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

const int MAXN = 2e6 + 7;
int n, k;
int max_x[MAXN], min_x[MAXN], sum[MAXN];
inline void init(){
    memset(max_x, -1, sizeof(int) * MAXN);
    fill(min_x, min_x + MAXN, MAXN + 1);
}
void recalc(int y1, int y2, int x){
    for (int i = min(y1, y2); i < max(y1, y2); i++){
        max_x[i] = max(max_x[i], x);
        min_x[i] = min(min_x[i], x);
    }
}
inline void solve(){
    init();
    int x_start, y_start;
    cin >> x_start >> y_start;
    int x_prev = x_start, y_prev = y_start;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        recalc(y, y_prev, x);
        x_prev = x, y_prev = y;
    }
    recalc(y_prev, y_start, x_start);
    int pos = 0;
    for (int i = 0; i < MAXN; i++){
        if (min_x[i] > max_x[i])
            continue;
        // cerr << min_x[i] << ' ' << max_x[i] << '\n';
        int lft = min_x[i] + k - i % k;
        int rgt = max_x[i] + k - i % k;
        sum[k - lft % k]--;
        sum[k - (rgt + k - 1) % k]++;
        lft /= k;
        rgt = (rgt + k - 1) / k;
        if (lft < rgt)
            pos += rgt - lft;
    }
    int mnpos = 0;
    for (int i = 1; i < MAXN; i++){
        sum[i] += sum[i - 1];
        if (sum[mnpos] > sum[i])
            mnpos = i;
    }
    // cerr << pos << '\n';
    cout << pos + sum[mnpos] << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#else
        freopen("monument.in", "r", stdin);
        freopen("monument.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k)
        solve();

}