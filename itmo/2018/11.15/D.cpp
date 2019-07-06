#include <bits/stdc++.h>

using namespace std;

long long per(int from, int to, int count) {
    if (from == 1) {
        return 1LL;
    }
    if (count == 1) {
        return 1LL;
    }
    return per(from, 3 ^ from ^ to, count - 1) + 1 + per(3 ^ from ^ to, to, count - 1);
}

int main() {
    freopen("pisa.in", "r", stdin);
    freopen("pisa.out", "w", stdout);
    int n;
    cin >> n;
    cout << per(0, 2, n);
}