#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<vector<ll>>> fenwick;
ll n;
void add(ll x, ll y, ll z, ll w){
    for(;x < n;x = x | (x + 1))
        for (int y1 = y;y1 < n;y1 |=y1 + 1)
            for (int z1 = z;z1 < n;z1 |= z1 + 1)
                fenwick[x][y1][z1] += w;
}
ll sum(ll x, ll y, ll z){
    ll ans = 0;
    for (;x >= 0;x = (x & (x + 1)) - 1)
        for (int y1 = y;y1 >= 0; y1 = (y1 & (y1 + 1)) - 1)
            for (int z1 = z;z1 >= 0;z1 = (z1 & (z1 + 1)) - 1)
                ans += fenwick[x][y1][z1];
    return ans;
}

signed main(){
    int n;
    cin >> n;
    fenwick.assign(n, vector<vector<ll>>(n, vector<ll>(n)));
    int m;
    do{
        cin >> m;
        if (m == 2){
            int x, y, z, x1, y1, z1;
            cin >>  x >> y >> z >> x1 >> y1 >> z1;
            cout << sum(x1, y1, z1) + sum(x - 1, y - 1, z - 1) - (sum(x1, y1, z - 1) + sum(x1, y - 1, z1) + sum(x - 1, y1, z1)) + sum(x - 1, y - 1, z1) + sum(x - 1, y1, z - 1) + sum(x1, y - 1, z - 1) << '\n';
        }
        if (m == 1){
            int x, y, z, w;
            cin >> x >> y >> z;
            cin >> w;
            add(x, y, z, w);
        }
    } while(m != 3);
}
