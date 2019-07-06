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
int x;
inline void init(){

}

inline int getlog(int x){
    int pw = 0;
    while((1 << pw) < x) pw++;
    pw--;
    return pw;
}
inline void solve(){
    if (x % 3 == 0)
        cout << x / 3 << ' ' << x / 3 << ' ' << x / 3 << '\n';
    else if (x % 3 == 1){
        int a = x / 3;
        int b = x / 3;
        int power = 0;
        while ((1 << power) & b){
            b ^= (1 << power++);
        }
        b ^= (1 << power);
        cout << a << ' ' << b << ' ' << x - a - b << '\n';
    }
    else {
        int a = x / 3;
        int sum = 2;
        int power = 0;
        while (power < 64 && ((1 << getlog(sum)) & a)){
            if ((1 << power) & a){
                a ^= (1 << power);
                sum += 3 * (1 << power);
            }
            cerr << power << ' ' << sum << ' ' << getlog(sum) << '\n';
            power++;
        }
        int b = a;
        a ^= (1 << getlog(sum));
        sum -= (1 << getlog(sum));
        b |= sum / 3;
        a |= sum / 3;
        cout << a << ' ' << b << ' ' << x - a - b << '\n';
    }
}

inline void stupid(){
    int best = -1;
    int a = 0, b = 0, c = 0;
    for (int i = -1e5; x / 3 + i <= 1e5; i++){
        int tmp = x / 3 - i;
        if (tmp >= 0 && x -  tmp - tmp >= 0 && (tmp & tmp & (x - tmp - tmp)) > best){
                best = tmp & tmp & (x - tmp - tmp);
                a = tmp;
                b = tmp;
                c = x - tmp - tmp;
            }
    }
    cout << a << ' ' << b << ' ' << c << ' ' << x / 3 << ' ' << x << '\n'; 
}
int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#else
                freopen("grants.in", "r", stdin);
                freopen("grants.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    x = 0;
    for (x = 0; x <= 150; x++)
        //solve();
        stupid();

}
