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
    int t = 1;
    #endif

    int n, p;
    cin >> n >> p;
    list<int> arr;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    auto it = arr.begin();
    for (int i = 0; i + 1 < p; i++) it++;
    int q;
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        if (s == "moveRight"){
            it++;
            if (arr.end() == it) it--;
        }
        if (s == "moveLeft"){
            if (arr.begin() == it) it++;
            it--;
        }
        if (s == "print"){
            cout << *(it) << '\n';
        }
        if (s == "insertLeft"){
            int x;
            cin >> x;
            arr.insert(it, x);
        }
        if (s == "insertRight"){
            int x;
            cin >> x;
            it++;
            arr.insert(it, x);
            it--;
            it--;
        }
    }
}
