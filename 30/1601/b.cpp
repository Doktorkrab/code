#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)


using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui = unsigned int;
using namespace std;
using pii = pair<int, int>;


void print(ostream& st){
    st << '\n';
}


template <typename Arg, typename... Arg1>
void print(ostream& st, const Arg& a, const Arg1&... a1){
    st << a << ' ';
    print(st, a1...);
}


void input(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #endif
    #ifdef DEBUG
    freopen("kek.in", "r", stdin);
    freopen("kek.out", "w", stdout);
    #endif
}
vector<ll> sum;
ll get_sum(int l, int r){
    return !l ? sum[r] : sum[r] - sum[l - 1];
}
int main(){
    input();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    sum.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i] = (!i ? (ll)arr[i] : sum[i - 1] + (ll)arr[i]);
    }
    vector<ll> dp(n, -1), dp1(n, -1);
    // for (int i : sum) cout << i << ' ';
    // cout << '\n';
    for (int i = k - 1; i < n; i++) {
        dp[i] = (i ? max(dp[i - 1], get_sum(i - k + 1, i)) : get_sum(i - k + 1, i));
        // print(cout, "SUM", get_sum(i - k + 1, i));
    }
    // print(cerr, "KEK", dp[k]);
    for (int i = n - k; i >= 0; i--) dp1[i] = (i != n - k ? max(dp1[i + 1], get_sum(i, i + k - 1)) : get_sum(i, i + k - 1));
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; i++){
        // print(cout, i, i + k + 1, dp[i - 1], dp1[i + k]);
        ll now = 0;
        if (i - 1 >= k - 1) now = max(dp[i - 1], now);
        if (i + k + k - 1 < n) now = max(dp1[i + k], now); 
        if (now) ans = min(ans, now);
    }
    assert(ans != LONG_LONG_MAX);
    print(cout, ans);
}