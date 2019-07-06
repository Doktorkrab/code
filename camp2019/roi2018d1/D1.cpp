#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <climits>
using namespace std;

const int MAXN = 31;
int n, m, k;
int d[MAXN];
int p[MAXN];
pair<int, int> pos[MAXN];
int used[MAXN];
inline void init(){
    for (int i = 0; i < MAXN; i++)
        d[i] = INT_MAX;
    memset(p, -1, sizeof(int) * MAXN);
}
bool cmp(const vector<int>& a, const vector<int>& b){
    for (int i = 2 * MAXN - 1; i >= 0; --i)
        if (a[i] != b[i])
            return a[i] < b[i];
    return 0;
}
inline void solve(){
    init();
    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        --x, --y;
        pos[i] = {x, y};
    }
    int nxt = 0;
    d[0] = 0;
    p[0] = -1;
    for (int gg = 0; gg < k; gg++){
        int now = -1;
        for (int i = 0; i < k; i++){
            if (!used[i] && (now == -1 || d[i] < d[now]))
                now = i;
        }
        if (now == -1)
            break;
        used[now] = 1;
        // cerr << now << '\n';
        // for (int j = 2 * MAXN - 1; j >= 0; --j)
        //     cerr << d[now][j] << " \n"[j == 0];
        // cerr << '\n';
        for (int i = 0; i < k; i++){
            int pw = 1 << (max(abs(pos[i].first - pos[now].first), abs(pos[i].second - pos[now].second)));
            if (d[i] > d[now] + pw){
                d[i] = d[now] + pw;
                nxt = i;
                p[i] = now;
            }
        }
        if (nxt == now)
            break;
    }
    // for (int i = 0; i < k; i++){
    //     cerr << i << ": ";
    //     for (int j = 2 * MAXN - 1; j >= 0; --j)
    //         cerr << d[i][j] << " \n"[j == 0];
    //     cerr << '\n';
    // }
    vector<int> ans;
    int now = k - 1;
    while (now != -1){
        ans.push_back(now + 1);
        now = p[now];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}


int main(){
    #ifdef LOCAL
        freopen("D.in", "r", stdin);
        freopen("D.out", "w", stdout);
    #endif
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> k)
        solve();

}