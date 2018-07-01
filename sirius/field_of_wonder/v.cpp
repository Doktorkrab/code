#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int prefix_sum = 0, mn = INT_MAX, mn_i = 0;
    int ans_l = 0, ans_r = 0, ans = INT_MIN;
    for (int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        prefix_sum += tmp;
        if (ans < tmp){
            ans = tmp;
            ans_l = ans_r = i;
//            cout << tmp << "!!!!\n";
        }
        if (mn > prefix_sum){
            mn = prefix_sum;
            mn_i = i;
        }
        if (mn_i != i && prefix_sum - mn > ans){
            ans = prefix_sum - mn;
//            cout << prefix_sum - mn << '\n';
//            cout << i << ' '
            ans_l = mn_i + 1;
            ans_r = i;
        }
    }
    cout << ans << '\n';
}
