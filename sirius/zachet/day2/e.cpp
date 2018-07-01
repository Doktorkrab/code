#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<int, int> ones;
    ones[0]++;
    int pr = 0;
    long long ans = 0;
    for (int i = 0; i < n;i++){
        pr += s[i] == '1';
        ans += (ones.count(pr - k) ? ones[pr - k] : 0);
        ones[pr]++;
    }
    cout << ans << '\n';
}