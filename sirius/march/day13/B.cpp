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
#define FMA 9e6
#ifdef FMA
    int alloc_p = 0;
    char alloc[(int) FMA];
    inline void* operator new(size_t n){
        char* res = alloc + alloc_p;
        alloc_p += n;
        assert(alloc_p <= (int) FMA);
        return (void *) res;
    }
    inline void operator delete(void*) noexcept {}
#endif
const int MAXN = 3e3 + 7;
int n;
int arr[MAXN];
int kek[MAXN][MAXN];
int cnt = 0;
inline void init(){
    cnt = 0;
    memset(arr, 0, sizeof(int) * MAXN);
}

int query_men(int l, int r){
    assert(cnt < 36000);
    assert(l < r);
    cout << "? " << l + 1 << ' ' << r << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
inline void solve(){
    init();
    arr[0] = 1;
    int nxt = 2;
    kek[0][1] = 1;
    if (n != 1 && query_men(0, 2) == 2){
        arr[1] = 2;
        nxt++;
        kek[0][2] = 2;
        kek[1][2] = 1;
    }
    else{
        arr[1] = 1;
        kek[0][2] = 1;
        kek[1][2] = 1;
    }
    for (int i = 2; i < n; i++){
        int l = -1, r = i;
        while (r - l > 1){
            int m = (l + r) / 2;
            // cerr << m << "!\n";
            // cerr << m << ' ' << l << ' ' << r << "\n";
            int tmp = query_men(m, i + 1);
            // cerr << kek[m][i] << ' ' << tmp << '\n';
            if (kek[m][i] < tmp)
                r = m;
            else
                l = m;
        }
        // cerr << l << ' ' << r << '\n';

        if (l != -1){
            arr[i] = arr[l];
        }
        else
            arr[i] = nxt++;
        int was = 0;
        for (int j = i - 1; j >= 0; j--){
            if (arr[j] == arr[i])
                was = 1;
            // cerr << j << ' ' << i << ' ' << kek[j][i] << " " << !was << '\n';
            kek[j][i + 1] = kek[j][i] + !was;
        }
        kek[i][i + 1] = 1;
    }
    cout << "Ready!" << endl;
    cout << kek[0][n] << endl;
    for (int i = 0;i < n; i++){
        cout << arr[i];
        if (i != n - 1)
            cout << ' ';
    }
    cout << endl;
    cout.flush();
}


int main(){
	// #ifdef LOCAL
	// 	freopen("B.in", "r", stdin);
	// 	freopen("B.out", "w", stdout);
	// #endif
	
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    // while (cin >> n)
    cin >> n;
        solve();

}
