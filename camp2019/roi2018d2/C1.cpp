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
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FMA 5e8
#ifdef FMA
int alloc_pos = 0;
char alloc[(int) FMA];
void* operator new(size_t n){
    char *res = alloc + alloc_pos;
    alloc_pos += n;
    assert(alloc_pos <= (int) FMA);
    return (void *)res;
}
void operator delete(void*) noexcept {}
#endif
const int MAXN = 4e5 + 7;
int n, p;
int arr[MAXN];
inline void init(){

}

inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    assert(p == 1);
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> lft, rgt;
    for (int i = 0; i < n; i++)
        rgt.insert({arr[i] + i, i});
    for (int i = 0; i < n; i++){
        int kek = 0;
        rgt.erase({arr[i] + i, i});
        // cerr << i << ' ' << arr[i] + i << ' ' << arr[i] + (n - i - 1) << '\n';
        // cerr << "?" << rgt.order_of_key({arr[i] + i, -1}) << ' ' << lft.order_of_key({arr[i] + (n - i - 1), -1}) << '\n';
        // for (auto i : lft)
        //     cerr << "("<<i.first << ", " << i.second << ") ";
        // cerr << '\n';
        // for (auto i : rgt)
        //     cerr << "("<<i.first << ", " << i.second << ") ";
        // cerr << "\n\n";
        kek = rgt.order_of_key({arr[i] + i, -1}) + lft.order_of_key({arr[i] + (n - i - 1), -1});
        cout << kek + 1 << '\n';
        lft.insert({arr[i] + (n - i - 1), i});
    }
}


int main(){
	#ifdef LOCAL
		freopen("C1.in", "r", stdin);
		freopen("C1.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> p)
        solve();

}