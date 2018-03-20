#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define ch(arr) arr.begin(),arr.end()
using ll = long long;
using ld = long double;
 
using namespace std;
vector<ll> times;
ll n, s;
bool cmp(int m){
    ll sum = 0;
    bool f = 0;
    rep(i, n){
        if (m - times[i] > 0) f = 1;
        sum += max(0LL, m - times[i]);
    }
    //cout << sum << '\n';
    return sum < s && f;
}
void bin_s(){
    ll l = 0, r = LONG_LONG_MAX;
    while (r - l != 1){
        ll m = (l + r) / 2;
        //cout << m << "!!!!!!!!!!!!!!!!!!\n";
        if (cmp(m)) l = m;
        else r = m;
    }
    cout << r << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        rep(tests, 2){
    #endif
        cin >> n >> s;
        times.assign(n, 0);
        rep(i, n) cin >> times[i];
        bin_s();
}
#ifdef LOCAL
}
#endif