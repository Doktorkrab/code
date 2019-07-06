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


char get_diff(char a){
    return 'a' + ((a - 'a' + 1) % 26);
}

char get_diff(char a, char b){
    vector<char> used(26);
    used[a - 'a'] = used[b - 'a'] = 1;
    for (int i = 0; i < 26; i++) if (!used[i]) return 'a' + i;
}

int32_t main(){
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n, t;
    cin >> n >> t;
    string s, s1;
    cin >> s >> s1;
    int diff1 = 0;
    for (int i = 0; i < n; i++){
        diff1 += (s[i] != s1[i]);
    }
    int t1 = n - diff1;
    if ((diff1 + 1) / 2 > t){
        cout << -1 << '\n';
        return 0;
    }
    int same = max(0, t - diff1);
    t -= (int) same;
    int diff = 2 * t - diff1;
    if (same > t1) diff += same - t1;
    // prn(diff, t, diff1);

    for (int i = 0; i <  n; i++){
        if (s[i] == s1[i]){
            if (same){
                cout << get_diff(s[i]);
                same--;
            }
            else cout << s[i];
        }
        else{
            // prn(diff, i);
            if (diff > 0){
                cout << get_diff(s[i], s1[i]);
                diff--;
            }
            else{
                if (diff1 % 2 == 0){
                    cout << s[i];
                }
                else cout << s1[i];
                diff1--;
            }
        }
    }
    prn();
}
