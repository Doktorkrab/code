// #define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// #define FMA 3e8
#ifdef FMA
    int alloc_p = 0;
    char alloc[(int) FMA];
    inline void* operator new(size_t n){
        char* res = alloc + alloc_p;
        alloc_p += n;
        assert(alloc_p <= (int) FMA);
        return (void *) res;
    }
    inline void operator delete(void*) noexcept {}
#endif
#define rep(i, n) for (int i = 0; i < (signed long long)n; i++)
#define each(i, v) for (auto i : v)

const int INF = 1e9;
const int MAXLOG = 25;
const int MAXLOG_N = 2e5;
using ll = long long;
const pair<int, int> MAX = {INF, INF};

vector<vector<pair<int, int>>> sparse; // [LOG][N]
vector<vector<int>> g;
vector<int> logs;
vector<int> id;
vector<pair<int, int>> euler;
vector<pair<int, int>> cour;
int n, k;

// -*-*-* All functions *-*-*-


void init(){
    g.assign(n, {});
    logs.assign(MAXLOG_N + 1, 0);
    for (int i = 2; i <= MAXLOG_N; i++){
        logs[i] = logs[i / 2] + 1;
    }
    id.assign(n, -1);
    euler.clear();
}

void precalc(int v, int d, int p = -1){
    id[v] = euler.size();
    euler.push_back({d, v});
    for (int u : g[v]){
        if (u == p) continue;
        precalc(u, d + 1, v);
        euler.push_back({d, v});
    }

}
void build(){
    // cerr << "build\n";
    sparse.assign(MAXLOG, vector<pair<int, int>>(euler.size(), MAX));
    sparse[0] = euler;
    for (int log = 1; log < MAXLOG; log++){
        for (int i = 0; i + (1 << (log - 1)) < (int)(euler.size()); i++){
            sparse[log][i] = min(sparse[log - 1][i], sparse[log - 1][i + (1 << (log - 1))]);
        }
    }
}

pair<int, int> get_min(int l, int r){
    if (l > r) swap(l, r);
    cerr << l << ' ' << r << '\n';
    int len = r - l + 1;
    int power = logs[len];
    return min(sparse[power][l], sparse[power][r - (1 << power) + 1]);
}

pair<int, int> lca(int a, int b){
    cerr << a << ' ' << b << '\n';
    return get_min(id[a], id[b]);
}


int main(){
    freopen("twopaths.in", "r", stdin);
    freopen("twopaths.out", "w", stdout);
    cin >> n >> k;
    init();
    for (int i = 1; i < n; i++){
        int t;
        cin >> t;
        g[t].push_back(i);
    }
    cour.resize(k);
    for (int i = 0; i < k; i++){
        cin >> cour[i].first >> cour[i].second;
        cour[i].first--;
        cour[i].second--;
        cerr << cour[i].first << ' ' << cour[i].second << '\n';
    }
    precalc(0, 0);
    build();
    int ind1 = 0, ind2 = 1, res = 0;
    cerr << '\n';
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            if (i == j)
                continue;
            cerr << cour[i].first << ' ' << cour[i].second << '\n';
            cerr << cour[j].first << ' ' << cour[j].second << '\n';
            auto laa = lca(cour[i].first, cour[i].second);
            auto lbb = lca(cour[j].first, cour[j].second);
            auto lab = max(lca(cour[i].first, cour[j].first), lca(cour[i].first, cour[j].second));
            // cerr << laa.second << ' ' << lbb.second << ' ' << lab.second << '\n';
            if (lab.first < lbb.first || lab.first < laa.first)
                continue;
            auto lab1 = max(lca(cour[i].second, cour[j].first), lca(cour[i].second, cour[j].second));
            // cerr << lab1.second << ' ' << lab1.first << '\n';
            if (lab1.first < lbb.first || lab1.first < laa.first)
                continue;
            auto lkek = lca(lab.second, lab1.second);
            // cerr << lkek.second << '\n';
            // cerr << '\n';
            int tmp = -2 * lkek.first + lab1.first + lab.first;
            if (tmp > res){
                res = tmp;
                ind2 = i;
                ind1 = j;
            }
        }
    }
    cout << res << '\n' << ind1 + 1 << ' ' << ind2 + 1 << '\n';

}