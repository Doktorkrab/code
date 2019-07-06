#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
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
#define int ll
map<pair<int, int>, int> game;
int n;
ll pow(ll a, ll b){
    if (b == 1) return a;
    if (b & 1){
        ll tmp = pow(a, b - 1) * a;
        if (tmp >= n) return n + 1;
        return tmp;
    }
    ll tmp = pow(a, b >> 1);
    if (tmp >= n || tmp * tmp >= n) return n + 1;
    return tmp * tmp;
}

int calc(pair<ll, ll> state){ // -1 - win, 0 - miss, 1 - lose
    if (game.count(state)) return game[state];
    ll cnt = pow(state.first, state.second);
    if (cnt >= n) return game[state] = -1;
    if (state.first == 1 && pow(2, state.second) >= n) return game[state] = 0;
    if (state.second == 1 && pow(state.first, 2) >= n){
        if (((n ^ state.first) & 1) == 1) return game[state] = 1;
        return game[state] = -1;
    }
    int tmp = calc({state.first + 1, state.second});
    if (tmp == 1){
        return game[state] = -1;
    }
    int tmp1 = calc({state.first, state.second + 1});
    if (tmp1 == 1){
        return game[state] = -1;
    }
    if (max(tmp, tmp1) == 0){
        return game[state] = 0;
    }
    return game[state] = 1;
}
int32_t main(){
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int a, b;
    cin >> a >> b >> n;
    int ans = calc({a, b});
    // for (const auto& i : game){
    //     cout << i.first.first << ' ' << i.first.second << ' ' << i.second << '\n';
    // }
    if (ans == -1){
        prn("Masha");
    }
    if (ans == 0){
        prn("Missing");
    }
    if (ans == 1){
        prn("Stas");
    }
}
