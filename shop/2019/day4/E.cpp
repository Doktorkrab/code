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
int n, N;
 
vector<string> arr;
vector<int> pos;
inline void init(){
    N = (1 << n);
    arr.resize(N);
    pos.resize(N);
}
 
inline void solve(){
    init();
 
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        for (int j = 0; j < n; j++)
            if (arr[i][j] == '?'){
                pos[i] = j;
                break;
            }
    }
 
    for (int ch = 0; ch <= 1; ch++){
        set<string> was;
        arr[0][pos[0]] = ch + '0';
        was.insert(arr[0]);
        int good = 1;
 
        for (int i = 1; i < N; i++){
            int change = -1;
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if (j == pos[i])
                    continue;
                if (arr[i][j] != arr[i - 1][j]){
                    cnt++;
                    change = j;
                }
            }
            if (cnt > 1){
                good = 0;
                break;
            }
            if (change == -1)
                arr[i][pos[i]] = !(arr[i - 1][pos[i]] - '0') + '0';
            else
                arr[i][pos[i]] = arr[i - 1][pos[i]];
            if (was.count(arr[i])){
                good = 0;
                break;
            }
            was.insert(arr[i]);
        }
        //     for (auto i : arr)
        //         cout << i << '\n';
        // cout << '\n';
        was.clear();
        was.insert(arr[0]);
        for (int i = 1; i < N; i++){
            int cnt = 0;
            if (was.count(arr[i])){
                good = 0;
                break;
            }
            was.insert(arr[i]);
            for (int j = 0; j < n; j++){
                if (arr[i][j] != arr[i - 1][j])
                    cnt++;
            }
            if (cnt != 1){
                good = 0;
                break;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (arr[0][i] != arr[N - 1][i])
                cnt++;
        }
        if (cnt != 1)
            good = 0;
        if (good){
            cout << "YES\n";
            for (auto i : arr)
                cout << i << '\n';
            return;
        }
    }
    cout << "NO\n";
}
 
 
int main(){
    #ifdef LOCAL
        freopen("E.in", "r", stdin);
        freopen("E.out", "w", stdout);
    #endif
     
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();
 
}