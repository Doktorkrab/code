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

int n, m;
const int MAXN = 1e4 + 7;
int a[MAXN], x[MAXN];
int b[MAXN], y[MAXN];
bool marked[MAXN];
inline void init(){

}
inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> y[i];
    int ll = -1, lr = -1, rl = -1, rr = -1;
    int s = 0;
    for (int i = 0; i < n; i++){
        memset(marked, 0, MAXN);
        int sn = 0;
        for (int j = i; j < n; j++){
            sn += x[j];
            marked[a[j]] = 1;
            int prev = -1, ssn = 0, tl = -1, tr = -1, tmp_s = 0;
            for (int k = 0; k < m; k++){
                if (marked[b[k]]){
                    if (tmp_s > ssn){
                        tl = prev;
                        tr = k - 1;
                        ssn = tmp_s;
                    }
                    prev = -1;
                    tmp_s = 0;
                    continue;
                }
                if (prev == -1)
                    prev = k;
                tmp_s += y[k];
            }
            if (tmp_s > ssn){
                tl = prev;
                tr = m - 1;
                ssn = tmp_s;
            }
            if (sn + ssn > s){
	   	ll = i, lr = j;
                rl = tl;
                rr = tr;
                s = sn + ssn;
            }
        }
    }
    int gg = 0;
    for (int i = 0; i < m; i++)
        gg += y[i];
    if (s < gg){
        s = gg;
        ll = lr = -1;
        rl = 0, rr = m - 1;
    }
    cout << s << '\n' << ll + 1 << ' ' << lr + 1 << '\n' << rl + 1 << ' ' << rr + 1 << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
