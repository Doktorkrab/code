#include <bits/stdc++.h>


using namespace std;


int main(){
    int k, n;
    cin >> k >> n;
    vector<int> perm(k);
    for (int i = 1; i <= k;i++){
        perm[i - 1] = i;
    }
    vector<pair<pair<int, int>, pair<int, int>> > arr(n);
    for (int i = 0;i < n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        arr[i] = {{a, b}, {c, d}};
    }
    do{
        int can = 1;
        for (int i = 0;i < n;i++){
            can &= (perm[arr[i].first.first] < perm[arr[i].first.second]) ^ (perm[arr[i].second.first] < perm[arr[i].second.second]);
        }
        if (can){
            vector<int> ans(k);
            for (int i = 0;i < k;i++){
                ans[perm[i] - 1] = i + 1;
            }
            for (int i : ans){
                cout << i << ' ';
            }
            cout << '\n';
            return 0;
        }
    } while(next_permutation(perm.begin(), perm.end()));
    cout << "0\n";
}