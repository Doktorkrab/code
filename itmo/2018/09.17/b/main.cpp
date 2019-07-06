#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
mt19937 rnd((uint64_t) new char);
int64_t rand(int64_t x, int64_t y){ return rnd() % (y - x + 1) + x; }
template<typename t>
t min(t a){
    return a;
}
template<typename t, typename... ts>
t min(const t& a, const ts&... as){
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}
template<typename t>
t max(t a){
    return a;
}
template<typename t, typename... ts>
t max(const t& a, const ts&... as){
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}
void prn(ostream& os){
    os << '\n';
}
void prn(){
    cout << '\n';
}
template<typename t, typename... ts>
void prn(ostream& os, const t& a, const ts&... b){
    os << a << ' ';
    prn(os, b...);
}
template<typename t, typename... ts>
void prn(const t& a, const ts&... b){
    cout << a << ' ';
    prn(cout, b...);
}

long double pi = acos(-1.);
int32_t main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    cout.precision(20);
    cout.setf(ios::fixed);
    int n;
    int r;
    cin >> n >> r;
    vector<pair<int, int>> arr(n);
    for (auto& i : arr) cin >> i.first >> i.second;
    sort(arr.begin(), arr.end());
    double ans = 0.;
    for (int i = 0; i < n; i++){
        int res = arr[i].second - arr[i].first;
        if (res < 0)
            res = 360 + res;
        ans += (double)pi * (double)r * (double)res / (double)180;
        //cout << len << ' ';
        if (i < n-1)
            ans += (double)2 * (double)r * (double)sin((double)pi * (double)abs(arr[i+1].first - arr[i].second) / (double)360);
    }
    ans += (double)2 * (double)r * (double)sin((double)pi * (double)abs(arr[n-1].second - arr[0].first) / (double)360);
    prn(ans);

}