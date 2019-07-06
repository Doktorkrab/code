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
using ll = int;
//------------------------------------------------------------------------------



int32_t main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
#endif
    while (t--){
        ll zz, zo, oz, oo;
        cin >> zz >> zo >> oz >> oo;
        if (zz + zo + oz + oo == 0){
            prn(0);
            continue;
        }
        ll cnt_0 = 1, cnt_1 = 1;
        while ((cnt_0 - 1) * cnt_0 / 2 < zz){
            cnt_0++;
        }
        if ((cnt_0 - 1) * cnt_0 / 2 > zz){
            prn("Impossible");
            continue;
        }
        while ((cnt_1 - 1) * cnt_1 / 2 < oo){
            cnt_1++;
        }
        if ((cnt_1 - 1) * cnt_1 / 2 > oo){
            prn("Impossible");
            continue;
        }
        if (zz == 0 || oo == 0){
            if (oz == 0 && zo == 0){
                // prn(cnt_0, cnt_1);
                if (cnt_0 == 1) cnt_0 = 0;
                if (cnt_1 == 1) cnt_1 = 0;
                for (int i = 0; i < cnt_0; i++) cout << '0';
                for (int i = 0; i < cnt_1; i++) cout << '1';
                cout << '\n';
                continue; 
            }
        }
        // prn(cnt_0, cnt_1);
        if (cnt_0 * cnt_1 != oz + zo){
            prn("Impossible");
            continue;
        }
        string ans;
        // prn(cnt_0, cnt_1);
        for (int i = 0; i < cnt_0 + cnt_1; i++) ans += '0';
        // prn(ans.size());
        rep(i, ans.size()){
            if (!cnt_0 || zo < cnt_1){
                ans[i] = '1';
                oz -= cnt_0;
                cnt_1--;
            }
            else{
                zo -= cnt_1;
                --cnt_0;
            }
        }
        cout << ans << '\n';
    }
}
