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

inline void init(){

}

inline void solve(){
        int l = 1, r = n + 1;
        while (r - l > 1){
            int m = (l + r) / 2;
            cout << m << endl;
            int x;
            cin >> x;
            if (x == 0)
                return;
            if (x == -1)
                r = m;
            else
                l = m;
        }
        cout << l << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
        solve();

}
