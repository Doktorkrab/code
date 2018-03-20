////////////////////////////////////////////////////////////////////////////////////////////////
// Andrey Odintsov
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
////////////////////////////////////////////////////////////////////////////////////////////////
int gg[26];
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int  cnt = 0;
    int right = 25, left = 0;
    for (char i : s){
        if (i == '?') continue;
        gg[i - 'a']++;
        if (gg[i - 'a'] == 1) cnt++;
    }
    while (right >= 0 && gg[right] != 0) right--;

    while (left < 26 && gg[left] != 0) left++;
    if (left > right) swap(right, left);
    int v_cnt = 0;
    vector<int> chet;
    vector<int> ne_chet;
    // cout << "!!!!" << left << ' ' << right << '\n';
    for (int i = 0;i < s.size();i++) {
        if (s[i] != '?')continue;
        v_cnt++;
        if ((i + 1) % 2 == 1) ne_chet.push_back(i);
        if ((i + 1) % 2 == 0) chet.push_back(i);
    }
    while (cnt < k && chet.size() && ne_chet.size()){
        if (left < 25 - right){
            s[chet.back()] = left + 'a';
            gg[left]++;
            while (left < 26 && gg[left] != 0) left++;
            // if (left == 26){
            //     cout << -1;
            //     return 0;
            // }
            cnt++;
            chet.pop_back();
        }
        else{
            s[ne_chet.back()] = right + 'a';
            gg[right]++;
            while (right >= 0 && gg[right] != 0) right--;
            // if (right == -1){
            //     cout << -1;
            //     return 0;
            // }
            cnt++;
            ne_chet.pop_back();
        }
    }
    while (chet.size()){
        if (cnt < k){
            s[chet.back()] = left + 'a';
            gg[left]++;
            while (left < 26 && gg[left] != 0) left++;
            // if (left == 26){
            //     cout << -1;
            //     return 0;
            // }
            cnt++;
            chet.pop_back();
        }
        else{
            s[chet.back()] = 'a';
            chet.pop_back();
        }
    }
    while (ne_chet.size()){
        if (cnt < k){
            s[ne_chet.back()] = right + 'a';
            gg[right]++;
            while (right >= 0 && gg[right] != 0) right--;
            // if (right == -1){
            //     cout << -1;
            //     return 0;
            // }
            cnt++;
            ne_chet.pop_back();
        }
        else{
            s[ne_chet.back()] = 'z';
            ne_chet.pop_back();
        }
    }
    //cout << s;
    set<char> gg1;
    for (char i : s) gg1.insert(i);
    if (gg1.size() < k) cout << -1;
    else cout << s;
}