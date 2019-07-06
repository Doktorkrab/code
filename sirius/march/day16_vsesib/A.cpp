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
const int MAXN = 1e6;
int64_t a, b, n;
int64_t arr[MAXN];
inline void init(){

}

inline void solve(){
    int tmpa = a;
    for (int i = 0; i < n - 2; i++){
        arr[i] = 1;
        a--;
    }
    if (a < 0){
        cout << "-1\n";
        return;
    }
    a -= b;
    if (a < 0){
        cout << "-1\n";
        return;
    }
    if (a & 1)
        arr[0]++;
    arr[n - 2] = a / 2;
    arr[n - 1] = a / 2 + b;
    int mx = -1;
    int mx1 = -2;
    int sm = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] <= 0){
            cout << "-1\n";
            return;
        }
        sm += arr[i];
        if (mx < arr[i]){
            mx1 = mx;
            mx = arr[i];
        }
        else if (mx1 < arr[i])
            mx1 = arr[i];
    }
    if (mx != mx1 + b || sm != tmpa)
        cout << "-1\n";
    else
        for (int i = 0; i < n; i++)
            cout << arr[i] << " \n"[i == n - 1];
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> a >> b >>  n)
        solve();

}
