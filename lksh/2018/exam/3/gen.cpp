#include <bits/stdc++.h>


using namespace std;

int main(){
    srand(time(0));
    int n = rand() % 10;
    int64_t l = rand();
    int64_t r = rand();
    if (l > r) swap(l, r);
    cout << n << ' ' << l << ' ' << r << '\n';
    for (int i = 0; i < n; i++){
        cout << rand() << ' ' << rand() << '\n';
    }
}