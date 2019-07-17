#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
  
struct Rectangle{
    int x1, y1, x2, y2, ind;
};
  
int n;
const int MAXN = 1e5 + 7;
Rectangle rects[MAXN];
// vector<bool> good;
inline void init(){
    // rects.resize(n, {0,0,0,0, -1});
    // good.resize(n, 1);
}
inline bool intersec(const Rectangle& a, const Rectangle& b){
    return max(a.x1, b.x1) < min(a.x2, b.x2) && max(a.y1, b.y1) < min(a.y2, b.y2);
}
inline void solve(){
    // init();
    int a, b;
    for (int i = 0; i < n; i++){
        cin >> rects[i].x1 >> rects[i].y1;
        cin >> a >> b;
        rects[i].x2 = rects[i].x1 + a;
        rects[i].y2 = rects[i].y1 + b;
    }
    bool flag;
    for (int i = 0; i < n; i++){
        flag = 1;
        for (int j = i + 1; j < n; j++){
            if (intersec(rects[i], rects[j])){
                flag = 0;
                break;
            }
        }
        cout << (flag ? "DA\n" : "NE\n");
    }
}
  
  
int main(){
    #ifdef LOCAL
        freopen("C_stupid.in", "r", stdin);
        freopen("C_stupid.out", "w", stdout);
    #endif
      
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();
  
}