#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define ch(arr) arr.begin(),arr.end()
using ll = long long;
using ld = long double;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        rep(tests, 3){
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i, n) cin >> arr[i];
    vector<int> events(n);
    rep(i, n){
        events[max(0, i - arr[i])]++;
        events[i]--;
    }
    int bal = 0;
    int ans = 0;
    // rep(i, n) cout << events[i] << ' ';
    // cout << '\n';
    rep(i, n){
        bal += events[i];
        if (bal > 0) ans++;
    }
    cout << n - ans << '\n';

}
#ifdef LOCAL
}
#endif