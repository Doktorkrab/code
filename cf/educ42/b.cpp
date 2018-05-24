#include <bits/stdc++.h>

using namespace std;
int n, a, b;
int ans = 0, len = 0;

void check(){
    if (!len) return;
    int len_1 = len / 2;
    if (len % 2 == 0){
        ans += min(len_1, a) + min(len_1, b);
        a -= min(len_1, a);
        b -= min(len_1, b);
    }
    else{
        ans += min(len_1 +(a >= b), a) + min(len_1 + (a < b), b);
        bool gg = (a >= b);
        a -= min(len_1 + gg, a);
        b -= min(len_1 + !gg, b);
    }
    len = 0;
}
int main(){

    cin >> n >> a >> b;

    for (int i = 0;i < n;i++){
        char tmp;
        cin >> tmp;
        if (tmp == '.'){
            len++;
        }
        else{
            check();
        }
    }
    check();
    cout << ans << '\n';
}