#include <bits/stdc++.h>

using namespace std;

pair<long long, unordered_map<int, int>> fact(int i){
    int old_i = sqrt(i), i1 = i;
    unordered_map<int, int> fct;
    pair<long long, unordered_map<int, int>> ans = {1, {}};
    for (int f = 2; f <= old_i; f++){
        while (i % f == 0){
            fct[f]++;
            i /= f;
        }
    }
    if (i != 1) fct[i]++;
    for (auto i : fct){
        ans.first *= i.second + 1LL;
        // cout << i.first << ' ' << i.second << '\n';
    }
    do{
        ans.second[i1 % 10]++;
        i1 /= 10;
    } while(i1 > 0);
    return ans;
}

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> gg;
    for (int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        gg[tmp]++;
    }
    int ans = 1e6, ans1 = 0;
    for (int i = 1; i < 2e5;i++){
        auto hh = fact(i);
        bool f = 1;
        for (auto j : hh.second){
            if (!gg.count(j.first) || gg[j.first] < j.second) {
                f = 0;
                break;
            }
        }
        if (f && ans > hh.first){
            ans = hh.first;
            ans1 = i;
        }
    }
    cout << ans << '\n' << ans1 << '\n';
}