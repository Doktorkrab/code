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
int n, r, c;
const int MAXN = 1e2 + 5;
int row[MAXN], column[MAXN];
int fld[MAXN][MAXN];
inline void init(){

}
inline void paint(int i, int j){
    fld[i][j] = 1;

    // cerr <<i << ' ' << j << '\n';
    column[j]++;
    row[i]++;
    }
inline void solve(){
    while (n > 0){
        // cerr << n << '\n';
        int x = -1, y = -1;
        int mx = row[0], ind = 0;
        int mx1 = column[0], ind1 = 0;
        for (int i = 0; i < r; i++)
            if (mx < row[i]){
                mx = row[i];
                ind = i;
            }
        for (int i = 0; i < c; i++)
            if (mx1 < column[i]){
                mx = column[i];
                ind1 = i;
            }
        // cerr << mx << ' ' << mx1 << " " << c << " " << r << "!\n";
        if (mx == c && mx1 == r){
            // cerr << "here\n";
            bool good = 0;
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++)
                    if (!fld[i][j]){
                        paint(i, j);
                        good = 1;
                        break;
                    }
                if (good)
                    break;
            }
        } else if (mx == c || (mx > mx1 && mx1 != r)){
            // cerr << "here!!\n";
            if (!fld[ind][ind1]){
                paint(ind, ind1);
            }
            else {
                for (int i = 0; i < r; i++){
                    // cerr << i << ' ' << ind1 << ' ' << fld[i][ind1] << '\n';
                    if (!fld[i][ind1]){
                        paint(i, ind1);
                        break;
                    }
                }
            }
        }
        else {
            // cerr << "here\n";
            if (!fld[ind][ind1]){
                paint(ind, ind1);
            }
            else {
                for (int i = 0; i < c; i++){
                    if (!fld[ind][i]){
                        paint(ind, i);
                        break;
                    }
                }
            }
        }
        --n;
    }
    int mx = 0;
    int mx1 = 0;
    for (int i = 0; i < r; i++)
        mx = max(mx, row[i]);
    for (int i = 0; i < c; i++)
        mx1 = max(mx1, column[i]);
    cout << min(mx, mx1) << '\n';
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (fld[i][j])
                cout << '#';
            else
                cout << ".";
        }
        cout << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >>r >> c)
        solve();

}