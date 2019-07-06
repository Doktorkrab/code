#include <bits/stdc++.h>

using namespace std;


int main(){
    srand(time(0));
    for (int i = 0; i < 2; i++){
        int len = rand() % 100 + 1;
        for (int i = 0; i < len; i++){
            cout << '0' + (rand() % 10);
        }
        cout << '\n';
    }
}