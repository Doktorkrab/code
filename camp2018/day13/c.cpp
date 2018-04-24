#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int MAX_MEM = 3e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { }
int main(){
    string FN = "prediction";
    freopen((FN + ".in").c_str(), "r", stdin);
    freopen((FN + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k1;
    cin >> n >> k1;
    vector<vector<int>> arr1(k1 + 1, vector<int>(n));
    vector<int> mx(n, 1), arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
         arr1[arr[i]][i] = 1;
    }
    int ans = n;
    for (int l = 2;l <= n;l++){
        for (int i = 0;i + l - 1 < n;i++){
            arr1[arr[i + l - 1]][i]++;
            mx[i] = max(mx[i], arr1[arr[i + l - 1]][i]);
            if (mx[i] > l / 2) ans++;
        }
    }
    cout << ans << '\n';
}