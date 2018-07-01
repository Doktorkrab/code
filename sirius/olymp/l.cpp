#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    cin >> n;
    unsigned long long a = 0, b = 0;
    for (int i = 0; i < n;i++){
        int aa, bb;
        cin >> aa >> bb;
        a += aa;
        b += bb;
    }
    int ans = 0;
    int i = 63;
    while (i >= 0 && (a & (1LL << i)) == (b & (1LL << i))){
        ans += ((a & (1LL << i)) > 0);
        --i;
    }
    ans += i + 1;
    cout << ans << '\n';

}