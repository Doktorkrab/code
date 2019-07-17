#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    cin >> n;
    int64_t sum = 0;
    for (int i = 1; i <= n; i++)
        sum += n / i;
    cout << sum << '\n';
}