#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, c, t;
    cin >> n >> a >> b >> c >> t;
    int choice = 0;
    // if (b == c) choice = 0;
    if (b < c) choice = 1;
    // if (b > c) choice = 2;
    int ans = 0;
    for (int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        ans += (choice ? a + (c - b) * (t - tmp) : a);
    }
    cout << ans << '\n';
}