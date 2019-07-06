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
#define FMA 2.53e8
#ifdef FMA
    int alloc_pos = 0;
    char alloc[(int)FMA];
    void* operator new (size_t n){
        char *res = alloc + alloc_pos;
        alloc_pos += n;
        assert(alloc_pos <= (int) FMA);
        return (void*) res;
    }
    void operator delete( void*) noexcept {}
#endif
using namespace std;

const int MAXN = 1.5e5 + 7;
int n, m;
multiset<int> dists[2][MAXN];
pair<int, int> gg[1507];
inline void init(){
    for (int i = 0; i < MAXN; i++){
        dists[0][i].clear();
        dists[1][i].clear();
    }
}
inline int dist(int x, int y, int x1, int y1){
    return (x - x1) * (x - x1) + (y - y1) * (y - y1); 
}
inline void solve(){
    //init();
    for (int i = 0; i < m; i++){
        char x;
        cin >> x;
        if (x == 'E'){
            int pos = 0;
            int y = 0;
            int dst = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < 2; j++){
                    if (!dists[j][i].size())
                        continue;
                    int kk = *(dists[j][i].begin());
                    if (dst < kk){
                        dst = kk;
                        pos = i;
                        y = j;
                    }
                }
            cout << pos + 1 << ' ' << y + 1 << '\n';
            gg[i] = {pos, y};
            for (int i = 0; i < n; i++)
                for (int j = 0; j < 2; j++)
                    dists[j][i].insert(dist(pos, y, i, j));
        }
        else {
            int y;
            cin >> y;
            --y;
            auto hh = gg[y];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < 2; j++)
                    dists[j][i].erase(dists[j][i].find(dist(i, j, hh.first, hh.second)));
        }
    }
}


int main(){
	#ifdef LOCAL
		freopen("B_45.in", "r", stdin);
		freopen("B_45.out", "w", stdout);
	#else
                freopen("tram.in", "r", stdin);
                freopen("tram.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
