#include <bits/stdc++.h>

using namespace std;


int main(){
    srand(time(0));
    int n = 500, m = 100000;
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; i++){
        cout << (rand() % n) + 1 << ' ' << (rand() % n) + 1 << ' ' << rand() % ((int)1e9) << '\n';
    }
}