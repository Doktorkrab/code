#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_set<int> cnt;
    vector<int> arr(n);
    vector<int> cnt1(5e5 + 1);
    int qni = 0;
    for (int i = 0;i < n;i++){
        cin >> arr[i];
        cnt.insert(arr[i]);
    }
    int l = 0, ans = 1;
    for (int r = 0;r < n;r++){
        if (cnt1[arr[r]] == 0) qni++;
        cnt1[arr[r]]++;
        while (l <= r && !(r - l + 1 == qni || (r - l == qni && qni < cnt.size()))){
            cnt1[arr[l]]--;
            if (cnt1[arr[l]] == 0) qni--;
            l++;
        }
        ans = max(ans,r - l + 1);
    }
    cout << ans << '\n';
}