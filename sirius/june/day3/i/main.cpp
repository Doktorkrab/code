#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    unordered_map<string, int> votes_to_state(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        string tmp_s;
        cin >> tmp_s >> tmp;
        votes_to_state[tmp_s] = tmp;
    }
    unordered_map<string, map<string, int>> votes_in_state;
    unordered_map<string, int> ans;
    string state, pres;
    while (cin >> state >> pres) {
        votes_in_state[state][pres]++;
        ans[pres] = 0;
    }
    for (auto i : votes_in_state) {
        int mx = 0;
        string ind;
        for (auto j : i.second) {
            if (mx < j.second) {
                mx = j.second;
                ind = j.first;
            }
        }
        ans[ind] += votes_to_state[i.first];
    }
    vector<pair<int, string>> ans1;
    for (auto i : ans) {
        ans1.push_back({-i.second, i.first});
    }
    sort(ans1.begin(), ans1.end());
    for (auto i :ans1) {
        cout << i.second << ' ' << -i.first << '\n';
    }
    return 0;
}