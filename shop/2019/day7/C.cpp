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
int n, m;
const int MAXN = 1e3 + 7;
const int MAXM = 55;
int fld[MAXN][MAXM];
int kek[MAXM];
int p[MAXN * MAXM], sz[MAXN * MAXM];
int get(int v){
    return (p[v] == v ? v : (p[v] = get(p[v])));
}
int comps = 0;
void merge(int a, int b){
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    if (sz[a] > sz[b])
        swap(a, b);
    p[a] = b;
    sz[b] += a;
    comps--;

}
inline void solve(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char c;
            cin >> c;
            fld[i][j] = c - '0';
        }

    int ans = 0;
    for (int i = 0; i < n; i++){
        memset(kek, 0, sizeof(int) * MAXM);
        int nxt = 1;
        comps = 0;
        for (int j = i; j < n; j++){
            for (int k = 0; k < m; k++){
                if (!kek[k] && fld[j][k]){
                    p[nxt] = nxt;
                    sz[nxt] = 1;
                    kek[k] = nxt++;
                    comps++;
                }
                else if (!fld[j][k])
                    kek[k] = 0;
            }
            for (int k = 0; k < m - 1; k++){
                if (kek[k] != 0 && kek[k + 1] != 0)
                    merge(kek[k], kek[k + 1]);
            }
            ans += comps;
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
    while (cin >> n >> m)
        solve();

}