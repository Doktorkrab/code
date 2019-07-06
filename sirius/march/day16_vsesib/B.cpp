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
#define int int64_t
const int MAXN = 500;
int n;
pair<int, int> arr[MAXN];
inline void init(){

}

inline void stupid(){
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    int m;
    arr[n] = {0, 0};
    arr[n + 1] = {0, 0};
    cin >> m;
    while (m--){
        int x, y;
        cin >> x >> y;
        int found = 0;
        for (int i = 0; i < n + 2; i++){
            int tmpx = x % arr[i].first;
            int tmpy = y % arr[i].second;
            for (int j = 0; j < n + 2; j++){
                if (i == j)
                    continue;
                int ttx = 0;
                int tty = 0;
                if (arr[j].first == 0)
                    ttx = tmpx;
                else
                    ttx = tmpx % arr[j].first;
                if (arr[j].second == 0)
                    tty = tmpy;
                else
                    tty = tmpy % arr[j].second;
                for (int k = 0; k < n + 2; k++){
                    if (i == k || j == k)
                        continue;
                    int tttx = 0;
                    int ttty = 0;
                    if (arr[k].first == 0)
                        tttx = ttx;
                    else
                        tttx = ttx % arr[k].first;
                    if (arr[k].second == 0)
                        ttty = tty;
                    else
                        ttty = tty % arr[k].second;
                    if (tttx == 0 && ttty == 0){
                        int cnt = 3 - (i >= n) - (j >= n) - (k >= n);
                        if (cnt != 0){
                            cout << cnt << ' ';
                            if (i < n)
                                cout << i + 1 << ' ';
                            if (j < n)
                                cout << j + 1 << ' ';
                            if (k < n)
                                cout << k + 1 << ' ';
                            cout << '\n';
                            found = 1;
                            break;
                        }
                    }
                }
                if (found)
                    break;
            }
            if (found)
                break;
        }
        if (!found)
            cout << "-1\n";
    }
}


int32_t main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#else
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        stupid();

}
