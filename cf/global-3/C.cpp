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
vector<int> p, id;
vector<pair<int, int>> ans;
inline void init(){
    p.resize(n);
    id.resize(n);
    ans.clear();
}

inline void swap(int i, int j){
    id[p[i]] = j;
    id[p[j]] = i;
    int tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
    ans.emplace_back(i + 1, j + 1);
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        id[p[i]] = i;
    }
    for (int i = 0; i < n; i++){
        int old = id[i];
        if (id[i] == i)
            continue;
        else if (2 * abs(id[i] - i) >= n)
            swap(id[i], i);
        else if (2 * id[i] >= n && 2 * i >= n){
            cerr << "0\n";
            swap(old, 0);
            swap(0, i);
            swap(old, 0);
        }
        else if (2 * abs(n - 1 - i) >= n && 2 * abs(n - 1 - id[i]) >= n){
            // cerr << "1\n";

            swap(old, n - 1);
            swap(n - 1, i);
            swap(old, n - 1);
        }
        else if (2 * id[i] >= n && 2 * abs(n - i - 1) >= n){
            // cerr << "2\n";
            swap(0, old);
            swap(n - 1, i);
            swap(0, n - 1);
            swap(0, old);
            swap(n - 1, i);
        }
        else if (2 * abs(n - 1 - id[i]) >= n && 2 * i >= n){
            // cerr << "3\n";

            swap(0, i);
            swap(n - 1, old);
            swap(0, n - 1);
            swap(n - 1, old);
            swap(0, i);
        }
        else 
            cout << "WUT";

    }
    cout << ans.size() << '\n';
    for (auto& i : ans)
        cout << i.first << ' ' << i.second << '\n';
    for (int&i : p)
        cerr << i << " ";
    cerr << '\n';
}

int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}