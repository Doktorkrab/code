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
int zeroes = 0;
int ones = 0;
const int MAXN = 2e5 + 7;
int arr[MAXN];
inline void init(){
    zeroes = ones = 0;
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] == 0)
            zeroes++;
        else
            ones++;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == 0)
            zeroes--;
        else
            ones--;
        if (ones == 0 || zeroes == 0){
            cout << i + 1 << '\n'; 
            break;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
