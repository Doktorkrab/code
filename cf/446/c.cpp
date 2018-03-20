#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define ch(arr) arr.begin(),arr.end()
using ll = long long;
using ld = long double;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        rep(tests, 7){
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i, n) cin >> arr[i];
    int ans = 0;
    int gg = 0;
    bool flaga = 0;
    for (;gg < n;gg++){
        bool flag = 0;
        for (int i = 0;i + 1 < n;i++){
            if (gcd(arr[i], arr[i + 1]) == 1){
                flag = flaga = 1;
                if (arr[i] == 1 && arr[i + 1] == 1) continue;
                ans -= (arr[i] == 1);
                ans -= (arr[i + 1] == 1);
                arr[i] = arr[i + 1] = 1;
                ans += 2;
            }
        }
        if (!flag) break;
    }
    //cout << ans << '\n';
    for (;gg < n;gg++){
        bool flag1 = 0;
        rep(i, n - 1){
            if (i > 0 && gcd(arr[i - 1], gcd(arr[i], arr[i + 1])) == 1){
                flag1 = flaga = 1;
                if (arr[i] == 1) ans--;
                if (arr[i - 1] == 1) ans--;
                if (arr[i + 1] == 1) ans--;
                if (arr[i] == 1 && arr[i + 1] == 1) ans--;
                arr[i - 1] = arr[i] = arr[i + 1] = 1;
                ans += 4;
            }
        }
        if (!flag1) break;
    }
    int o_cnt = 0;
    rep(i, n) o_cnt += (arr[i] == 1);
    if (!o_cnt) cout << -1 << '\n';
    else cout << ans << '\n';
}
#ifdef LOCAL
}
#endif