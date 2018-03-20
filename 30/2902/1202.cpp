#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sqr(x) 1LL * x * x

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int intersect(int x, int y, int x1, int y1){
    return max(x, x1) <= min(y, y1);
}
struct Solver{
    ll n, y_prev = 1, d = 0, y0 = -1e9, y1 = 1e9, gg = 0;
    Solver(){
        cin >> n;
        for (ll i = 0;i < n;i++){
            ll x, y, xt, yt;
            cin >> x >> y >> xt >> yt;
            // cout << x << ' ' << y << ' ' << xt << ' ' << yt << ' ' << y0 << ' ' << y1 << '\n';
            ++x, ++y, --xt, --yt;
            if (intersect(y, yt, y0, y1)){
                d += (i != 0) * 2LL + abs(xt - x);
                if (abs(y - y_prev) < abs(yt - y_prev)){
                    d += abs(y - y_prev);
                    y_prev = y;
                    gg = -1;
                }
                else{
                    // assert(0);
                    d += abs(yt - y_prev);
                    y_prev = yt;
                    gg = 1;
                }
                // cout << "! " << y << ' ' << yt << '\n';
                y0 = y - 1;
                y1 = yt + 1;
            }
            else{
                cout << "-1\n";
                return;
            }
        }
        cout << d + abs(y1 - y_prev) - 1 << '\n';
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int t = 1;
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    cin >> t;
    #endif
    while(t--) Solver a;
}