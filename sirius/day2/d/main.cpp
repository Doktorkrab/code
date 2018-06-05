#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> original(n);
    int mx = 0;
    for (int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        original[i] = a - b;
        mx = max(mx, original[i]);
    }
    vector<int> ans;
    for (int f = 1; 1LL * f * f <= 1LL * mx; f++){
        bool fl = 0, f2 = 0;
        for (int i : original){
            fl |= i % f;
        }
        if (fl) continue;
        ans.push_back(f);
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}