#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n;
vector<vector<int>> sparse;
vector<int> logs(5e5);
void build(){
    for (int i = 1; i < 25;i++){
        for (int j = 0; j + (1 << i) <= n;j++){
            sparse[i][j] = __gcd(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
//            cout << i << ' ' << j << ' ' << sparse[i][j] << '\n';
        }
    }
}

int get(int l, int r){
    int len = r - l + 1;
    int power = logs[len];
    return __gcd(sparse[power][l], sparse[power][r - (1 << power) + 1]);
}
int main() {
    cin >> n;
    sparse.assign(25, vector<int>(n, 0));
    for (int i = 0;i < n;i++){
        cin >> sparse[0][i];
    }
    build();
    logs[2] = 1;
    for (int i = 3;i < logs.size();i++) logs[i] = logs[i / 2] + 1;
//    cout << logs[5e5 - 1] << '\n';
    int k;
//    for (int i = 0;i < 25;i++){
//        for (int j = 0; j < n;j++){
//            cout << sparse[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    cin >> k;
    for (int i = 0;i < k;i++){
        int l, r;
        cin >> l >> r;
        cout << get(l - 1, r - 1) << ' ';
    }
    cout << '\n';
    return 0;
}