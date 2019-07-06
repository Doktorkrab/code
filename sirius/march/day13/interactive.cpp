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
using namespace std;


const int MAXN = 3e3 + 7;
int n;
int arr[MAXN];
int arr1[MAXN];
int kek[MAXN][MAXN];
int cnt = 0;
inline void init(){
    cnt = 0;
    memset(arr, 0, sizeof(int) * MAXN);
}
int query_arr(int l, int r){
    unordered_set<int> kek;
    for (int i = l; i < r; i++)
        kek.insert(arr[i]);
    return kek.size();
}

int query_men(int l, int r){
    assert(cnt < 36000);
    assert(l < r);
    // cout << "? " << l << ' ' << r << '\n';
    unordered_set<int> kek;
    for (int i = l; i < r; i++)
        kek.insert(arr1[i]);
    return kek.size();
}
inline void solve(){
    init();
    arr[0] = 1;
    int nxt = 2;
    kek[0][1] = 1;
    if (n != 1 && query_men(0, 2) == 2){
        arr[1] = 2;
        nxt++;
        kek[0][2] = 2;
        kek[1][2] = 1;
    }
    else{
        arr[1] = 1;
        kek[0][2] = 1;
    }
    for (int i = 2; i < n; i++){
        int l = -1, r = i;
        while (r - l > 1){
            int m = (l + r) / 2;
            // cerr << m << "!\n";
            // cerr << m << ' ' << l << ' ' << r << "\n";
            int tmp = query_men(m, i + 1);
            if (kek[m][i] < tmp)
                r = m;
            else
                l = m;
        }
        // cerr << l << ' ' << r << '\n';

        if (l != -1){
            arr[i] = arr[l];
        }
        else
            arr[i] = nxt++;
        int was = 0;
        for (int j = i - 1; j >= 0; j--){
            if (arr[j] == arr[i])
                was = 1;
            kek[j][i + 1] = kek[j][i] + !was;
        }
        kek[i][i + 1] = 1;
    }
    // cout << "Ready!" << endl;
    // cout << kek[0][n] << endl;
    // for (int i = 0;i < n; i++){
    //     cout << arr[i];
    //     if (i != n - 1)
    //         cout << ' ';
    // }
    // cout << endl;
    cout.flush();
}



int main(){
    // #ifdef LOCAL
    //  freopen("B.in", "r", stdin);
    //  freopen("B.out", "w", stdout);
    // #endif
    
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    // while (cin >> n)
    mt19937 rnd(time(0));
    while (1){
        n = rnd() % 20 + 1;
        cerr << "here\n";
        int k = rnd() % 2 + 1;
        for (int i = 0; i < n; i++)
            arr1[i] = rnd() % k + 1;
        map<int, vector<int>> gg;
        for (int i = 0; i < n; i++)
            gg[arr1[i]].push_back(i);
        k = gg.size();
        set<vector<int>> kekos;
        for (auto i : gg)
            kekos.insert(i.second);
        solve();
        if (query_arr(0, n) != k){
            cout << "ERROR!\n";
            for (int i = 0; i < n; i++)
                cout << arr1[i] << " \n"[i == n - 1];
            return 1;
        }
        map<int, vector<int>> hh;
        for (int i = 0; i < n; i++)
            hh[arr[i]].push_back(i);
        set<vector<int>> kikos;
        for (auto i : hh)
            kikos.insert(i.second);
        if (kikos != kekos){
            cout << "ERROR!\n";
            for (int i = 0; i < n; i++)
                cout << arr1[i] << " \n"[i == n - 1];
            return 1;
        }
    }

}