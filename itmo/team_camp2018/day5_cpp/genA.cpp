#include <bits/stdc++.h>


using namespace std;


int main(){
    srand(time(0));
    int n = 10, m = 10;
    cout << n << ' ' << m << '\n';
    for (int i = 0;i < n; i++) cout << rand() % 100 << ' ';
    cout << '\n';
    unordered_set<int> gg[n];
    for (int i = 0; i < m; i++){
        int l = rand() % n;
        int r = rand() % 100;
        while (gg[l].count(r)) l = rand() % n, r = rand() % 100;
        gg[l].insert(r);
        cout << l + 1 << ' ' << r << '\n';
    }
}