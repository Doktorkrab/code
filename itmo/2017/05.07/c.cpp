#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
const ull BASE = 239017, MOD = 1e9 + 7;
pair<vector<ull>, vector<ull>> bld_hash(string& s){
    vector<ull> hashes = {0}, bases = {1};
    for (int i = 0;i < s.size();i++){
        hashes.push_back(hashes[i] * BASE + s[i]);
        bases.push_back(bases[i] * BASE);
    }
    return {hashes, bases};
}
ull getHash(int l, int r, vector<ull>& h, vector<ull>& deg) {
  return h[r + 1] - h[l] * deg[r - l + 1];
}
int main(){
    string s;
    cin >> s;
    auto tmp = bld_hash(s);
    vector<ull> hash_s = tmp.first;
    vector<ull> bases = tmp.second;
    reverse(s.begin(), s.end());
    tmp = bld_hash(s);
    vector<ull> hash_t = tmp.first;
    ull n = s.size(), ans = 0;
    for (int i = 0;i < n;i++){
        for (int j = i;j < n;j++){
            if (getHash(i, j, hash_t, bases) == getHash(i, j, hash_s, bases)) {
                cout << i << ' ' << j << ' ' << getHash(i, j, hash_t, bases) << ' ' <<  getHash(i, j, hash_s, bases) << '\n';
                ans++;
            }
        }
    }
    cout << ans << '\n';
}