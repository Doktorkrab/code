
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const int MAXBASE = 7e5 + 5;
ull bases[MAXBASE], bases1[MAXBASE];
const ull BASE = 127;
const ull MOD1 = 150000001, MOD2 = 1500000001;
const ull MM1 = MOD1 * MOD1, MM2 = MOD2 * MOD2;
pair<vector<ull>, vector<ull>> get_hash(const string& s){
    int n = s.size();
    vector<ull> hashes(n + 1), hashes1(n + 1);
    for (int i = 0; i < n;i++){
        hashes[i + 1] = ((hashes[i] * BASE) % MOD1 + (s[i] - 'a' + 1)) % MOD1;
        hashes1[i + 1] = ((hashes1[i] * BASE) % MOD2 + (s[i] - 'a' + 1)) % MOD2;
    }
    return {hashes, hashes1};
}

void build_bases(){
    int n = 7e5;
    bases[0] = 1;
    bases1[0] = 1;
    for (int i = 1; i <= n; i++){
        bases[i] = (bases[i - 1] * BASE) % MOD1;
        bases1[i] = (bases1[i - 1] * BASE) % MOD2;
    }
}

ull get_hash(int l, int r, const vector<ull>& hashes){
    return (hashes[r] + MM1 - (hashes[l] * bases[r - l]) % MOD1) % MOD1;
}
ull get_hash1(int l, int r, const vector<ull>& hashes){
    return (hashes[r] + MM2 - (hashes[l] * bases1[r - l]) % MOD2) % MOD2;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<ull> hashes, hashes1;
    string s;
    build_bases();
    set<pair<ull, ull>> full;
    for (int i = 0;i < n;i++){
        cin >> s;
        auto tmp = get_hash(s);
        hashes = tmp.first;
        hashes1 = tmp.second;
        full.insert({hashes.back(), hashes1.back()});
    }
    for (int i = 0; i < m;i++){
        cin >> s;
        auto tmp = get_hash(s);
        hashes = tmp.first;
        hashes1 = tmp.second;
        string ans = "NO\n";
        for (int k = 0;k < s.size();k++){
            ull h1 = get_hash(0, k, hashes);
            ull h2 = get_hash(k + 1,s.size(), hashes);
            ull hh1 = get_hash1(0, k, hashes1);
            ull hh2 = get_hash1(k + 1, s.size(), hashes1);
            for (int j = 'a'; j <= 'c'; j++){
                if (j == s[k]) continue;
                ull one = ((h1 * BASE) % MOD1 + (j - 'a' + 1)) % MOD1;
                ull two = ((one * bases[(int)s.size() - k - 1]) % MOD1 + h2) % MOD1;
                ull one1 = ((hh1 * BASE) % MOD2 + (j - 'a' + 1)) % MOD2;
                ull two1 = ((one1 * bases1[(int)s.size() - k - 1]) % MOD2 + hh2) % MOD2;
                if (full.count({two, two1})){
                    ans = "YES\n";
                    break;
                }
            }
            if (ans == "YES\n") break;
        }
        cout << ans;
    }
}
