#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> arr = {1,2};
    int nxt = 3;
    int n = 2;
    cin >> n;
    cout << "Ready!" << endl;
    cout << nxt - 1 << endl;
    for (int i = 0;i < n; i++){
        cout << arr[i];
        if (i != n - 1)
            cout << ' ';
    }
    cout << endl;
    cout.flush();
}