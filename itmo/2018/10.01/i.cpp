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

int n;
int dist(int a, int b){
    if (a > b) swap(a, b);
    return min(b - a, a + n - b);
}
int32_t main(){
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("i.in", "r", stdin);
    freopen("i.out", "w", stdout);
#endif
    unordered_map<int, vector<int>> entries;
    unordered_map<int, int> point;
    cin >> n;
    int ans = 0, ind = -1, ind1 = -1;
    rep(i, n){
        int now;
        cin >> now;
        if (!entries.count(now)){
            entries[now] = {i};
            point[now] = 0;
            continue;
        }
        int pnt = point[now];
        int ans1 = dist(entries[now][pnt], i);
        while (pnt + 1 < entries[now].size() && dist(entries[now][pnt + 1], i) > dist(entries[now][pnt], i)){
            ans1 = dist(entries[now][pnt + 1], i);
            pnt++;
        }
        if (ans < ans1){
            ans = ans1;
            ind = i;
            ind1 = entries[now][pnt];
        }
        point[now] = pnt;
        entries[now].push_back(i);
    }
    prn(ind + 1, ind1 + 1);
}