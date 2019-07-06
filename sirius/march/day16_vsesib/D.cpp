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


inline void init(){

}
vector<pair<int, int>> shift = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};
inline void solve(){
    int ans = 0;
    if (n * m > 500){
        cout << "0\n";
        return;
    }
    for (int xl = 0; xl < n; xl++){
        for (int yl = 0; yl < m; yl++){
            for (int xe = 0; xe < n; xe++){
                for (int ye = 0; ye < m; ye++){
                    for (int xk = 0; xk < n; xk++){
                        for (int yk = 0; yk < m; yk++){
                            if (xl == xe || xl == xk || yl == ye || yl == yk)
                                continue;
                            if (abs(xe - xl) == abs(ye - yl) || abs(xe - xk) == abs(ye - yk))
                                continue;
                            int good = 1;
                            for (auto [x_sh, y_sh] : shift){
                                int tx = xk + x_sh;
                                int ty = yk + y_sh;
                                if ((tx == xe && ty == ye) || (tx == xl && ty == yl)){
                                    good = 0;
                                    break;
                                }
                            }
                            if (!good)
                                continue;
                            ans++;
//                            cerr << xl << ' ' << yl << '\n';
//                            cerr << xe << ' ' << ye << ' ' << xe - xl << ' ' << ye - yl << '\n';
//                            cerr << xk << ' ' << yk << '\n';
//                            cerr << '\n';
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
//    cerr << '\n';
}


int main(){
    #ifdef LOCAL
        freopen("D.in", "r", stdin);
        freopen("D.out", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
