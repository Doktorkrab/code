#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
ll a, b, c, d, x, y;

pair<ll, ll> get_ans(){
    ll bound = min((ll) 2e6 + a, b);
    for (ll i = a; i <= bound; i++){
        ll l = max(c, (x + i - 1) / i);
        ll r = min(d, y / i);
        if (l <= r) {
            if (i * l < x || i * l > y || l < c || l > d || i < a || i > b){
                exit(1);
            }
            return {i, l};
        }
    }
    return {0, 0};
}
main(){
    cin >> a >> b >> c >> d >> x >> y;
    auto ans = get_ans();
    if (ans != make_pair(0LL, 0LL)){
        cout << "YES\n";
        cout <<ans.first << ' ' << ans.second << '\n';
        return 0;
    }
    swap(a, c);
    swap(b, d);
    ans = get_ans();
    if (ans != make_pair(0LL, 0LL)){
        cout << "YES\n";
        cout <<ans.first << ' ' << ans.second << '\n';
        return 0;
    }
    cout << "NO\n";
}