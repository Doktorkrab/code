
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
const ull MOD = 150000001;
constexpr ull MOD_SQR = MOD * MOD;
const ull BASE = 127;

int n;

pair<vector<ull>, vector<ull>> build(const string& s){
    vector<ull> hashes, bases;
    hashes.resize(n + 1);
    bases.resize(n + 1);
    // cout << "!!!" << s << '\n';
    hashes[0] = 0, bases[0] = 1;
    for (int i = 0; i < n;i++){
        hashes[i + 1] = (hashes[i] * BASE + s[i]) % MOD;
        bases[i + 1] = (bases[i] * BASE) % MOD; 
    }
    return {hashes, bases};
}
vector<ull> hashes, hashes1, bases;

ull get_hash(int l, int r){ // [l; r)
    return (hashes[r] + MOD_SQR - (hashes[l] * bases[r - l]) % MOD) % MOD;
}

ull get_hash1(int l, int r){ // [l; r)
    return (hashes1[r] + MOD_SQR - (hashes1[l] * bases[r - l]) % MOD) % MOD;
}
int bin_search(int st){
    int l = 0, r = st + 2;
    while (r - l > 1){
        int m = (l + r) / 2;
        // cout << l << ' ' << m << ' ' << r << '\n';
        int nr = n - (st - m + 1);
        int nl = n - (st + 1);
        // cout << nl << ' ' << nr << '\n';
        if (get_hash(0, m) == get_hash1(nl, nr)){
            l = m;
        }
        else r = m;
    }
    return l;
}
int main(){
    string s;
    cin >> n;
    cin >> s;
    auto tmp = build(s);
    hashes = tmp.first, bases = tmp.second;
    reverse(s.begin(), s.end());
    tmp = build(s);
    hashes1 = tmp.first;
    for (int i = 0; i < n; i++) cout << bin_search(i) << ' ';
    cout << '\n';
}