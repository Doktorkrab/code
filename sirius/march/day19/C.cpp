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
#define x first
#define y second
#define int int64_t

using namespace std;

const int MAXN = 60;
pair<int, int> points[MAXN];

int n, q;

inline void init(){

}
int triangle(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c){
    int x1 = b.first - a.first;
    int y1 = b.second - a.second;
    int x2 = c.first - a.first;
    int y2 = c.second - a.second;
    return abs(x1 * y2 - x2 * y1);
}
int cnt = 0;
bool ask(char type, int i, int j, int k){
    cout << type << " 3 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    //assert(++cnt < 4000);
    if (type == '!')
        return 0;
    string ans;
    cin >> ans;
    return ans[0] == 'Y';
}
inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    int q;
    cin >> q;
    cerr << "here\n";
    while (q > 0){
        int ar = 9e18;
        int a, b, c;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++){
                    bool ret = ask('?', i, j, k);
                    if (ret && triangle(points[i], points[j], points[k]) < ar){
                        ar = triangle(points[i], points[j], points[k]);
                        a = i;
                        b = j;
                        c = k;
                    }
                }
            }
        }
        assert(ar != 1e18);
        cout << "! 3 " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
        --q;
    }
}


int32_t main(){
    cin >> n;
    solve();

}
