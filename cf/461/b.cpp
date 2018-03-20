#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<vector<int>> gg;
    long long ans = 0;
    for (int c = 1; c <= n; c++){
        for (int b = 1; b <= c;b++){
            int a = c ^ b;
            if (a > b || b > c) continue;
            if (a + b > c && a + c > b && b + c > a && a <= n){
                // vector<int> tmp = {a, b, c};
                // sort(tmp.begin(), tmp.end());
                // gg.insert(tmp);
                ans++;
            }
        }
    }
    // for (auto u : gg){
    //     for (auto i : u) cout << i << ' ';
    //     cout << '\n';
    // }
    cout << ans;
}