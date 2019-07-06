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

int n, x;
const int MAXN = 1e9;
const int S = 1e4;
const int MAX_SQRT = sqrt(MAXN) + 5;
bool nprime[MAX_SQRT];
int primes[MAX_SQRT];
bool bl[MAX_SQRT];
int cnt;
inline void init(){
	cnt = 0;
}
// 23456789
// 00000000
inline void solve(){
	init();
    int hash = 0;
    int nsqrt = sqrt(n);
    for (int i = 2; i <= MAX_SQRT; i++){
    	if (nprime[i])
    		continue;
    	primes[cnt++] = i;
    	for (int j = i * i; j <= nsqrt; j += i)
    		nprime[j] = 1;
    }
    for (int k = 0, maxk = n / S; k <= maxk; k++){
    	memset(bl, 0, sizeof bl);
    	int start = k * S;
    	for (int i = 0; i < cnt; ++i){
    		int start_idx = (start + primes[i] - 1) / primes[i];
    		int j = max(start_idx, 2) * primes[i] - start;
    		for (; j < S; j += primes[i]){
    			bl[j] = true;
    		}
    	}
    	if (k == 0){
    		bl[0] = bl[1] = true;
    	}
    	for (int i = 0; i < S && start + i <= n; ++i){
    		if (!bl[i]){
    			hash = hash * x + i + start;
    		}
    	}
    }
    cout << hash << '\n';
}

int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> x)
        solve();
}