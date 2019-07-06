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
int cnt = 0;
int n, y, l;
int ask(int x){
    cout << "? " << x << endl;
    assert(++cnt <= 90);
    int ret;
    cin >> ret;
    return ret;
}
void bs1(int l1, int r){
    while (r - l1 > 1){
        int m = (l1 + r) / 2;
        int tmp = ask(m);
        if (m == tmp)
            l1 = m;
        else
            r = m;
    }
    cerr << l << ' ' << r << '\n';
    y = r;
    l = ask(y) - y;
}
inline void solve(){
    int a = ask((int64_t)1e18);
    if (a == 1){
        n = ask((int64_t) 1e18 - 1);
        bs1(1, n + 1);
        cout << "! " << n << ' ' << y << ' ' << l << endl;
        return;
    }
    else {
        int b = ask((int64_t) 1e18 + 1 - a);
        if (b == 1){
            n = ask((int64_t) 1e18 - a);
            bs1(1, n + 1);
            cout << "! " << n << ' ' << y << ' ' << l << endl;
            return;
        }
        else {
            cerr << "enter binsearch\n";
            int l1 = (int) 1e18 + 1 - a;
            int r = (int) 1e18 - 1;
            while (r - l1 > 1){
                int m = (l1 + r) / 2;
                if (ask(m) >= b)
                    l1 = m;
                else
                    r = m;
            }
            n = ask(l1);
            cerr << "n is " << n << '\n';
            bs1(1, a);
            cout << "! " << n << ' ' << y << ' ' << l << endl;
        }
    }

}


int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //while (cin >> n)
        solve();

}
