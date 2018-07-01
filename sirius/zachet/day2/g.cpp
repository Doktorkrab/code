#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    unsigned long long ans = 0;
    vector<long long> arr(n);
    long long need = 0;
    for (long long& i : arr) {
        cin >> i;
        need += i;
    }
    if (need % 3){
        cout << "0\n";
        return 0;
    }
    need /= 3;
    long long ft = 0, pr = 0;
    for (int i = 0;i < n - 1;i++){
        pr += arr[i];
        if (pr == need * 2){
            ans += ft;
        }
        if (pr == need){
            ft++;
        }

    }
    cout << ans << '\n';
}