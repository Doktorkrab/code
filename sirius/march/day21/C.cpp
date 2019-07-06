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

int n, k;

inline void init(){

}
mt19937 rnd('u' + 'r' + 'a' + 'l' + 'o' + 'x');
inline void solve(){
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    shuffle(arr.begin(), arr.end(), rnd);
    partial_sort(arr.begin(), arr.begin() + k,arr.end(), [&](int a, int b){
            if (a == b)
                return false;
            cout << "? " << a << ' ' << b << '\n';
            string ans;
            cin >> ans;
            return ans == "<";
            });
    cout << "! ";
    for (int i = 0; i < k; i++)
        cout << arr[i] << ' ';
    cout << endl;
}


int main(){
    cin >> n >> k;
        solve();

}
