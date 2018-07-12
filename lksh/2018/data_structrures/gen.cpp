#include <bits/stdc++.h>

using namespace std;


int main(){
    srand(time(0));
    int n = 5, m = 5;
    unordered_set<int> was;
    cout << n << ' ' << m << '\n';
    for (int i = 0;i < n; i++) {
        int now = rand() % 10;
        while (was.count(now)) now = rand() % 10;
        was.insert(now);
        cout << now << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; i++){
        int l = rand() % 4, r = rand() % 4;
        if (l > r) swap(l, r);
        cout << l + 1 << ' ' << r + 1 << ' ';
        l = rand() % 10, r = rand() % 10;
        if (l > r) swap(l, r);   
        cout << l << ' ' << r << '\n';
    }
    
}