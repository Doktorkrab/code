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
vector<int> arr;
bool cmp(int a, int b){
    cout << "1 " << a << ' ' << b << '\n';
    string ans;
    cin >> ans;
    return ans == "YES";
}
inline void solve(){
    arr.resize(n);
    iota(arr.begin(), arr.end(), 1);
    stable_sort(arr.begin(), arr.end(), cmp);
    cout << "0 ";
    for (int i : arr)
        cout << i << ' ';
    cout << endl;
}


int main(){
    cin >> n;
    solve();
}
