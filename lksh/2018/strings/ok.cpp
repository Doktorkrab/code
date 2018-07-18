#include <bits/stdc++.h>


using namespace std;


int main(){
    string s;
    cin >> s;
    int m;
    cin >> m;
    while (m--){
        string q;
        cin >> q;
        if (q == "palindrome?"){
            int l, r;
            cin >> l >> r;
            bool ans = 1;
            --l, --r;
            while (l <= r){
                // cout << s[l] << ' ' << s[r] << '\n';
                ans &= s[l] == s[r];
                l++, --r;
            }
            cout << (ans ? "Yes" : "No") << '\n';
        }
        if (q == "change"){
            int pos;
            char c;
            cin >> pos >> c;
            s[pos - 1] = c;
        }
    }
}