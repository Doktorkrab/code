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


string dp[2000][2000];

int32_t main(){
    #ifndef LOCAL
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif
    int n;
    cin >> n;
    rep(i, 2000) rep(j, 2000) dp[i][j] = "A";
    dp[0][0] = "";
    deque<pair<int, int>> q = {{0, 0}};
    while (!q.empty()){
        auto top = q.front();
        int v = top.first, u = top.second;
        q.pop_front();
        repab(i, 0, 10){
            int s = v + i;
            if (s > n) continue;
            int m = (u * 10 + i) % n;
            if (dp[s][m] == "A"){
                dp[s][m] = dp[v][u] + to_string(i);
                q.push_back({s, m});
            }
        }
    }
    cout << dp[n][0] << '\n';
}
