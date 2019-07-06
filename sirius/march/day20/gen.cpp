#include <bits/stdc++.h>


using namespace std;


int main(){
    mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
    int n = rnd() % 8 + 1;
    for (int i = 0; i < n; i++)
        cout << "()?"[rnd() % 3];
    cout << '\n';
}
