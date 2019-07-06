#include <bits/stdc++.h>


using namespace std;
vector<int> arr = {2,2,1,3,1,4,2};

int query_arr(int l, int r){
    unordered_set<int> kek;
    for (int i = l; i < r; i++)
        kek.insert(arr[i]);
    return kek.size();
}

int main(){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        cout << arr[i] << ": ";
        for (int m = 0; m < i; m++)
            if (query_arr(m, i) < query_arr(m, i + 1))
                cout << '<';
            else if (query_arr(m, i) == query_arr(m, i + 1))
                cout << '=';
            else
                cout << '>';
        cout << '\n';
    }
}