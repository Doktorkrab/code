#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FILE_IO(x) freopen((string(x) + ".in").c_str(), "r", stdin); freopen((string(x) + ".out").c_str(), "w", stdout)
#define f first
#define s second
#define x1 x1qwer
#define y1 y1qwer
#define foreach(it, v) for (auto it : v)
#define rep(it, n) for (int it = 0; it < n; ++it)
#define forin(it, l, r) for (int it = l; it < r; ++it)
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
mt19937 mmtw(MOD);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }
template <class T> T binpow(T n, T k) { if (k == 1) return n; if (k & 1) return binpow(n, k - 1) * n; T a = binpow(n, k / 2); return a * a; }
template <class T> T fact(T n) { if (n == 1) return 1; return n * fact(n - 1); }
int main(){
    FAST_IO;
    FILE_IO("numbers");
    int n;
    cin >> n;
    unordered_map<string, vector<string>> cnt;
    rep(i, n){
        string c; int k;
        cin >> c >> k;
        cnt[c] = vector<string>(k);
        rep(j, k){
            cin >> cnt[c][j];
        }
    }
    int m;
    cin >> m;
    rep(i, m){
        string str;
        cin >> str;
        bool flag1 = 0;
        for (auto v : cnt){
            if (v.first == str.substr(0, v.first.size())){
                bool flag = 0;
                if (v.first[0] == '0') continue;
                for (string& g : v.second){
                    if (g == str.substr(v.first.size(), g.size())){
                        if (g[0] == '0') continue;
                        //cout << g << ' ' << 11 - g.size() - v.first.size() << ' '<< str << ' ' << str[4] << ' ' << str[5] << ' ' << str[6] << ' ' << str[7] << str[8] << " debug! ";
                        if (11 - g.size() - v.first.size() == 3 && str[8] != '0'){
                            cout << "+" << v.first << "(" << g << ")" << str.substr(8, 3) << '\n';
                            flag = 1;
                            break;
                        }
                        else if (11 - g.size() - v.first.size() == 4 && str[7] != '0'){
                            cout << "+" << v.first << "(" << g << ")" << str.substr(7, 2) << "-" << str.substr(9, 2) << '\n';
                            flag = 1;
                            break;
                        }
                        else if (11 - g.size() - v.first.size() == 5 && str[6] != '0'){
                            cout << "+" << v.first << "(" << g << ")" << str.substr(6, 3) << "-" << str.substr(9, 2) << '\n';
                            flag = 1;
                            break;
                        }
                        else if (11 - g.size() - v.first.size() == 6 && str[5] != '0'){
                            cout << "+" << v.first << "(" << g << ")" << str.substr(5, 2) << "-" << str.substr(7, 2) <<"-"<< str.substr(9, 2) << '\n';
                            flag = 1;
                            break;
                        }
                        else if (11 - g.size() - v.first.size() == 7 && str[4] != '0'){
                            cout << "+" << v.first << "(" << g << ")" << str.substr(4, 3) << "-" << str.substr(7, 2) <<"-"<< str.substr(9, 2) << '\n';
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag){
                    flag1 = 1;
                    break;
                }
            }
        }
        if (!flag1) cout << "Incorrect\n";
    }
}