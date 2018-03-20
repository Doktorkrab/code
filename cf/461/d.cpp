#include <bits/stdc++.h>

using namespace std;
struct node{
    long long h_cnt = 0, s_cnt = 0, ind = 0;
    bool operator<(node const& a){
        return h_cnt * a.s_cnt < s_cnt * a.h_cnt;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> arr(n);
    vector<node> to_sort(n);
    for (int i = 0;i < n;i++){
        string s;
        cin >> s;
        arr[i] = s;
        long long s_cnt = 0;
        long long h_cnt = 0;
        for (auto j : s){
            if (j == 'h') h_cnt++;
            else s_cnt++; 
        }
        to_sort[i] = {h_cnt, s_cnt, i};
    }
    sort(to_sort.begin(), to_sort.end());
    long long s_cnt = 0;
    long long ans = 0;
    for (auto i : to_sort){
        for (auto j : arr[i.ind]){
            if (j == 's' || j == 'S') s_cnt++;
            else ans += s_cnt;
        }
    }
    cout << ans << '\n';
}