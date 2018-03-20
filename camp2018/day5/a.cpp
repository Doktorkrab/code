#include <bits/stdc++.h>
using ull = unsigned long long;
using namespace std;
#define forn(i, n) for(ull i = 0;i < n;i++)
#define sz size
#define pb push_back
 
// const ull MOD = 1e9 + 17;
ull p = 1007;
ull m = 1e9 + 239;
vector<ull> h;
vector<ull> bases;
void build(string& s){
    ull n = s.size();
    h.resize(n + 1);
    bases.resize(n + 1);
    h[0] = 0, bases[0] = 1;
    for (ull i = 0;i < n;i++){
        h[i + 1] = (h[i] * p) % m + s[i];
        h[i + 1] %= m;
        bases[i + 1] = bases[i] * p;
        bases[i + 1] %= m;
    }
}
ull get_hash(ull l, ull r){
    return (h[r + 1] + m - (h[l] * bases[r - l + 1]) % m) % m;
}
ull bin_search(ull a, ull b){
    ull l = 0, r = min(h.size() - a, h.size() - b);
    while(r - l > 1){
        ull m = (l + r) / 2;
        if (get_hash(a, a + m - 1) == get_hash(b, b + m - 1)){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l;
}
string s;
bool cmp(ull a, ull b){
    ull lcp = bin_search(a, b);
    if (lcp == min(h.size() - a, h.size() - b)) return a > b;
    return s[a + lcp] < s[b + lcp];
}
signed main(){
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    cin >> s;
    build(s);
    ull n = s.size();
    vector<ull> suf(n);
    for (ull i = 0;i < n;i++){
        suf[i] = i;
    }
    sort(suf.begin(), suf.end(), cmp);
    ull ans = 0;
    for (ull i = 0;i < n;i++){
        ans += n - suf[i];
    }
    for (ull i = 0;i + 1 < n;i++){
        ans -= bin_search(suf[i], suf[i + 1]);
    }
    cout << ans << '\n';
}