#include <bits/stdc++.h>

using namespace std;

vector<string> ch = {"palindrome?", "change"};
int main(){
    srand(time(0));
    int n = 10;
    string s;
    for (int i = 0; i < n; i++){
        s += 'a' + (rand() % 26);
    }
    cout << s << '\n';
    int m = 50;
    cout << m << '\n';
    while (m--){
        int ch1 = rand() % 2;
        if (!ch1){
            int l = rand() % n;
            int r = rand() % n;
            if (l > r) swap(l, r);
            cout << ch[0] << ' ' << l + 1 << ' ' << r + 1 << '\n';
        }
        else{
            int pos = rand() % n;
            char c = 'a' + (rand() % 26);
            cout << ch[1] << ' ' << pos + 1 << ' ' << c << '\n';
        }
    }
}