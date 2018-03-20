#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> p;
int find(int a){
    return p[a] == a ? a : (p[a] = find(p[a]));
}
bool un(int a, int b){
    a = find(a), b = find(b);
    if (a > b) swap(a, b);
    if (a == b) return 0;
    p[a] = b;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    p.resize(n + 1);
    for (int i = 0;i <= n;i++) p[i] = i;
    vector<int> ans(n);
    for (int i = 0;i < m;i++){
        int l, r, x;
        cin >> l >> r >> x;
        --l,--r,--x;
        while (find(l) <= r){
            l = find(l);
            if (l == x) {
                l++;
                continue;
            }
            ans[l] = x + 1;
            un(l, l + 1);
        }
    }
    for (int i = 0;i < n;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}