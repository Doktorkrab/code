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
#include <climits>

using namespace std;
#define int int64_t
int n;

inline void init(){

}
string s;
inline void solve(){
    __int128_t v = 1, u = 1;
    int power = 0;
    for (char c : s){
        if (c == '1'){
            v *= 2;
            power++;
        }
        else if (c == '2'){
            v = v * 2 + 1;
            power++;
        }
        else if (c == 'U'){
            v = max((__int128_t) 1, v / 2);
            power--;
        }
        else if (c == 'L')
            v--;
        else
            v++;
    }
    int power1 = 0;
    cin >> s;
    for (char c : s)
        if (c == '1'){
            u *= 2;
            power1++;
        }
        else if (c == '2'){
            u = u * 2 + 1;
            power1++;
        }
        else if (c == 'U'){
            u = max((__int128_t) 1, u / 2);
            power1--;
        }
        else if (c == 'L')
            u--;
        else
            u++;
    int ans = 0;
    while (power < power1){
        power1--;
        u /= 2;
        ans++;
    }
    while (power1 < power){
        power--;
        v /= 2;
        ans++;
    }
    int64_t right_ans = 2 * power;
    //cerr << v << ' ' << u << '\n';
    //cerr << ans << '\n';
    __int128_t kek = 101;
    while (power >= 0){
        if ((v < u ? u - v : v - u) > kek){
            u /= 2;
            v /= 2;
            ans += 2;
            if (power == 0)
                break;
            power--;
            continue;
        }
        right_ans = min((int64_t)(ans + (v < u ? u - v : v - u)), right_ans);
        //cerr << ans + (v < u ? u - v : v - u) << ' ' << right_ans << '\n';
        ans += 2;
        if (power == 0)
            break;
        power--;
        u /= 2;
        v /= 2;
       //cerr << power << '\n';
    }

    cout << right_ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
                freopen("board.in", "r", stdin);
                freopen("board.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}
