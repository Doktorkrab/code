#include <bits/stdc++.h>
// #define _GLIBCXX_DEBUG
using ull = unsigned long long;
using namespace std;
#define forn(i, n) for(ull i = 0;i < n;i++)
#define sz size
#define pb push_back

// const ull MOD = 1e9 + 17;
ull p = 239;
//ull m = 4743498719;
vector<ull> h;
vector<ull> bases;
void build(string& s){
    ull n = s.size();
    h.resize(n + 1);
    bases.resize(n + 1);
    h[0] = 0, bases[0] = 1;
    for (ull i = 0;i < n;i++){
        h[i + 1] = (h[i] * p)  + s[i];
//        h[i + 1] %= m;
        bases[i + 1] = bases[i] * p;
//        bases[i + 1] %= m;
    }
}
ull get_hash(ull l, ull r){
    return (h[r + 1] - (h[l] * bases[r - l + 1]));
}

int main(){
    string s;
    cin >> s;
    build(s);
    int n = s.size();
    vector<bool> ans(n);
    ans[n - 1] = 1;
    int l1 = 0, r1 = 0, l2 = n - 1, r2 = n - 1;
    while(l1 <= l2){
        if (get_hash(l1, r1) == get_hash(l2, r2)){
            ans[r1] = ans[r2] = 1;
            r1++, l2--;
            l1 = r1;
            r2 = l2;
        }
        else r1++, l2--;
    }
    string cur;
    int ans1 = 0;
    for (int i : ans) ans1 += i;
//    cout << '\n';
    cout << ans1 << '\n';
    for (int i = 0; i < n;i++){
        cur += s[i];
        if (ans[i]) {
            cout << cur << '\n';
            cur.clear();
        }
    }
//    cout << cur << '\n';
}