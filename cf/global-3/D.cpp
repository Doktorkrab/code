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
struct Pair
{
    int a, b, ind;
};
vector<Pair> a, b;
inline void init(){
    a.clear(), b.clear();
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        Pair gg;
        cin >> gg.a >> gg.b;
        gg.ind = i + 1;
        if (gg.a < gg.b)
            a.push_back(gg);
        else
            b.push_back(gg);
    }
    auto cmp1 = [](const Pair& a, const Pair& b){ return a.b < b.b;};
    auto cmp = [](const Pair& a, const Pair& b){ return a.b > b.b;};
    if (a.size() < b.size()){
        swap(a, b);
        sort(a.begin(), a.end(), cmp1);
    }
    else
        sort(a.begin(), a.end(), cmp);
    cout << a.size() << '\n';
    for (int i = 0; i < a.size(); i++)
        cout << a[i].ind << ' ';
    cout << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}