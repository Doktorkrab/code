#include <bits/stdc++.h>
 
using namespace std;
#define int long long
struct Man{
    int v, d, p;
};
int32_t main() {
    int n;
    cin >> n;
    vector<Man> arr(n);
    for (int i = 0; i < n; i++){
        int v, d, p;
        cin >> v >> d >> p;
        arr[i] = {v, d, p};
    }
    vector<int> ans;
    vector<bool> used(n, 0);
    for (int i = 0; i < n; i++){
        if (arr[i].p < 0){
            if (used[i]) continue;
            for (int j = i + 1; j < n; j++) {
                arr[j].p -= arr[i].d;
            }
            used[i] = 1;
            continue;
        }
        ans.push_back(i + 1);
        int cnt = 0;
        for (int j = i + 1; j < n && cnt < arr[i].v; j++){
            if (!used[j]) arr[j].p -= arr[i].v - cnt++;
        }
       // for (auto i : arr) cout << i.p << ' ';
       // cout << '\n';
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
}