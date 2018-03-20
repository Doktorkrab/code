#include <bits/stdc++.h>
using namespace std;
int main(){
    set<pair<int, int>> s;
    int n, m, tmp, tmp1;
    cin >> n;
    vector<int> schools(n);
    vector<vector<int>> need(1001);
    for (int i = 0;i < n;i++){
        cin >> schools[i];
        need[schools[i]].push_back(i);
    }
    cin >> m;
    vector<pair<int, int>> conds(m);
    for (int i = 0;i < m;i++){
        cin >> tmp >> tmp1;
        conds[i] = {tmp1, tmp};
    }
    sort(conds.begin(), conds.end());
    int cnt = n;
    int ans = 0;
    int j = 0;
    while(cnt){
        for (int i = conds[j].second;i>=0;i--){
            while (need[i].size()){
                need[i].pop_back();
                // cerr << "!!! " << conds[j].second << ' ' << conds[j].first << '\n';
                ans += conds[j].first;
                --cnt;
            }
        }
        ++j;
    }
    cout << ans << '\n';
}