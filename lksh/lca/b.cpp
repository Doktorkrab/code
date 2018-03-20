// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (signed long long)n; i++)
#define each(i, v) for (auto i : v)

using ll = long long;
using pii = pair<int, int>;
const int MAXLOG = 30;
const int MAXN = 2e5 + 10;
const int c = 20;
vector<pii> euler;
vector<vector<pii>> sparse;
vector<vector<int>> sons;
vector<int> id;
vector<int> logs(MAXN + c);


void dfs(int v, int d = 0){
    id[v] = euler.size();
    euler.push_back({d, v});
    each(u, sons[v]){
        dfs(u, d + 1);
        euler.push_back({d, v});
    }
}


void build(){
    sparse.assign(MAXLOG + c, vector<pii>(euler.size() + c, {INT_MAX, INT_MAX}));
    rep(i, euler.size()) sparse[0][i] = euler[i];
    for (int log = 1; log <= MAXLOG; log++){
        for (int i = 0; i + (1 << (log - 1)) <= (int) euler.size(); i++){
            sparse[log][i] = min(sparse[log - 1][i], sparse[log - 1][i + (1 << (log - 1))]);
        }
    }
}


int get_min(int a, int b){
    a = id[a];
    b = id[b];
    if (b < a) swap(a, b);
    int len = b - a + 1;
    int power = logs[len];
    pii min_ = min(sparse[power][a], sparse[power][b - (1 << power) + 1]);
    return min_.second;
}


int main(){
    freopen("lca2.in", "r", stdin);
    freopen("lca2.out", "w", stdout);
    int n;
    cin >> n;
    sons.resize(n + 20);
    id.resize(n + 20);
    ll m;
    cin >> m;
    for (int i = 2; i <= MAXN; i++){
        logs[i] = logs[i / 2] + 1;
    }
    for (int i = 1; i < n; i++){
        int tmp;
        cin >> tmp;
        sons[tmp].push_back(i);
    }
    dfs(0);

    build();

    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    ll x, y, z;
    cin >> x >> y >> z;
    int prev = 0;
    rep(i, m){
        prev = get_min((a + prev) % n, b);
        ans += prev;
        a = (x * a + y * b + z) % n;
        b = (x * b + y * a + z) % n;
    }
    cout << ans << '\n';
}