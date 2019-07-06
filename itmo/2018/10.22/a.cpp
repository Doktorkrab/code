#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
mt19937 rnd((uint64_t) new char);
int64_t rand(int64_t x, int64_t y){ return rnd() % (y - x + 1) + x; }
template<typename t>
t min(t a){
    return a;
}
template<typename t, typename... ts>
t min(const t& a, const ts&... as){
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}
template<typename t>
t max(t a){
    return a;
}
template<typename t, typename... ts>
t max(const t& a, const ts&... as){
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}
void prn(ostream& os){
    os << '\n';
}
void prn(){
    cout << '\n';
}
template<typename t, typename... ts>
void prn(ostream& os, const t& a, const ts&... b){
    os << a << ' ';
    prn(os, b...);
}
template<typename t, typename... ts>
void prn(const t& a, const ts&... b){
    cout << a << ' ';
    prn(cout, b...);
}
#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------
const int MAXN = 150;
int cls[MAXN][MAXN];
int ans[MAXN];
int used[MAXN];
vector<vector<int>> g;

void dfs(int v, int color = 0){
    used[v] = 1;
    ans[v] = color;
    for (int u : g[v]){
        if (used[u]){
            if (1 - ans[u] != ans[v]){
                // for (int i = 0; i < 2; i++) cout << ans[i];
                // cout << '\n';
                // prn(v, u);
                cout << "Impossible\n";
                exit(0);
            }
            continue;
        }
        dfs(u, 1 - color);
    }
}
int32_t main(){
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> dia(m);
    g.resize(m);
    for (int i = 0; i < m; i++){
        cin >> dia[i].first >> dia[i].second;
        dia[i].first--;
        dia[i].second--;
        // if (dia[i].first > dia[i].second) swap(dia[i].first, dia[i].second);
        for (int j = (dia[i].first + 1) % n; j != dia[i].second; j = (j + 1) % n){
            cls[j][i] = 1;
        }
        for (int j = (dia[i].second + 1) % n; j != dia[i].first; j = (j + 1) % n){
            cls[j][i] = 2;
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < i; j++){
            if (cls[dia[i].first][j] != cls[dia[i].second][j] && dia[i].first != dia[j].first && dia[i].second != dia[j].first && dia[i].first != dia[j].second && dia[i].second != dia[j].second){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < m; i++) if (!used[i]) dfs(i);
    for (int j = 0; j < m; j++){
        int i = ans[j];
        if (i) cout << "o";
        else cout << "i";
    }
    cout << '\n';
}
