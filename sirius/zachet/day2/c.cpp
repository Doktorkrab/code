#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for (auto& i : arr) cin >> i;
    int ans = 0;
    for (int i = 'a'; i <= 'z'; i++){
        for  (int j = 'a'; j <= 'z'; j++){
            int now = 0;
            for (string s : arr){
                int ft = 0;
                for (char c : s){
                    if (c != i && c != j){
                        ft = 0;
                        break;
                    }
                    ft++;
                }
                now += ft;
            }
            ans = max(ans, now);
        }
    }
    cout << ans << '\n';
}