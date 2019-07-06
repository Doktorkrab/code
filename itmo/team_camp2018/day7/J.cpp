#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>
using namespace std;


#define  MAX_N (int)1e6+3
int a[MAX_N], b[MAX_N], aPos[MAX_N], bPos[MAX_N];
int n;
int ans[MAX_N];


int main() {
    scanf("%d", &n);
    fill(ans, ans + n, (int)1e9);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        aPos[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        bPos[b[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; i * j <= n; j++){
            int tmp = aPos[i] - bPos[j];
            if (tmp < 0) tmp += n;
            ans[tmp] = min(ans[tmp], i * j);
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    return 0;
}