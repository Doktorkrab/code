#include <bits/stdc++.h>


using namespace std;


int main(){
    srand(time(0));
    int n = rand() % 10 + 1;
    cout << n << '\n';
    for (int i = 0; i < n; i++){
        cout << hex << uppercase << setfill('0') << setw(2)<< rand() % (CHAR_MAX + 1) << " \n"[i == n - 1];
    }
}