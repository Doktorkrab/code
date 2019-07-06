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
#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------



int32_t main(){
    #ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        arr[i] = c - '0';
        sum += arr[i];
    }
    if (!sum){
        cout << "YES\n";
        return 0;
    }
    for (int i = 1; i < sum; i++){
        if (i != 0 && sum % i) continue;
        ll s_n = 0;
        bool f = 0;
        // prn(i);
        for (int j = 0; j < n; j++){
            s_n += arr[j];
            // prn(j, s_n);
            if (s_n == i) s_n = 0;
            if (s_n > i){
                f = 1;
                break;
            }
        }
        if (s_n == 0 && !f){
            cout << "YES\n";
            return 0;
        }

    }
    cout << "NO\n";
}

