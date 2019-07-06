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

const int MAXN = 5e4 + 7;
//#define int int64_t
struct Node{
    int x;
    int add = -1;
};
struct Node1{
    int x;
    int add = -1;
    int right_ones = 0;
    int left_ones = 0;
};
int n, q;
int arr[MAXN];
int prefix[MAXN];
Node st[4 * MAXN];
Node1 st1[4 * MAXN];

void push(int v, int l, int r){
    if (st[v].add == -1)
       return;
    st[v].x += st[v].add * (r - l);
    if (r - l != 1){
        st[2 * v].add = st[v].add;
        st[2 * v + 1].add = st[v].add;
    }
    st[v].add = -1;
}
void pull(int v, int l, int r){
    if (r - l != 1)
        st[v].x = st[2 * v].x + st[2 * v + 1].x;
}
int gt(int v, int l, int r, int L, int R){
    push(v, l, r);
    if (l >= R || L >= r)
        return 0;
    if (L <= l && r <= R)
        return st[v].x;
    int m = (l + r) / 2;
    int ret = gt(v * 2, l, m, L, R) + gt(v * 2 + 1, m, r, L, R);
    pull(v, l, r);
    return ret;
}

void insert_add(int v, int l, int r, int L, int R, int what){
    if (l >= R || L >= r)
        return;
    if (L <= l && r <= R){
        st[v].add = what;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    insert_add(2 * v, l, m, L, R, what);
    insert_add(2 * v + 1, m, r, L, R, what);
    pull(v, l, r);
}

void push1(int v, int l, int r){
    if (st1[v].add == -1)
        return;
    st[v].x += st[v].add * (r - l);
}
pair<int, int> gt1(int v)

inline void init(){

}
int ans(){
    int ret = 0;
//    for (int i = 0; i < n; i++)
//        cerr << arr[i] << " \n"[i == n - 1];
//    for (int i = 0; i < n; i++)
//        cerr << prefix[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++)
        ret += prefix[i] - i;
    return ret;
}
inline void solve(){
    for (int i = 0; i < n; i++){
        char x;
        cin >> x;
        arr[i] = x - '0';
    }
    prefix[n - 1] = (arr[n - 1] == 0 ? n - 1 : n);
    for (int i = n - 2; i >= 0; i--)
        prefix[i] = (arr[i] == 0 ? i : prefix[i + 1]);
    cout << ans() << '\n';
    for (int i = 0; i < q; i++){
        int l, r, c;
        cin >> l >> r >> c;
        --l;
        for (int j = l; j < r; j++)
            arr[j] = c;
        if (c == 1){
            while ((l > 0) && (arr[l - 1] == 1))
                --l;
            while ((r < n) && (arr[r] == 1))
                ++r;
            for (int j = l; j < r; j++)
                prefix[j] = max(prefix[j], r);
        }
        cout << ans() << '\n';
    }
}


int32_t main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
                freopen("lamps.in", "r", stdin);
                freopen("lamps.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> q)
        solve();

}
