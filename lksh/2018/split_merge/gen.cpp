#include <bits/stdc++.h>

using namespace std;



int main(){
    srand(time(0));
    int n = 5;
    cout << n << '\n';
    set<pair<int, int>> was;
    for (int i = 0; i < n; i++){
        int x = rand() % 20 - 10, y = rand() % 20 - 10;
        while (was.count({x, y})) x = rand() % 20 - 10, y = rand() % 20 - 10;
        was.insert({x, y});
        cout << x << ' ' << y << '\n';
    }

}