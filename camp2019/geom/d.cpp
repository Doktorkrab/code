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
const int MAXN = 1e5 + 7;
struct Vector{
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}
    Vector () {}

    int dot_product(const Vector& oth) const {
        return x * oth.x + y * oth.y;
    }
    int cross_product(const Vector& oth) const {
        return x * oth.y - y * oth.x;
    }
    Vector operator+(const Vector& oth) const {
        return {x + oth.x, y + oth.y};
    }
    Vector operator-(const Vector& oth) const {
        return {x - oth.x, y - oth.y};
    }
};
Vector polygon[MAXN];
Vector checked;
inline void init(){
    fill(polygon, polygon + MAXN, Vector());
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> polygon[i].x >> polygon[i].y;
    polygon[n] = polygon[0];
    int ans = 0;
    for (int i = 0; i < n; i++){
        Vector upper = polygon[i], down = polygon[i + 1];
        if ((polygon[i] - checked).cross_product(polygon[i + 1] - checked) == 0 && (polygon[i] - checked).dot_product(polygon[i + 1] - checked) < 0){
            cout << "YES\n";
            return;
        }
        if (upper.y == down.y)
            continue;
        if (upper.y < down.y)
            swap(upper, down);
        if (!(upper.y >= checked.y && checked.y > down.y))
            continue;
        ans += (down - upper).cross_product(checked - upper) < 0;
    }
    cerr << ans << '\n';
    cout << (ans & 1 ? "YES\n" : "NO\n");
}


int main(){
	#ifdef LOCAL
		freopen("d.in", "r", stdin);
		freopen("d.out", "w", stdout);
	#else
                freopen("point.in", "r", stdin);
                freopen("point.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> checked.x >> checked.y)
        solve();

}
