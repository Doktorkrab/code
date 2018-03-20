#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 19;i < (int)1e8;i++){
        int j = i, s = 0;
        while (j != 0){
            s += j % 10;
            j /= 10;
        }
        cnt += s == 10;
        if (cnt == n){
            cout << i << '\n';
            return 0;
        }
    }
}