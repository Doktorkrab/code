#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> p, sz, arr, sm;
vector<bool> cross;
int n;
using ll = long long;
int find(int a){
    return p[a] == a ? a : (p[a] = find(p[a]));
}
void un(int a, int b){
    a = find(a), b = find(b);
    if (sz[a] > sz[b]) swap(a, b);
    if (a == b) return;
    p[a] = b;
    sz[b] += sz[a];
    sm[b] += sm[a];
}

int main(){
    cin >> n;
    p.resize(n);
    sz.assign(n, 1);
    arr.resize(n);
    sm.resize(n);
    cross.assign(n, 1);
    for (int i = 0;i < n;i++) p[i] = i;
    for (int i = 0;i < n;i++) cin >> arr[i];
    vector<int> p1(n);
    for (int i = 0;i < n;i++) cin >> p1[i], p1[i]--;
    reverse(p1.begin(), p1.end());
    // cout << 0 << '\n';
    vector<ll> ans;
    ll mn = 0;
    for (int i : p1){
        ans.push_back(mn);
        cross[i] = 0;
        sm[i] = arr[i];
        // cout << arr[i] << '\n';
        if (i - 1 >= 0 && !cross[i - 1]) un(find(i), find(i - 1));
        if (i + 1 < n && !cross[i + 1]) un(find(i), find(i + 1));
        // cout << sm[find(i)] << ' ' << i << '\n';
        mn = max(mn, sm[find(i)]);
        // cout << mn << '\n';
    }
    reverse(ans.begin(), ans.end());
    for (ll i : ans) cout << i << '\n';
}