#include <bits/stdc++.h>


using namespace std;
#define int int64_t
int32_t main(){
    int n, l, r;
    cin >> n >> l >> r;
    vector<pair<int, int>> gg(n);
    for (int i = 0; i < n; i++){
        cin >> gg[i].first >> gg[i].second;
    }
    int ans = 0, mask = 0;
    for (int i = 0; i < (1 << n); i++){
        int w = 0, s = 0;
        for (int j = 0; j < n; j++){
            if ((1 << j) & i) w += gg[j].first, s += gg[j].second;
        }
        if (w >= l && w <= r && ans < s){
            ans = s;
            mask = i;
        }
    }
    // cout << ans;
    vector<int> hh;
    int w = 0;
    for (int i = 0; i < n; i++){
        if ((1 << i) & mask) hh.push_back(i + 1), w += gg[i].first;
    }
    cout << w << '\n';
    cout << hh.size() << '\n';
    for (int i : hh) cout << i << ' ';
    cout << '\n';
}