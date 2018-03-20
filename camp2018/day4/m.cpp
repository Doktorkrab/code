#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> p, sz;
vector<bool> cross;
int find(int a){
    return p[a] == a ? a : (p[a] = find(p[a]));
}
void un(int a, int b){
    a = find(a), b = find(b);
    // if (sz[a] > sz[b]) swap(a, b);
    if (a == b) return;
    p[a] = b;
    // sz[b] += sz[a];
}
vector<ll> value, now;

void add(int pos, int how){
    pos = find(pos);
    while (now[pos] + how > value[pos]){
        // cerr << pos << ' ' <<value[pos] << ' ' << now[pos] << ' ' << '\n';
        how -= value[pos] - now[pos];
        now[pos] = value[pos];
        un(pos, pos + 1);
        pos = find(pos);
    }
    now[pos] += how;
}
int main(){
    int n;
    cin >> n;
    value.resize(n + 1), now.resize(n + 1);
    for (int i = 0;i < n;i++) cin >> value[i];
    value[n] = LONG_LONG_MAX;
    p.resize(n + 1);
    for (int i = 0;i <= n;i++ ) p[i] = i;
    sz.assign(n + 1, 1);
    int m;
    cin >>m;
    for (int i = 0;i < m;i++){
        int q;
        cin >> q;
        if (q == 1){
            int ind, how;
            cin >> ind >> how;
            add(ind - 1, how);
        }
        else{
            int ind;
            cin >> ind;
            cout << now[ind - 1] << '\n';
        }
    }
}