#include <bits/stdc++.h>
using namespace std;
bool in(string& s, string& t){
    int l = 0, r = 0;
    while(l < s.size() && r < t.size()){
        if (s[l] == t[r]) r++;
        l++;
    }
    return r == t.size();
}
int main(){
    string s;
    cin >> s;
    vector<string> sqrs;
    for (int i = 1; to_string(i * i).size() <= s.size();i++){
        sqrs.push_back(to_string(i * i));
    }
    int ans = 1e9;
    for (string& sqr : sqrs){
        if (in(s, sqr)){
            ans = min(ans, (int)s.size() - (int)sqr.size());
        }
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}