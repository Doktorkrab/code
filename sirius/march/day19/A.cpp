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

int n, cnt = 0;
const int MAXN = 5e4 + 7;
vector<int> stack;
int ans[MAXN];
inline void init(){
    stack.clear();
    memset(ans, 0, sizeof(int) * MAXN);
    cnt = 0;
}
bool ask(int l, int r){
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    cnt++;
    assert(cnt <= 100000);
    string x;
    cin >> x;
    return x[0] == 'Y';
}
inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        if (stack.empty()){
            stack.push_back(i);
            continue;
        }
        if (ask(stack.back(), i)){
            ans[i] = 1;
            stack.pop_back();
        }
        else 
            stack.push_back(i);
    }
    assert(stack.empty());
    string s = "()";
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << s[ans[i]];
    cout << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    solve();

}
