#include <bits/stdc++.h>

using namespace std;

vector<int> diveders;

void factor(int n){
    for (int i = 1; i * i <= n;i++){
        if (n % i == 0){
            diveders.push_back(i);
            if (i != n / i) diveders.push_back(n / i);
        }
    }
    sort(diveders.begin(), diveders.end());
}

int main(){
    int n;
    cin >> n;
    factor(n);
    int ans = 0;
    for (int i = 0;i < diveders.size();i++){
        for (int j = i + 1;j < diveders.size();j++){
            if (diveders[i] * diveders[j] > n) break;
            if (__gcd(diveders[i], diveders[j]) == 1) ans++;
        }
    }
    cout << ans << '\n';
}