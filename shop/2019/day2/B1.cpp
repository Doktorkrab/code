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

int n, m;
const int MAXN = 2e3 + 5;
char arr[MAXN][MAXN];
int h[MAXN][MAXN];
inline void init(){
    for (int i = 0; i < n; i++){
        memset(h[i], 0, MAXN * sizeof(int));
        memset(arr[i], 0, MAXN);
    }
}

inline void solve(){
    // init();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    int64_t ans = 0;
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cerr << h[i][j] << " \n"[j == m - 1];
    for (int j = 0; j < m; j++)
        for (int i = n - 1; i >= 0; i--){
            if (arr[i][j] == '#')
                h[i][j] = 0;
            else if (i == n - 1)
                h[i][j] = 1;
            else
                h[i][j] = h[i + 1][j] + 1;
    
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < m; j++){
            int gg = 0;
            while (j - gg >= 0 && h[j - gg] >= h[j])
                gg++;
            gg--;
            int hh = 1;
            while (hh + j < m && h[hh + j] > h[j])
                hh++;
            hh--;


        }
    }
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B1.in", "r", stdin);
		freopen("B1.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}