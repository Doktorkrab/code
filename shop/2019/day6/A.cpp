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
#include <random>
#include <chrono>
#define x first
#define y second

using namespace std;
int n;
const int MAXN = 25;
int fld[MAXN * MAXN][MAXN * MAXN];
int rows[MAXN * MAXN][MAXN * MAXN + 1], columns[MAXN * MAXN][MAXN * MAXN + 1], rectangles[MAXN][MAXN][MAXN * MAXN + 1];
vector<pair<int, int>> zeroes;
vector<vector<int>> shuf;
int ans = 0;
int ans_fld[MAXN * MAXN][MAXN * MAXN];
inline void init(){
}
mt19937 rnd(1234567654);
// mt19937 rnd1(rnd() + 239);

bool rec(int pos){
    // cerr << pos << ' ' << zeroes.size() << '\n';
    if (pos == zeroes.size()){
        int tmp = 0;
        for (int i = 0; i < n * n; i++)
            for (int j = 0; j < n * n; j++)
                tmp += fld[i][j] == 0;
                // cout << fld[i][j] << " \n"[j == n * n - 1];
        // return;
        // cerr << tmp << '\n';
        // cerr << tmp << ' ' << ans << '\n';
        if (tmp < ans){
            ans = tmp;
            for (int i = 0; i < n * n; i++)
                for (int j = 0; j < n * n; j++)
                    ans_fld[i][j] = fld[i][j];
        }
        return 1;
        // exit(0);
    }
    int x = zeroes[pos].x, y = zeroes[pos].y;
    // vector<int> kek(n * n);
    // iota(kek.begin(), kek.end(), 1);
    shuffle(shuf[pos].begin(), shuf[pos].end(), rnd);
    // kek.push_back(0);
    // shuffle(kek.begin(), kek.end(), rnd);
    bool good = 0;
    for (int i : shuf[pos]){
        if (i > 0 && (columns[y][i] || rectangles[x / n][y / n][i] || rows[x][i]))
            continue;
        rows[x][i] = 1;
        columns[y][i] = 1;
        rectangles[x / n][y / n][i] = 1;
        fld[x][y] = i;
        good = 1;
        if (rec(pos + 1))
            return 1;
        fld[x][y] = 0;
        rows[x][i] = 0;
        columns[y][i] = 0;
        rectangles[x / n][y / n][i] = 0;
        // break;
    }
    return 0;
}

inline void solve(){
    init();
    for (int i = 0; i < n * n; i++){
        for (int j = 0; j < n * n; j++){
            cin >> fld[i][j];
            rows[i][fld[i][j]] = 1;
            columns[j][fld[i][j]] = 1;
            rectangles[i / n][j / n][fld[i][j]] = 1;
            if (fld[i][j] == 0){
                zeroes.push_back({i, j});
                ans++;
                shuf.push_back(vector<int>(n * n));
                iota(shuf.back().begin(), shuf.back().end(), 1);
                shuf.back().push_back(0);
            }
        }
    }
    // cerr << zeroes.size() << '\n';
    for (int i = 0; i < 5e3; i++){
        for (auto [x, y] : zeroes)
            fld[x][y] = 0;
        for (int i = 0; i < n * n; i++){
            for (int j = 1; j <= n * n; j++){
                columns[i][j] = 0;
                rows[i][j] = 0;
                rectangles[i / n][i % n][j] = 0;
            }
        }
        for (int i = 0; i < n * n; i++){
            for (int j = 0; j < n * n; j++){
                rows[i][fld[i][j]] = 1;
                columns[j][fld[i][j]] = 1;
                rectangles[i / n][j / n][fld[i][j]] = 1;
            }
        }
        sort(zeroes.begin(), zeroes.end());
        rnd = mt19937(rnd());
        shuffle(zeroes.begin(), zeroes.end(), rnd);
        // for (auto [x, y] : zeroes)
        //     cerr << x << ' ' << y << '\n';
        // cerr << '\n';
        rec(0);
        // if (ans == 0)
        //     break;
        // cerr << ans << ' ' << i << '\n';
    }
    for (int i = 0; i < n * n; i++)
        for (int j = 0; j < n * n; j++)
            cout << ans_fld[i][j] << " \n"[j == n * n - 1];
    cerr << zeroes.size() << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}