#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;


const ull BASE = 127;
const ull MOD = 150000001;
const ull MOD_SQR = MOD * MOD;

vector<string> matrix;
vector<vector<ull>> hashes, hashes1;
vector<ull> bases;
vector<ull> get(int i){
    string &s = matrix[i];
    vector<ull> hashes;
    int n = s.size();
    hashes.resize(n + 1);
    bases.resize(n + 1);
    hashes[0] = 0, bases[0] = 1;
    for (int i = 0;i < n;i++){
        hashes[i + 1] = ((hashes[i] * BASE) % MOD + s[i]) % MOD;
        bases[i + 1] = (bases[i] * BASE) % MOD;
    }
    return hashes;
}
void get1(int j){
    string &s = matrix[j];
    reverse(s.begin(), s.end());
    int n = s.size();
    hashes1[j].resize(n + 1);
    hashes1[j][0] = 0;
    for (int i = 0;i < n;i++){
        hashes1[j][i + 1] = ((hashes[j][i] * BASE) % MOD + s[i]) % MOD;
    }
    reverse(s.begin(), s.end());
}
ull get_hash(int l, int r, int i){ // [l; r)
    return (hashes[i][r] + MOD_SQR - (hashes[i][l] * bases[r - l]) % MOD) % MOD;
}