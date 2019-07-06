#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    assert(m == 1);
    vector<int> arr(n), to_sort(n);
    unordered_map<int, int> gg;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        to_sort[i] = arr[i];
    }
    sort(to_sort.begin(), to_sort.end());
    to_sort.erase(unique(to_sort.begin(), to_sort.end()), to_sort.end());
    for (int i = 0; i < to_sort.size(); i++)
        gg[to_sort[i]] = i + 1;
    for (int i = 0; i < n; i++)
        cout << gg[arr[i]] << '\n';

}
