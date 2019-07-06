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
#include <chrono>
using namespace std;

int n;

inline void init(){

}
int cnt = 0;
bool query(unsigned int x){
    cout << x << endl;
    assert(++cnt <= 30000);
    string ans;
    cin >> ans;
    if (ans == "yes" && x == 1)
        exit(0);
    return ans == "yes";

}
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
inline void solve(){
   unsigned int x = 0;
   unsigned int kek = 0;
   while (x != 1){
       query(1);
       unsigned nxt = (unsigned) rnd();
       if (query(nxt))
           x = nxt;
   }
}


int main(){
        solve();

}
