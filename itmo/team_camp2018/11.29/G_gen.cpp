#include <bits/stdc++.h>

using namespace std;
const int n = 10;
int arr[n];

void rec(int pos, int sum) {
    if (pos == n) {
        int cnt[n];
        for (int i = 0; i < n; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) {
            cnt[arr[i]]++;
        }
        int good = 1;
        for (int i = 0; i < n; i++){
            if (cnt[i] != arr[i]){
                good = 0;
                break;
            }
        }
        if (good){
            for (int i = 0; i < n; i++) cout << arr[i] << ' ';
            cout << '\n';
            exit(0);
        }
        return;
    }
    for (int i = 0; i + sum <= n; i++){
        arr[pos] = i;
        rec(pos + 1, sum + i);
    }
}

int main(){
    rec(0, 0);
}