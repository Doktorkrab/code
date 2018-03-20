#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= k; i++){
        if (n % i != i - 1LL){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}