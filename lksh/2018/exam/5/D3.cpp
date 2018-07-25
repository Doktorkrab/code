#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;
using ull = uint64_t;
const ull BASE = 127;
const ull MOD = 1500000001;
const ull MOD_SQR = MOD * MOD;
string s;
ull hashes[MAXN], bases[MAXN];
auto get_hash = [&](int l, int r){ return (hashes[r] + MOD_SQR - (hashes[l] * bases[r - l]) % MOD) % MOD;};
int n;
ull bin_search(ull a, ull b){
    ull l = 0, r = min(n - a, n - b);
    while(r - l > 1){
        ull m = (l + r) / 2;
        if (get_hash(a, a + m) == get_hash(b, b + m)){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l;
}
bool cmp(ull a, ull b){
    ull lcp = bin_search(a, b);
    if (lcp == min(n - a, n - b)) return a > b;
    return s[a + lcp] < s[b + lcp];
} 
int main(){
    hashes[0] = 0;
    bases[0] = 1;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++){
        hashes[i + 1] = (hashes[i] * BASE) % MOD + s[i];
        bases[i + 1] = bases[i] * BASE;
    }
    vector<int> suff(n);
    iota(suff.begin(), suff.end(), 0);
    sort(suff.begin(), suff.end(), cmp);
    for (int i = 0; i < n; i++) cout << suff[i] << ' ';
    cout << '\n';
}