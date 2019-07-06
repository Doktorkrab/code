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
int n, N;
int st[4 * MAXN];
int arr[MAXN];
int k[MAXN];
inline void init(){
    N = 1;
    while (N < n) N <<= 1;
}

int get_sum(int v, int vl, int vr, int l, int r){
    if (vr <= l || r <= vl)
        return 0;
    if (l <= vl && vr <= r)
        return st[v];
    int vm = (vl + vr) / 2;
    return get_sum(v * 2, vl, vm, l, r) + get_sum(v * 2 + 1, vm, vr, l, r);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> arr[N + i];
    for (int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        k[i + 1] = k[i] + x;
    }
    int q;
    cin >> q;
    while (q--){
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        --a;
        if (c == 's')
            cout << get_sum(1, 0, N, a, b) << '\n';
        else {
            int nxt = arr[N + a] + b;
            int l = 0, r = n - a;
            while (r - l > 1){
                int m = (l + r) / 2;
                if (nxt + k[a + m] - k[a] > arr[N + a + m])
                    l = m;
                else
                    r = m;
            }
            
        }
    }
}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}