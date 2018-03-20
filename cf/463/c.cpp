#include <bits/stdc++.h>
using namespace std;

void input(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}
int main(){
    input();
    int n, a, b;
    cin >> n >> a >> b;
    //return 0;
    int cur = 1;
    vector<int> ans(n);
    int ctr = n, i = 0;
    while (ctr >= a && ctr % b != 0){
        ctr -= a;
        int tmp = cur++;
        for (int j = 1; j < a;j++) {
            // cout << cur << ' ';
            ans[i++] = cur++;
        }
        // cout << i << '\n';
        // cout << tmp << ' ';
        ans[i++] = tmp;  
    }
    // cout << '\n';
    while(ctr >= b){
        int tmp = cur++;
        ctr -= b;
        for (int j = 1; j < b;j++, i++) ans[i] = cur++;
        ans[i++] = tmp;  
    }
    if (ctr != 0)
        cout << -1 << '\n';
    else{
        for (int u : ans) cout << u << ' ';
        cout << '\n';
    }
}