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
#include <string>
#include <cassert>

using namespace std;

mt19937 rnd((uint64_t) new char);

int64_t rand(int64_t x, int64_t y) { return rnd() % (y - x + 1) + x; }

template<typename t>
t min(t a) {
    return a;
}

template<typename t, typename... ts>
t min(const t &a, const ts &... as) {
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}

template<typename t>
t max(t a) {
    return a;
}

template<typename t, typename... ts>
t max(const t &a, const ts &... as) {
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}

void prn(ostream &os) {
    os << '\n';
}

void prn() {
    cout << '\n';
}

template<typename t, typename... ts>
void prn(ostream &os, const t &a, const ts &... b) {
    os << a << ' ';
    prn(os, b...);
}

template<typename t, typename... ts>
void prn(const t &a, const ts &... b) {
    cout << a << ' ';
    prn(cout, b...);
}

#ifdef LOCAL

template<typename... ts>
void deb(const ts &... b) {
    prn(cerr, "DEBUG", b...);
}

#else
template<typename... ts>
void deb(const ts&... b){

}
#endif

#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (int adsada = 0; adsada < v.size(); adsada++) cout << v[adsada] << " \n"[adsada == v.size() - 1];
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------

struct Query {
    ll diff, a, b, c, d, ind;

    bool operator<(const Query &rhs) const {
        return tie(diff, a, b, c, d, ind) < tie(rhs.diff, rhs.a, rhs.b, rhs.c, rhs.d, rhs.ind);
    }
};

const int OPEN = -1, CLOSE = 1;
struct Event {
    int type, ind;
};

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string FN = "tram";
//    freopen((FN + ".in").c_str(), "r", stdin);
//    freopen((FN + ".out").c_str(), "w", stdout);
#endif
    int n, m, p;
    cin >> n >> m >> p;
    ll sum_a = 0;
    ll sum_stand = 0;
    ll ans = 0;
    vector<vector<Event>> events(p);
    vector<Query> pass(n);
    set<Query> sits, stands;
    rep(i, n) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        events[--c].push_back({OPEN, i});
        events[--d].push_back({CLOSE, i});
        pass[i] = {a - b, a, b, c, d, i};
    }
    rep(i, p){
        for (const Event& e : events[i]){
            if (e.type == OPEN) {
                stands.insert(pass[e.ind]);
                sum_a += pass[e.ind].a;
                sum_stand += pass[e.ind].diff;
            }
            if (e.type == CLOSE){
                sum_a -= pass[e.ind].a;
                if (stands.count(pass[e.ind])){
                    stands.erase(pass[e.ind]);
                    sum_stand -= pass[e.ind].diff;
                }
                else sits.erase(pass[e.ind]);
            }
        }

        while (sits.size() < m && stands.size() > 0 && stands.rbegin()->diff > 0){
            sum_stand -= stands.rbegin()->diff;
            auto a = *stands.rbegin();
            sits.insert(a);
            stands.erase(a);
        }
        while (!sits.empty() && !stands.empty() && sits.begin()->diff < stands.rbegin()->diff && stands.rbegin()->diff > 0){
            sum_stand -= stands.rbegin()->diff;
            sum_stand += sits.begin()->diff;
            auto a = *sits.begin();
            auto b = *stands.rbegin();
            sits.erase(a), stands.erase(b);
            sits.insert(b), stands.insert(a);
        }

        while (!sits.empty() && sits.begin()->diff < 0){
            auto a = *sits.begin();
            sum_stand += a.diff;
            stands.insert(a);
            sits.erase(a);
        }
        ans += sum_a - sum_stand;
    }
    cout << ans << '\n';
}
