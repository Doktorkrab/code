#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> cnt(3);
    char c;
    char prev = 'a';
    while(cin >> c) {
        cnt[c - 'a']++;
        if (c == 'a' && prev != 'a'){
            cout << "NO\n";
            return 0;
        }
        if (c == 'b' && prev == 'c'){
            cout << "NO\n";
            return 0;
        }
        if (c == 'c' && prev == 'a'){
            cout << "NO\n";
            return 0;
        }
        prev = c;
    }
    if ((cnt[0] == cnt[2] || cnt[1] == cnt[2]) && cnt[0] != 0 && cnt[1] != 0) cout << "YES\n";
    else cout << "NO\n"; 
}