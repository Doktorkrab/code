#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 2; i++){
        for (int j = 0; j < n - 1; j++){
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
        for (int j = 0; j < n; j++)
            cerr << arr[j] << " \n"[j == n - 1];
    }
}