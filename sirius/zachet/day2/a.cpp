#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, x;
    cin >> n >> x;
    if (n == 2 && x == 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n == 1){
        cout << x << '\n';
        return 0;
    }
    if (n == 2){
        cout << x << " 0\n";
        return 0;
    }
    int cur = 0;
    for (int i = 1; i <= n - 3;i++) {
        cout << i << ' ';
        cur ^= i;
    }
    int pw = 0;
    int a = (1 << 17);
    int b = (1 << 18);
    if (cur == x){
        cout << a + b << ' ' << a << ' ' << b << '\n';
    }
    else{
        cout << a << ' ' << ((a ^ x) ^ cur) << " 0\n";
    }


}