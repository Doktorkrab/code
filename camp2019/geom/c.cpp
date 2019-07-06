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

using namespace std;
struct Vector{
    int x, y;
    Vector() {}
};
struct Line{
    int a, b, c;
    Line () {}
    int get_sign(Vector& oth) const {
        int tmp = a * oth.x + b * oth.y + c;
        if (tmp == 0)
            return 0;
        if (tmp > 0)
            return 1;
        return -1;
    }
};
int n, m, r;
const int MAXN = 1e5 + 7;
vector<int> tmp;
Vector points[MAXN];
Line lines[MAXN];
inline void init(){
    fill(points, points + MAXN, Vector());
    cerr << m << '\n';
    tmp.resize(m);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    for (int i = 0; i < m; i++)
        cin >> lines[i].a >> lines[i].b >> lines[i].c;
    set<vector<int>> kek;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            tmp[j] = lines[j].get_sign(points[i]);
        if (kek.count(tmp)){
            cout << "YES\n";
            return;
        }
        kek.insert(tmp);
    }
    cout << "NO\n";
}


int main(){
	#ifdef LOCAL
		freopen("c.in", "r", stdin);
		freopen("c.out", "w", stdout);
	#else
                freopen("candles.in", "r", stdin);
                freopen("candles.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> r)
        solve();

}
