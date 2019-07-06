#include <bits/stdc++.h>

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
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
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



int32_t main() {
#ifdef LOCAL
    freopen("uue2.in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("uue2.in", "r", stdin);
    freopen("uue2.out", "w", stdout);
#endif
    string s;
//    getline(cin, s);
    vector<int> ans;
    while (getline(cin, s)) {
        if (s[0] == 96) break;
        int cnt = s[0] - 32;
        string s1;

        for (int i = 1; i < s.size(); i++){
            string tmp;
            int todo = s[i] - 32;
            do{
                tmp += '0' + (todo & 1);
                todo /= 2;
            }while(todo > 0);
            while (tmp.size() < 6) tmp += '0';
            reverse(all(tmp));
            s1 += tmp;
        }
        while (s1.size() % 24) s1 += '0';
        for (int i = 0; i < cnt; i++){
            int tmp = 0;
            for (int j = 0; j < 8; j++) tmp = (tmp * 2) + (s1[8 * i + j] - '0');
            ans.push_back(tmp);
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++){
        cout << hex << uppercase << setfill('0') << setw(2) << ans[i]  << " \n"[i == ans.size() - 1];
    }
}
