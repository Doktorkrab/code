#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
   
#define ft first
#define sc second
#define len(v) (int)v.size()
#define pb push_back
#define int ll 
   
using namespace std;
typedef long long ll;
  
 ll p = 239;
 ll mod = 1e9 + 7;
  
 
signed main() {
   
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     
    int n, d;
    cin >> n >> d;
    if(n == 0 && d == 0) {
        cout << 2 << " " << 1 << endl;
        return 0;
    }
    if(n == 0 || n < d) {
        cout << 2 << " " << 0 << endl;
        return 0;
    }
    int maxx = 0;
    int ans = 2;
    if(n - d >= 2 && (n % (n - d)) == d) {
        maxx = 1;
        ans = n - d;
    }
 
 
    if(d != 0 && (n - d) % d == 0 && (n - d) / d >= 2) {
        maxx = 2;
        ans = (n - d) / d;
    }
 
    int dis = sqrtl(d * d - (d - n) * 4 * d);
    if(d != 0 && dis * dis == d * d - (d - n) * 4 * d) {
        int neww = (-d + dis) / (2 * d);
        if(neww * 2 == (-d + dis) / (2 * d) && neww >= 2) {
            maxx = 3;
            ans = neww;
        }
    }
    for (int i = 2; i < 1e7; i++) {
        int cnt = 0;
        int nc = n;
        while(nc > 0) {
            if(nc % i != d) {
                break;
            }
            cnt++;
            nc /= i;
        }
        if(cnt > maxx) {
            maxx = cnt;
            ans = i;
        }
        if(cnt == maxx && i < ans) {
            maxx = cnt;
            ans = i;
        }
    }
    cout << ans << " " << maxx << endl;
    return 0;
}