#include <bits/stdc++.h>


using namespace std;

const int INF = 1e9;


int main(){
    // freopen("game.in", "r", stdin);
    // freopen("game.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> id(1 << n, -1);
    vector<string> strings(m);
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        strings[i] = s;
        int mask = 0;
        for (char c : s){
            if ((1 << (c - 'a')) & mask){
                mask = INF;
                break;
            }
            else {
                mask |= 1 << (c - 'a');
            }
            // cerr << s << ' ' << c << ' ' << mask << '\n';
        }
        // cerr << mask << '\n';
        if (mask == INF) continue;
        id[mask] = i;
    }
    vector<int> dp((1 << n)), prev((1 << n));
    int ans = 0, pos = 0;
    for (int mask = 1; mask < (1 << n); mask++){
        for (int submask = mask; submask; submask = mask & (submask - 1)){
            if (id[submask] == -1) continue;
            if (dp[mask] < dp[mask ^ submask] + (int)(strings[id[submask]].size()) - 1){
                dp[mask] = dp[mask ^ submask] + strings[id[submask]].size() - 1;
                prev[mask] = submask;
            }
        }
        if (ans < dp[mask]){
            ans = dp[mask];
            pos = mask;
        }
    }
    vector<int> ans1;
    while(pos){
        ans1.push_back(id[prev[pos]] + 1);
        pos ^= prev[pos];
    }
    cout << ans1.size() << '\n';
    for (int i : ans1) cout << i << ' ';
    cout << '\n';
}