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

int n;
const int MAXN = 5e3 + 7;
pair<int, int> arrival[2][MAXN]; // 0 - i -> i + 1, 1 - i + 1 -> i
int t[MAXN];
pair<int, int> segments[MAXN];
inline void init(){
    for (int i = 0; i < 2; i++)
        fill(arrival[i], arrival[i] + MAXN, make_pair(1, -1));
    fill(t, t + MAXN, 0);
    fill(segments, segments + MAXN, make_pair(1, -1));
}
pair<int, int> intersect(int l1, int r1, int l2, int r2){
    return {max(l1, l2), min(r1, r2)};
}
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n - 1; i++)
        cin >> segments[i].first >> segments[i].second;
    arrival[0][n - 1] = {0, 1e9 + 7};
    for (int i = 0; i < n - 1; i++)
        arrival[0][i] = {max(0, segments[i].first - t[i]), segments[i].second};
    arrival[1][0] = {0, 1e9 + 7};
    for (int i = 1; i < n; i++)
        arrival[1][i] = {max(0, segments[i - 1].first - t[i]), segments[i - 1].second};
    for (int i = 0; i < n; i++){
        int l = 0, r = 1e9 + 7;
        for (int j = i; j < n - 1; j++){
            int nl, nr;
            tie(nl, nr) = intersect(l, r, arrival[0][j].first, arrival[0][j].second);
            if (nr < nl){
                l = nl, r = nr;
                break;
            }
            l = segments[i].first;
            r = nr;
        }
        for (int j = i; j > 0; --j){
            int nl, nr;
            tie(nl, nr) = intersect(l, r, arrival[1][j].first, arrival[1][j].second);
            l = nl, r = nr;
            if (r < l)
                break;
            l = segments[i - 1].first;
        }
        if (r < l)
            cout << "-1\n";
        else
            cout << l << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
