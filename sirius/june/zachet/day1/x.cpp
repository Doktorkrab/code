#include <bits/stdc++.h>
/** Begin fast allocation */
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { } // must have!
/** End fast allocation */

using namespace std;


vector<vector<int>> histogramm;
vector<int> cnt;
void update(int v, int old, int nw){
    if (histogramm[v][old] == 1) cnt[v]--;
    histogramm[v][old]--;
    if (histogramm[v][nw] == 0) cnt[v]++;
    histogramm[v][nw]++;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    vector<int> color(n);
    vector<int> big_number(n, -1);
    for (int i = 0;i < n;i++){
        cin >> color[i];
    }
    for (int i = 0;i < m;i++){
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    int k = 2 * ((int) sqrt(m + 0.5));
    vector<int> gg(1e5 + 1);
    for (int v = 0;v < n;v++){
        if (g[v].size() > k){
            big_number[v] = histogramm.size();
            histogramm.push_back(gg);
            cnt.push_back(0);
            for (int u : g[v]){
                if (histogramm[big_number[v]][color[u]] == 0) cnt[big_number[v]]++;
                histogramm[big_number[v]][color[u]]++;
            }
        }
    }
    for (int i = 0; i < q; i++){
        int query;
        cin >> query;
        if (query == 1){
            int v, c;
            cin >> v >> c;
            --v;
            for (int u : g[v]){
                if (big_number[u] != -1) update(big_number[u], color[v], c);
            }
            color[v] = c;
        }
        if (query == 2){
            int v;
            cin >> v;
            --v;
            if (big_number[v] != -1){
                cout << cnt[big_number[v]] << '\n';
            }
            else{
                int cnt = 0;
                for (int u : g[v]){
                    gg[color[u]]++;
                    if (gg[color[u]] == 1) cnt++;
                }
                cout << cnt << '\n';
                for (int u : g[v]){
                    gg[color[u]] = 0;
                }
            }
        }
    }

}