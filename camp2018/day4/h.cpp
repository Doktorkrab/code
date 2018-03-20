#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> p, sz;
vector<bool> cross;
int n;
int find(int a){
    return p[a] == a ? a : (p[a] = find(p[a]));
}
void un(int a, int b){
    a = find(a), b = find(b);
    if (sz[a] > sz[b]) swap(a, b);
    if (a == b) return;
    p[a] = b;
    sz[b] += sz[a];
    n--;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    p.resize(n), sz.assign(n, 1);
    for (int i = 0;i < n;i++) p[i] = i;
    if (n == 1){
        cout << "0\n";
        return 0;
    }
    for (int i = 0;i < m;i++){
        int v, u;
        cin >> v >> u;
        --v;--u;
        un(v, u);
        if (n == 1){
            cout << i + 1 << '\n';
            return 0;
        }
    }
}