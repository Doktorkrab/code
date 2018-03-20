#include <bits/stdc++.h>
using ull = unsigned long long;
using namespace std;
#define forn(i, n) for(int i = 0;i < n;i++)
#define sz size
#define pb push_back
  
// const int MOD = 1e9 + 17;
ull p = 127;
ull m = 1e9 + 211;
vector<ull> bases;
void build(vector<ull>& h, string& s, ull m){
    int n = s.size();
    h.resize(n + 1);
    h[0] = 0;
    for (int i = 0;i < n;i++){
        h[i + 1] = (h[i] * p) % m + s[i];
        h[i + 1] %= m;
    }
}
void build_bases(vector<ull>& bases, int gg, int m){
    bases.resize(gg + 5);
    bases[0] = 1;
    for (int i = 1;i < gg + 5;i++) bases[i] = (bases[i - 1] * p) % m;
}
ull get_hash(vector<ull>& h, vector<ull>& bases, int l, int r, ull m){
    return (h[r + 1] + m - (h[l] * bases[r - l + 1]) % m) % m;
}
  
int main(){
    freopen("common.in", "r", stdin);
    freopen("common.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    vector<ull> h, h1, h2, h3, b1, b2;
    int m1 = 1e9 + 211;
    int m2 = 1e9 + 239;
    build(h, s, m1);
    build(h1, s, m2);
    build(h2, t, m1);
    build(h3, t, m2);
    build_bases(b1, max(s.size(), t.size()), m1);
    build_bases(b2, max(s.size(), t.size()), m2);
    int l = 0, r = min(s.size(), t.size()) + 1;
    // cout << get_hash(h2, 0, 1, m2) << ' ' << get_hash(h3, 0, 1, m2) << ' ' <<get_hash(h, 3, 5, m1) << ' ' << get_hash(h1, 3, 5, m1) << '\n';
    while (r - l > 1){
        int m = (l + r) / 2;
        bool f = 0;
        unordered_set<ull> gg;
        unordered_map<ull, ull> hh;
        for (int i = 0;i + m - 1 < s.size();i++){
            gg.insert(get_hash(h, b1, i, i + m - 1, m1));
            hh[get_hash(h, b1, i, i + m - 1, m1)] = get_hash(h1, b2, i, i + m - 1, m2);   
        }
        for (int i = 0;i + m - 1 < t.size();i++){
            f |= gg.count(get_hash(h2, b1, i, i + m - 1, m1)) && (hh[get_hash(h2, b1, i, i + m - 1, m1)] == get_hash(h3, b2, i, i + m - 1, m2));
        }
        if (f){
            l = m;
        }
        else{ 
            r = m;
        }
    }
    cout << l << '\n';
  
}