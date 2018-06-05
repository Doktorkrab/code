#include <bits/stdc++.h>

using namespace std;
string lower(const string& s){
    string s1;
    for (char c : s){
        s1 += tolower(c);
    }
    return s1;
}

int cnt_upper(const string& s){
    int cnt = 0;
    for (char c : s){
        if (c != tolower(c)) cnt++;
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    unordered_map<string, unordered_set<string>> dict(n);
    string word;
    for (int i = 0; i < n;i++){
        cin >> word;
        dict[lower(word)].insert(word);
    }
    int ans = 0;
    while (cin >> word){
        string l_word = lower(word);
        ans +=  ((dict.count(l_word) && !dict[l_word].count(word)) || (!dict.count(l_word) && cnt_upper(word) != 1));
    }
    cout << ans << '\n';
}