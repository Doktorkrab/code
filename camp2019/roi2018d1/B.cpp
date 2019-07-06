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

const int MAXN = 5e2 + 7;
int n, p;
int a[MAXN][MAXN];
int pos[MAXN][MAXN];
inline void init(){

}

inline void solve(){
    vector<int> ans;
    for (int i = 0; i < n; i++){
        int kek;
        cin >> kek;
        --kek;
        a[i][0] = kek;
        pos[i][kek] = 0;
        if (kek == i)
            ans.push_back(i + 1);
        for (int j = 1; j < n; j++){
            cin >> kek;
            --kek;
            a[i][j] = kek;
            pos[i][kek] = j;
        }
    }
    cin >> p;
    if (p == 1){
        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    set<int> gg;
    for (int i = 0; i < n; i++){
        vector<int> killed(n);
        int j = n - 1;
        int cnt = 0;
        cerr << i << '\n';
        while (j >= 0 && a[i][j] > pos[i][i]){
            for (int kk = 0; kk < j; kk++){
                int k = a[i][kk];
                if (!killed[k] && pos[k][k] > pos[k][a[i][j]]){
                    killed[k] = 1;
                    cnt++;
                }
                // cerr << k << ' ' << kk << '\n';
            }
            if (killed[a[i][j]])
                cnt--;
            --j;
        }
        // cerr << "!" << i << ' ' << j << '\n';
        for (; j >= 0; --j){
            if (killed[a[i][j]])
                cnt--;
            for (int kk = 0; kk < j; kk++){
                int k = a[i][kk];
                if (!killed[k] && pos[k][k] > pos[k][a[i][j]]){
                    killed[k] = 1;
                    cnt++;
                }
            }
            // cerr << "?" << a[i][j] << ' ' << cnt << ' ' << j << '\n';
            if (cnt == j)
                gg.insert(a[i][j] + 1);
          
        }
    }
    cout << gg.size() << '\n';
    for (int i : gg)
        cout << i << ' ';
    cout << '\n';

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