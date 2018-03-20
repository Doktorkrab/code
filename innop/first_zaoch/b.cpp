#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define ch(arr) arr.begin(),arr.end()
using ll = long long;
using ld = long double;

using namespace std;
ll n, s;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        rep(tests, 3){
    #endif
        cin >> n >> s;
        ll sum = 0;
        vector<ll> times(n);
        rep(i, n) {
            cin >> times[i];
        }
        ll ans = 0;
        for (ll i = 0;i < n;i++){
            sum += times[i];
            if ((s + sum) % (i + 1) == 0 && (s + sum) / (i + 1) >= times[i]   && (i + 1 == n|| (i + 1 < n &&(s + sum) / (i + 1) <= times[i + 1]))){
                //cout << i + 1 << ' ' << s + sum << ' ' <<(i + 1 < n ? times[i + 1] : -1) << '\n';
                ans = (s + sum) / (i + 1);
            }
        }
        cout << ans << '\n';
}
#ifdef LOCAL
}
#endif