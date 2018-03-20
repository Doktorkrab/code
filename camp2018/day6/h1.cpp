#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0;i < n;i++)
using namespace std;
vector<long long> p, sz;
#define int long long
int get(int v){
        // cerr << v << p[v] << '\n';
        if (p[v] == v) return v;
        return p[v] = get(p[v]);
    }
void un(int v, int u){
    v = get(v), u = get(u);
    if (v == u) return;
    if(sz[v] > sz[u]) swap(v, u);
    p[v] = u;
    sz[u] += sz[v];
}
struct Edge{
    int v, u;
    long double w;
    bool operator<(Edge& a){
        return tie(w, v, u) < tie(a.w, a.v, a.u);
    }
};
long double len(int x, int y, int x1, int y1){
    return sqrt(1.L * (x - x1) * (x - x1) + 1.L * (y - y1) * (y - y1));
}
signed main(){
    int n;
    cin >> n;
    p.resize(n), sz.resize(n);
    forn(i, n) p[i] = i, sz[i] = 1;
    int air = 1;
    vector<pair<int, int>> coords(n);
    forn(i, n) cin >> coords[i].first;
    forn(i, n) cin >> coords[i].second;
    vector<Edge> edges;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            if (i == j) continue;
            edges.push_back({i, j, len(coords[i].first, coords[i].second, coords[j].first, coords[j].second)});
        }
    }
    sort(edges.begin(), edges.end());
    vector<Edge> ans;
    for (Edge e : edges){
        if (get(e.v) != get(e.u)){
            un(e.v, e.u);
            ans.push_back(e); 
        }
    }
    long double r, a;
    cin >> r >> a;
    long double ans1 = 0, ans2 = a;
    for (Edge e : ans){
        if (r * e.w > a){
            ans2 += a;
            ans1 += r * e.w;
            // air = 0;
        }
        else {
            ans2 += r * e.w;
            ans1 += r * e.w;
        }
    }
    cout.precision(20);
    cout.setf(ios::fixed);
    cout << min(ans1, ans2) << '\n';


}