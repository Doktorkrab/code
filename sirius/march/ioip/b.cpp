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

const int MAXN = 1e5 + 7;
int n, m, w;
int a[MAXN], b[MAXN];

inline bool read(){
    if (!(cin >> w >> n >> m))
        return 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    return 1;
}
inline void init(){

}

inline void solven2(){
    int ans = 1e9;
    for (int w1 = 1; w1 < w; w1++){
        int l = 0;
        int cnt = 1;
        int good = 1;
        for (int i = 0; i < n; i++){
            if (a[i] > w1){
                good = 0;
                break;
            }
            if (l + a[i] > w1){
                cnt++;
                l = 0;
            }
            l += a[i] + 1;
        }
        if (!good)
            continue;
        l = 0;
        int cnt1 = 1;
        for (int i = 0; i < m; i++){
            if (b[i] > w - w1){
                good = 0;
                break;
            }
            if (l + b[i] > w - w1){
                cnt1++;
                l = 0;
            }
            l += b[i] + 1;
        }
        if (!good)
            continue;
        cerr << w1 << ' ' << cnt << ' ' << cnt1 << '\n';
        if (ans > max(cnt, cnt1)){
            ans = max(cnt, cnt1);
        }
    }
    cout << ans << '\n';
}

inline int check(int w1, int *a, int sz){
    int cnt = 1;
    int l = 0;
    for (int i = 0; i < sz; i++){
        if (a[i] > w1)
            return (int)1e9;
        if (l + a[i] > w1){
            cnt++;
            l = 0;
        }
        l += a[i] + 1;
    }
    return cnt;
}
inline void solvenlogn(){
    int l = *min_element(a, a + n), r = w - *max_element(b, b + m);
    while (r - l > 1){
        int m1 = (l + r) / 2;
        if (check(m1, a, n) >= check(w - m1, b, m))
            l = m1;
        else
            r = m1;
    }
    cout << min(max(check(l, a, n), check(w - l, b, m)), max(check(r, a, n), check(w - r, b, m))) << '\n';
}
int main(){
	#ifdef LOCAL
		freopen("b.in", "r", stdin);
		freopen("b.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (read())
        solvenlogn();
}
