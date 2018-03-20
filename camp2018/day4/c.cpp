#include <bits/stdc++.h>
using namespace std;

const int MAXLOG = 25;
const int MAXN = 1e5;
using ll = long long;
int n, m;
vector<vector<ll>> sparse;
vector<int> logs(MAXN);
void build(){
    for(int log = 1;log < MAXLOG;log++){
        for (int i = 0; i + (1 << (log - 1)) < n;i++){
            sparse[log][i] = min(sparse[log - 1][i], sparse[log - 1][i + (1 << (log - 1))]);
        }
    }
}
int get(int l, int r){
    if (r < l) swap(l, r);
    int len = r - l + 1;
    int power = logs[len];
    return min(sparse[power][l], sparse[power][r - (1 << power) + 1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> m;
    sparse.assign(MAXLOG, vector<ll>(n, INT_MAX));
    cin >> sparse[0][0];
       for (int i = 1; i < n; i++) {
        sparse[0][i] = (23 * sparse[0][i - 1] + 21563) % 16714589;
    }
    build();
    logs[2] = 1;
    for (int i = 3;i < MAXN;i++) logs[i] = logs[i / 2] + 1;
    int v, u;
    cin >> u >> v;
    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans = get(v - 1, u - 1);
        //cout << ans << ' ';
        u = ((17 * u + 751 + ans + 2 * (i + 1)) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * (i + 1)) % n) + 1;
        //cout << v << ' ' << u <<'\n';
    }
    cout << u << ' ' << v << ' ' << get(u - 1, v - 1) << '\n';
}