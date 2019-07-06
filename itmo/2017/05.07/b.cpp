#include <bits/stdc++.h>

using namespace std;
vector<int> arr, broken;
int n, m;
int check(int i){
    // cout << i << ' ' << (i != 0 && arr[i - 1] > arr[i]) << ' ' << (i != n - 1 && arr[i + 1] < arr[i]) << '\n';
    return (broken[i] = (i != 0 && arr[i - 1] > arr[i]) || (i != n - 1 && arr[i + 1] < arr[i]));   

}
int main(){
    freopen("army.in", "r", stdin);
    freopen("army.out", "w", stdout);
    cin >> n >> m;
    int broken_cnt = 0;
    arr.resize(n), broken.resize(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
        // broken_cnt += check(i);
    }
    for (int i = 0; i < n;i++){
        broken_cnt += check(i);
    }
    for (int q = 0;q < m;q++){
        char c;
        cin >> c;
        if (c == '!'){
            int i, x;
            cin >> i >> x;
            --i;
            arr[i] = x;
            if (broken[i]) broken_cnt -= 1 - check(i);
            else broken_cnt += check(i);
            if (i != 0 && broken[i - 1]) broken_cnt -= 1 - check(i - 1);
            else if (i != 0) broken_cnt += check(i - 1);
            if (i != n - 1 && broken[i + 1]) broken_cnt -= 1 - check(i + 1);
            else if(i != n - 1) broken_cnt += check(i + 1);
        }
        else{
            // cout << broken_cnt << '\n';
            cout << (broken_cnt ? "NO\n" : "YES\n");
        }
    }
}