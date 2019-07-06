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
#define cerr if (false) cerr
using namespace std;
 
 
const int MAXN = 1e3 + 7;
int n;
int arr[MAXN];
vector<int> have_now(MAXN), have_new(MAXN);
inline void init(){
    memset(arr, 0, sizeof(int) * MAXN);
}
int get_ans(){
    int ans = 0;
    int lcp = 0;
    for (int i = 0; i < n; i++){
        have_now[i] = 0;
        have_new[i] = 0; 
    }
    cerr << "lcp: " << lcp << '\n';
    for (int power = 31; power >= 0; power--){
        int was_change = 0;
        for (int i = 0; i < n - 1; i++){
            if (have_now[i] < have_now[i + 1]){
                cerr << "continue on " << i << ' ' << i + 1 << '\n';
                cerr << have_now[i] << ' ' << have_now[i + 1] << '\n'; 
                continue;
            }
            int bit = (arr[i] >> power) & 1;
            int bit1 = (arr[i + 1] >> power) & 1;
            cerr << "arr[i]: " << arr[i] << " " << "bit: " << bit << '\n';
            cerr << "arr[i + 1]: " << arr[i + 1] << " " << "bit1: " << bit1 << '\n';
            cerr << was_change << '\n';
            if (bit < bit1 && was_change)
                return -1;
            if (bit > bit1)
                was_change = 1;
        }
        for (int i = 0; i < n - 1; i++){
            if (have_now[i] < have_now[i + 1]){
                have_new[i] = (have_now[i] << 1) | (((arr[i] >> power) & 1) ^ was_change);
                have_new[i + 1] = (have_now[i + 1] << 1) | (((arr[i + 1] >> power) & 1) ^ was_change);
                continue;
            }
            int bit = ((arr[i] >> power) & 1) ^ was_change;
            if (arr[i] == 0)
                bit = was_change;
            int bit1 = ((arr[i + 1] >> power) & 1) ^ was_change;
            if (arr[i + 1] == 0)
                bit1 = was_change;
            if (bit > bit1)
                return -1;
             
            have_new[i] = (have_now[i] << 1) | bit;
            have_new[i + 1] = (have_now[i + 1] << 1) | bit1;
        }
        cerr << "All good! was_change:" << was_change << '\n';
        if (was_change)
            ans |= (1 << power);
    swap(have_now, have_new);
    }
    return ans;
}
inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << get_ans() << '\n';
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        arr[a - 1] = b;
        cerr << "---------------------------------\n";
        cout << get_ans() << '\n';
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
