#include <bits/stdc++.h>
using namespace std;

vector<int> p, sz;
using ll = long long;
vector<ll> sm;
int find(int a){
    return p[a] == a ? a : (p[a] = find(p[a]));
}
void un(int a, int b, ll c){
    a = find(a), b = find(b);
    if (sz[a] > sz[b]) swap(a, b);
    sm[b] += c;
    if (a == b) return;
    p[a] = b;
    sz[b] += sz[a];
    sm[b] += sm[a];
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    p.assign(n, 0);
    sz.assign(n, 1);
    sm.resize(n);
    for(int i = 0;i < n;i++) p[i] = i;
    for (int i = 0;i < m;i++){
        int c;
        cin >> c;
        if (c == 1){
            int a, b;
            ll c;
            cin >> a >> b >> c;
            un(a - 1, b - 1, c);
        }
        else{
            int a;
            cin >> a;
            cout << sm[find(a - 1)] << '\n';
        }
    }
}