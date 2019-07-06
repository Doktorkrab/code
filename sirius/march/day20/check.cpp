#include <bits/stdc++.h>


using namespace std;


int main(){
    string s;
    cin >> s;
    int tmp = 0;
    int open = 0;
    for (char c : s){
        if (c == '(')
            open++;
        if (c == ')' && open){
            open--;
            tmp++;
        }
    }
    cout << tmp << '\n';
}
