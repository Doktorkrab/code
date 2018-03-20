#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sqr(int a) {return 1LL * a * a;}
int main(){
    freopen("circles.in", "r", stdin);
    freopen("circles.out", "w", stdout);
    int x, y, r;
    cin >> x >> y >> r;
    int x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    int ans = 0;
    for (int x2 = x - r; x2 <= x + r;x2++){
        for (int y2 = y - r; y2 <= y + r;y2++){
            if (sqr(x2 - x) + sqr(y2 - y) < r * r && sqr(x1 - x2) + sqr(y1 - y2) < r1 * r1) ans++;
        }
    }
    cout << ans << '\n';
}