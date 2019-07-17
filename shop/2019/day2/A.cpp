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

void to_string(const string& s){
    cout << s;
}
template<typename T>
void to_string(const vector<T>& vec){
    cout << '{';
    bool is_first = 1;
    for (const T& i : vec){
        if (!is_first)
            cout << ", ";
        cout << to_string(i);
    }
    cout << '}';
}
void prn(){
    cout << '\n';
}
template<typename T, typename... Ts>
void prn(const T& t, const Ts&... ts){
    cout << to_string(t) << ' ';
    prn(ts...);

}
#define int int64_t
int n, m;
vector<int> lft, rgt;
inline void init(){
    lft.resize(n);
    rgt.resize(m);
}

inline void solve(){
    init();
    for (int& i : lft)
        cin >> i;
    for (int& i : rgt)
        cin >> i;
    sort(lft.begin(), lft.end());
    sort(rgt.begin(), rgt.end());

    if (n > m){
        swap(n, m);
        swap(lft, rgt);
    }
    int l = -1, r = 1e9 + 7;
    while (r - l > 1){
        int M = (l + r) / 2;
        int pnt = 0;
        int good = 1;
        for (int i = 0; i < n; i++){
            while(pnt + 1 < m && pnt - i < m - n && abs(lft[i] - rgt[pnt]) > M)
                pnt++;
            if (abs(lft[i] - rgt[pnt]) > M){
                good = 0;
                break;
            }
            pnt++;
        }
        // cerr << M << ' ' << good << '\n';
        if (good)
            r = M;
        else
            l = M;
    }
    cout << r << '\n';
    // cerr << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}