#include <bits/stdc++.h>

using namespace std;

int main() {
//    freopen("prefix-function.in", "r", stdin);
//    freopen("prefix-function.out", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    int pi[n];
    for (int i = 0; i < n; i++) {
        pi[i] = 0;
    }
    cout << 0 << ' ';
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j != 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
        cout << j << ' ';
    }
}
