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
using namespace std;

int n, m;
const int MAXN = 1e5 + 7;
pair<int, int> arr[MAXN];
int used[MAXN];
inline void init(){

}
bool check(const vector<int>& kek){
    int good = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++){
            int can = 0;
            for (int c : kek){
                if (arr[i].x != arr[j].x && arr[i].x != c && arr[j].x != c)
                    can = 1;
                if (arr[i].x != arr[j].y && arr[i].x != c && arr[j].y != c)
                    can = 1;
                if (arr[i].y != arr[j].x && arr[i].y != c && arr[j].x != c)
                    can = 1;
                if (arr[i].y != arr[j].y && arr[i].y != c && arr[j].y != c)
                    can = 1;
            }
            if (!can)
                good = 0;
        }
    return good;
}
inline void solve(){
    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        arr[i].second--;
    }
    if (m == 2){
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < m; i++){
        if (check({i})){
            cout << "1\n" << i + 1 << '\n';
            return;
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (check({i, j})){
                cout << "2\n" << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
    cout << "3\n 1 2 3\n";
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}
