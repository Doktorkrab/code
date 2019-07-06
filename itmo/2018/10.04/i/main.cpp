#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main(){
    freopen("sorting.in", "r", stdin);
    freopen("sorting.out", "w", stdout);
    int n, M;
    cin >> n >> M;
    vector<int> arr(n);
    set<int> rainbow_dash;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        rainbow_dash.insert(arr[i]);
    }
    for (int i = 0; i < n; i++){
        rainbow_dash.erase(arr[i]);
        auto it = rainbow_dash.upper_bound(arr[i]);
        if (it != rainbow_dash.begin()){
            it--;
//            cerr << arr[i] << ' ' << (*it) << '\n';
            if ((*it) + arr[i] > M){
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}