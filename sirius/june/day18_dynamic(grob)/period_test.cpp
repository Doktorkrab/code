#include <bits/stdc++.h>

using namespace std;
string s;
int get_period(int l, int r){
    int n = r - l + 1;
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n;i++){
        int k = p[i - 1];
        while (k > 0 && s[i + l] != s[k + l]) k = p[k - 1];
        if (s[i + l] == s[k + l]) k++;
        p[i] = k;
        // cout << p[i] << ' ';
    }
    return (n % (n - p.back()) ? n : n - p.back());
}

int main(){
    cin >> s;
    cout << s.size() / get_period(0, s.size() - 1);
}